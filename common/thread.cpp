/*
 * thread.cpp
 *
 *  Created on: 2012-2-22
 *      Author: gl
 */

#include "thread.h"

    void * _ThreadEntry(void *pParam){
        thread* pThread = (thread*)pParam;
        if(pThread->init_instance()){
            pThread->run();
        }

        pThread->exit_instance();
        return NULL;

    }

    thread::thread() {
        m_hThread = 0;
        pthread_mutex_init(&m_mutex,NULL);
        pthread_cond_init(&m_cond,NULL);
    }

    thread::~thread() {
        // TODO Auto-generated destructor stub
    }

    bool thread::create(){
        bool ret = true;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        ret = (::pthread_create(&m_hThread,&attr,&_ThreadEntry,this)==0);
        return ret;
    }

    bool thread::init_instance(){
        return true;
    }

    void thread::exit_instance(){
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_cond);
    }


    void thread::os_sleep(timespec sleep_time)
    {
    	thread_resume(&sleep_time);
    }


    THREAD_HANDLE thread::get_current_handle()
    {
        return ::pthread_self();
    }

    void thread::thread_resume(timespec *time_wait){
        pthread_mutex_lock(&m_mutex);
        timespec tm;
        timeval now;
        if(time_wait == NULL){
            gettimeofday(&now,NULL);
            tm.tv_sec = now.tv_sec + 60*60*24*365;
            tm.tv_nsec = now.tv_usec + 0;	
            time_wait = &tm;
        }
        pthread_cond_timedwait(&m_cond,&m_mutex,time_wait);
        pthread_mutex_unlock(&m_mutex);
    }

    void thread::thread_suspend(){
        pthread_mutex_lock(&m_mutex);
        pthread_cond_signal(&m_cond);
        pthread_mutex_unlock(&m_mutex);
    }

    









