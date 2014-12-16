#ifndef _SFL_LOCK_H_
#define _SFL_LOCK_H_

#include "head.h"

class LockBase
{
    public:
        LockBase(void){}
        virtual ~LockBase(void){}
        virtual void lock(void) = 0;
        virtual void unlock(void) = 0;
};

class Locker
{
    public:
        Locker(LockBase *lock)
        {
            assert(lock != NULL);
            _lock = lock;
            _lock->lock();
        }
        ~Locker()
        {
            if (_lock)
            {
                _lock->unlock();
                _lock = NULL;
            }
        }

        void unlock()
        {
            if (_lock)
            {
                _lock->unlock();
                _lock = NULL;
            }
        }
    private:
        LockBase *_lock;
};

class NullLock : public LockBase
{
    public:
        NullLock(void){}
        virtual ~NullLock(void){}
        int init(void) const
        {
            return 0;
        }

        virtual void lock(void) {}
        virtual void unlock(void) {}

};

class MutexLock : public LockBase
{
    public:
        MutexLock(void)
        {
        }

        ~MutexLock(void)
        {
            pthread_mutex_destroy(&_lock);
        }

        int init()
        {
            pthread_mutex_init(&_lock, NULL);
            return 0;
        }

        virtual void lock(void)
        {

            pthread_mutex_lock(&_lock);
        }

        virtual void unlock(void)
        {

            pthread_mutex_unlock(&_lock);
        }

        pthread_mutex_t* get_mutex(){
            return &_lock;
        };
    private:
        pthread_mutex_t _lock;
};

class SpinLock : public LockBase
{
    public:
        SpinLock(void)
        {
            _lock = NULL;
        }

        ~SpinLock(void)
        {
            if (_lock)
            {
                pthread_spin_destroy(_lock);
                delete _lock;
                _lock = NULL;
            }
        }

        int init(void)
        {
            assert(_lock == NULL);
            _lock = new pthread_spinlock_t;
            assert(_lock);

retry:
            int rv = pthread_spin_init(_lock, PTHREAD_PROCESS_PRIVATE);
            if (rv == -1)
            {
                if (EAGAIN == errno)
                {
                    goto retry;
                }

                return -1;
            }

            return 0;
        }

        virtual void lock(void)
        {
            assert(_lock);

            pthread_spin_lock(_lock);
        }

        virtual void unlock(void)
        {
            assert(_lock);

            pthread_spin_unlock(_lock);
        }


    private:
        pthread_spinlock_t *_lock;
};


template<class T>
class  ScopeLock
{
    public:
        ScopeLock(T& t):lock(t){
            lock.lock(); 
        }
        ~ScopeLock(){
            lock.unlock(); 
        }
    protected:
        T&   lock;
};







#endif /* _SFL_LOCK_H_ */
