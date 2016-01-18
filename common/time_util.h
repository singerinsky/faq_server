#ifndef TIME_UTIL_H_
#define TIME_UTIL_H_

#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

enum { SECONDS_QUARTER_HOUR = 900, SECONDS_HALF_HOUR = 1800, SECONDS_OF_HOUR = 3600, };
enum { SECONDS_OF_DAY = 24 * 3600, SECONDS_OF_WEEK = SECONDS_OF_DAY * 7, };  // 每天的秒数
enum { LOCAL_TIME_ZONE = 8 * 3600 }; // 本地时区

extern long timezone;  // 本地时区偏移


//CPU's timestamp counter.
inline uint64_t rdtsc()
{
    uint32_t low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return (uint64_t) high << 32 | low;
}

// millisecond
inline int64_t time_ms()
{
    struct timeval tv = {0} ;
    gettimeofday(&tv,NULL) ;
    return tv.tv_sec * 1000 + tv.tv_usec/1000 ;

}



// microsecond by gettimeofday
inline int64_t time_us()
{
    struct timeval tv = {0} ;
    gettimeofday(&tv,NULL) ;
    return tv.tv_sec * 1000000 + tv.tv_usec ;

}

// microsecond by clock , require librt
inline int64_t clock_us()
{
    struct timespec tv = {0} ;
    clock_gettime(CLOCK_MONOTONIC,&tv) ;
    return tv.tv_sec * 1000000 + tv.tv_nsec/1000 ;
}

// get tick counter per microsecond , may block 100 milliseconds
inline int64_t get_tsc_us()
{
    int64_t begin_tsc = rdtsc() ;
    int64_t begin_us = time_us() ;
    int64_t tsc_interval = 0 ;
    int64_t us_interval = 0 ;
    do
    {
        usleep(100000) ;
        tsc_interval = rdtsc() - begin_tsc  ;
        us_interval = time_us() - begin_us ;

    } while(us_interval < 1 ); //cliff : || us_interval  (100000 << 3) ) ;

    return tsc_interval/us_interval ;
}

inline time_t str2time(const char* buf,const char* fmt)
{
    struct tm tmp_tm = {0} ;

    if ( strptime(buf,fmt,&tmp_tm) == NULL ) return 0 ;
    return mktime(&tmp_tm) ;
}

inline int time2str(char* buf,int maxlen ,const char* fmt,time_t t)
{
    struct tm tmp_tm;
    localtime_r(&t,&tmp_tm) ;
    return strftime(buf,maxlen,fmt,&tmp_tm) ;
}

// 获取当天已经逝去的秒数
inline time_t get_seconds_elapsed_of_the_day(time_t cur_time = 0, int day_seconds = SECONDS_OF_DAY)
{
	time_t  zero_time ;
	if (cur_time == 0)
	{
		time(&cur_time);
	}
	
	struct tm  tmp_tm_time;
	localtime_r(&cur_time,&tmp_tm_time);
	tmp_tm_time.tm_hour = 0;
	tmp_tm_time.tm_min = 0;
	tmp_tm_time.tm_sec = 0;

	zero_time = mktime(&tmp_tm_time);

	return (cur_time - zero_time) % day_seconds ;
}

// 获取当前的tm时间
inline struct tm* get_current_tm_time(struct tm*  user_tm_time)
{
	time_t  cur_t;
	time(&cur_t);

	return localtime_r(&cur_t, user_tm_time);
}

// 判断两个日期是否是同一天
inline bool is_same_day(struct tm* first_tm, struct tm* second_tm)
{
	return (first_tm->tm_year == second_tm->tm_year
		&& first_tm->tm_mon == second_tm->tm_mon
		&& first_tm->tm_mday == second_tm->tm_mday);
}

inline void init_timezone()
{
	time_t  now;
	time(&now);

	struct tm local_time;
	localtime_r(&now, &local_time);

	// fprintf(stderr, "local time zone is %ld", timezone);
	// now extern long timezone is set to -28800
}

// 第三个参数可以设置，方便调试
// should init_timezone() first
inline bool is_same_day(time_t first_t, time_t second_t, int default_day_seconds = SECONDS_OF_DAY)
{
	if (timezone == 0)
	{
		init_timezone();
	}
	return (first_t - timezone) / default_day_seconds == (second_t - timezone )/ default_day_seconds;
}

struct SimpleTime
{
	int hour;
	int min;
	int sec;
};

inline int seconds_diff(const SimpleTime& start, const SimpleTime& end)
{
    int seconds_diff = (end.hour * SECONDS_OF_HOUR + end.min * 60 + end.sec)
        - (start.hour * SECONDS_OF_HOUR + start.min * 60 + start.sec);

    return seconds_diff;
}

inline struct tm* convert_from_simple_time(const SimpleTime& a, struct tm* tm_time)
{
	tm_time->tm_hour = a.hour;
	tm_time->tm_min = a.min;
	tm_time->tm_sec = a.sec;
	return tm_time;
}

inline SimpleTime* convert_from_tm(const struct tm& tm_time, SimpleTime* a)
{
	a->hour = tm_time.tm_hour;
	a->min = tm_time.tm_min;
	a->sec = tm_time.tm_sec;
	return a;
}

