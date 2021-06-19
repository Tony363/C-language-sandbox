#ifndef CRWLOCK_H
#define CRWLOCK_H
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
using namespace std;

class cRWLock{
    public:
        cRWLock( ){};
        cRWLock(int mActiveReaders,int mWaitingWriters,int mActiveWriters): 
            mActiveReaders(mActiveReaders),
            mWaitingWriters(mWaitingWriters),
            mActiveWriters(mActiveWriters){};
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
//      condition_variable    condvar ;
//      queue<int>                   msgQueue ;
} ;

#endif