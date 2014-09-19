/*
 * thread.h
 *
 *  Created on: 2012-2-22
 *      Author: gl
 */

#ifndef CTHREAD_H_
#define CTHREAD_H_

#include <pthread.h>
#include "head.h"

typedef pthread_t THREAD_HANDLE;

class thread {
public:
	thread();
	virtual ~thread();
	virtual bool create();
	virtual void run()=0;
	virtual bool init_instance();
	virtual void exit_instance();
	THREAD_HANDLE	get_handle()
	{
		return m_hThread;
	}

	void os_sleep(timespec);

	static THREAD_HANDLE get_current_handle();

	void thread_resume(struct timespec *time=NULL);

	void thread_suspend();

    void thread_lock();
    void thread_unlock();


private:

	THREAD_HANDLE m_hThread;

public:
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;


};


#endif /* CTHREAD_H_ */
