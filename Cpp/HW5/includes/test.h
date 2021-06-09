#ifndef TEST_H
#define TEST_H
// #pragma Once
#include <iostream>
#include <sstream>
#include <Game.h>
#include <vector>
using namespace std;

class TestRun{
    private:
        Game test;
        vector<istringstream> iss;
    public:
        TestRun(){
            // this->test = Game();
            // find all combinations on grid
            this->testGame();
        }
        ~TestRun(){}
        void testGame();
        
    // friend class Game;
};

#endif