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
#include <cRWLock.h>
using namespace std;

bool cRWLock::noWriter( ){
    return mActiveReaders > 0 || mActiveWriters == 0;
}

bool cRWLock::noAccessor( ){
    return mActiveReaders == 0 && mActiveWriters == 0;
}

void cRWLock::readLock( ){
    unique_lock<mutex> lk(mShared);
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
    unique_lock<mutex> lk(mShared);
    --mActiveWriters;
    if(mWaitingWriters > 0)
        mWriterQ.notify_one();
    else
        mReaderQ.notify_all();
    lk.unlock();
}