inline int time_cmp(const SimpleTime& a, const SimpleTime& b)
{
	if (a.hour > b.hour)      return 1;
	else if (a.hour < b.hour) return -1;
	else
	{
		if (a.min > b.min)       return 1;
		else if (a.min < b.min)  return -1;
		else
		{
			if (a.sec > b.sec)      return 1;
			else if (a.sec < b.sec) return -1;
			else                    return 0;
		}
	}
}

// 仅比较时分秒
inline int time_cmp(struct tm time_a, int hour, int min, int sec)
{
	SimpleTime a, b;
	a.hour = time_a.tm_hour;
	a.min = time_a.tm_min;
	a.sec = time_a.tm_sec;

	b.hour = hour;
	b.min = min;
	b.sec = sec;

	return time_cmp(a, b);
}

// 距最近的指定时间还剩多少秒
// hour [0-23] min[0-59] sec[0-59]
inline int32_t seconds_to_nearest_time(int hour, int min, int sec)
{
	struct tm  now;
	get_current_tm_time(&now);

	int32_t  sec_needs = 0;
	int cmp = time_cmp(now, hour, min, sec) ;
	if (cmp > 0) // 当前时间大于指定的时间
	{
		sec_needs = SECONDS_OF_DAY - get_seconds_elapsed_of_the_day();
		sec_needs += hour * 3600 + min * 60 + sec;
		return sec_needs;
	}
	else if (cmp == 0)
	{
		return 0;
	}
	else // 当前时间小于指定时间
	{
		sec_needs = (hour - now.tm_hour) * 3600 + (min - now.tm_min) * 60 - now.tm_sec + sec ;
		return sec_needs;
	}
}

// 获取当天已经逝去的秒数
inline time_t get_seconds_elapsed_of_the_week(time_t now_sec = 0)
{
	if (now_sec == 0)
	{
		time(&now_sec);
	}

	struct tm  now_tm_time;
	localtime_r(&now_sec, &now_tm_time);

	return now_tm_time.tm_wday * SECONDS_OF_DAY + get_seconds_elapsed_of_the_day(now_sec);
}

// 计算距离某time_t时间 到 现在 是第几天
// time_t 所在的天 是第一天
inline int get_passed_days_since(time_t  last_time = 0, int default_day_seconds = SECONDS_OF_DAY)
{
	if (last_time < 0) return INT_MAX;
	
	time_t now = time(NULL);
	if (last_time > now) return 0;
	else if (last_time == now) return 1;

	bool need_add_one_more_day = false;
	if (last_time == 0) 
	{
		need_add_one_more_day = ((now % default_day_seconds) > 0 );

		return (now / default_day_seconds) + (need_add_one_more_day ? 1 : 0);
	}
	else
	{
		time_t first_day_left_seconds = default_day_seconds - get_seconds_elapsed_of_the_day(last_time, default_day_seconds);
		
		if (now - last_time < first_day_left_seconds) return 1; // 还是第一天
		
		need_add_one_more_day = ((now - last_time - first_day_left_seconds) % default_day_seconds) > 0;

		return (now - last_time - first_day_left_seconds) / default_day_seconds + 1 + (need_add_one_more_day ? 1 : 0);
	}
}

// 计算距离某time_t时间 到 某天 是第几天
// time_t 所在的天 是第一天
inline int get_passed_days_between(time_t  last_time,time_t end_time, int default_day_seconds = SECONDS_OF_DAY)
{
	if (last_time < 0) return INT_MAX;

	if (last_time > end_time) return 0;
	else if (last_time == end_time) return 1;

	bool need_add_one_more_day = false;
	if (last_time == 0)
	{
		need_add_one_more_day = ((end_time % default_day_seconds) > 0 );

		return (end_time / default_day_seconds) + (need_add_one_more_day ? 1 : 0);
	}
	else
	{
		time_t first_day_left_seconds = default_day_seconds - get_seconds_elapsed_of_the_day(last_time, default_day_seconds);

		if (end_time - last_time < first_day_left_seconds) return 1; // 还是第一天

		need_add_one_more_day = ((end_time - last_time - first_day_left_seconds) % default_day_seconds) > 0;

		return (end_time - last_time - first_day_left_seconds) / default_day_seconds + 1 + (need_add_one_more_day ? 1 : 0);
	}
}

// 是否为同一周，默认周日为一周的第一天
inline bool is_same_week(time_t first_t, time_t second_t)
{
	if (first_t == 0 || second_t == 0)
	{
		return false;
	}

	if (abs(first_t - second_t) > SECONDS_OF_WEEK)
	{
		return false;
	}

	if (is_same_day(first_t, second_t))
	{
		return true;
	}

	// 以first为基准
	// 本周已经逝去的时间
	int  elapsed_secs_of_week = get_seconds_elapsed_of_the_week(first_t);

	// 本周还剩的时间
	int  left_secs_of_week = SECONDS_OF_WEEK - elapsed_secs_of_week;

	if (second_t < first_t)
	{
		if (first_t - second_t > elapsed_secs_of_week)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (second_t - first_t > left_secs_of_week)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}



#endif /* TIME_UTIL_H_ */
