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

mutex shared ;
condition_variable condvar ;
queue<int> msgQueue;
int result = 0 ;


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
