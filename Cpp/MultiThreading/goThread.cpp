// writeUnlockreadUnlock// How to make a multiple-read/single-write lock
// https://www.jyt0532.com/2017/01/02/c++-multi-thread-p4-2/
#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <functional>   // bind(...)
#include <chrono>
#include <future>
#include <queue>
using namespace std ;

class cRWLock{
    public:
    cRWLock( ) ;
        bool noWriter( ) ;
        bool noAccessor( ) ;
        void readLock( ) ;
        void readUnlock( ) ;
        void writeLock( ) ;
        void writeUnlock( ) ;

//******************************************************
//        void producer(int owner, int start, int end)   ;
//        void consumer( int owner, int demand) ;
        condition_variable    condvar ;
        queue<int>            msgQueue ;

    private:
        mutex                 mShared ;
        condition_variable    mReaderQ ;
        condition_variable    mWriterQ ;
        int                   mActiveReaders ;
        int                   mWaitingWriters ;
        int                   mActiveWriters ;
//        std::condition_variable    condvar ;
//        std::queue<int>                   msgQueue ;
} ;

mutex shared ;
condition_variable condvar ;
queue<int> msgQueue;

cRWLock::cRWLock( ): mShared( ), mReaderQ( ), mWriterQ( ){
    mActiveReaders = 0 ;
    mWaitingWriters = 0 ;
    mActiveWriters = 0 ;
}

bool cRWLock::noWriter( ){
    return mActiveReaders > 0 || mActiveWriters == 0;
}

bool cRWLock::noAccessor( ){
    return mActiveReaders == 0 && mActiveWriters == 0;
}

void cRWLock::readLock( ){
    unique_lock<std::mutex> lk(mShared);
    mReaderQ.wait(lk, bind(&cRWLock::noWriter, this)) ;
    ++mActiveReaders;
    lk.unlock( ) ;
}


void cRWLock::readUnlock( ){
    unique_lock<mutex> lk(mShared);
    --mActiveReaders;
    lk.unlock();
    mWriterQ.notify_one();
}


void cRWLock::writeLock( ){
    unique_lock<mutex> lk(mShared);
    ++mWaitingWriters;
    mWriterQ.wait(lk, bind(&cRWLock::noAccessor, this));
    --mWaitingWriters;
    ++mActiveWriters;
    lk.unlock();
}


void cRWLock::writeUnlock( ){
    unique_lock<std::mutex> lk(mShared);
    --mActiveWriters;
    if(mWaitingWriters > 0)
        mWriterQ.notify_one();
    else
        mReaderQ.notify_all();
    lk.unlock();
}

void producer(int owner, int start, int end){
    for (int x = start; x < end; x++){
        this_thread::sleep_for(chrono::milliseconds(200)) ;
        {
            lock_guard<mutex> guard(shared) ;
            msgQueue.push( x ) ;
        }
        printf("    Producer : %d  -->  %2d \n",owner,  x) ;
        condvar.notify_all( ) ;
    }
}

void consumer( int owner, int demand){
    while (true){
        unique_lock<mutex> ulock(shared) ;
        condvar.wait(ulock,  [ ] { return msgQueue.size( ) > 0 ; } ) ;
        // wait的第二個引數使得顯式的double check不再必要
        printf("Consumer %d :  < --  %2d\n", owner, msgQueue.front( ) ) ;
        msgQueue.pop( ) ;
        --demand ;
        if  (  demand <= 0 )  break ;
    }
}

int result = 0 ;

void func(cRWLock &rw, int i){
    if(i % 2 == 0){
        rw.writeLock();
        result += 1;
        rw.writeUnlock();
        rw.readLock();
        rw.readUnlock();
    }else{
        rw.readLock();
        rw.readUnlock();
        rw.writeLock();
        result += 2;
        rw.writeUnlock();
    }
}

void not_safe(int i){
    if(i%2 == 0){
        result += 1;
    }else{
        result += 2;
    }
}

int main( ){
    cRWLock rw ;
    vector<thread> threads ;
    for(int i = 0; i < 1000; i++){
        threads.push_back(std::thread(func, ref(rw), i));
        //threads.push_back(std::thread(not_safe, i));
    }
    for(int i = 0; i < threads.size() ; i++){
        threads[i].join();
    }
    cout << result << endl;
    return 0;
}
