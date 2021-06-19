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
#include <fstream>
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
        printf("Producer : %d  -->  %2d \n",owner,  x) ;
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

void func(cRWLock &rw,int i){
    if(i % 2 == 0){
        rw.writeLock();
        result ++;
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
class ThreadWriter{
public:
    ThreadWriter(const string& path): path(path){
        this->ofile.open(path);
    }
    void write(const string& dataToWrite){
        lock_guard<mutex> lock(this->writerMutex);
        this->ofile << dataToWrite;
    }
private:
    string path;
    ofstream ofile;
    mutex writerMutex;
};

class Writer{
public:
    Writer(shared_ptr<ThreadWriter> sf): sf(sf){};
    void writeToFile(){
        // cout << "is this working?" << endl;
        this->sf->write("logging...\n");
    }
private:
    shared_ptr<ThreadWriter> sf;
};
int main(){
    auto ofile = make_shared<ThreadWriter>("./testLogging1.txt");
    Writer writer1(ofile);
    Writer writer2(ofile);
    cRWLock rw ;
    vector<thread> threads ;
    for(int i = 0; i < 100000000; i++){
        // threads.push_back(thread(func, ref(rw), i));
        // threads.push_back(thread(not_safe, i));
        writer1.writeToFile();
        writer2.writeToFile();
    }
    for(int i = 0; i < threads.size() ; i++){
        threads[i].join();
    }
    cout << result << endl;
    return 0;
}