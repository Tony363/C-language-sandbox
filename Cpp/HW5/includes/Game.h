#ifndef GAME_H
#define GAME_H
// #pragma Once
#include <iostream>
#include <Board.h>
#include <test.h>
#include <vector>
#include <tuple>
#include <test.h>
#include <sstream>
using namespace std;

class Game:public Board,public TestRun{
    private:
        bool test;
        int h,w,totalMoveCount;
        tuple<string,char>players[2];
        vector<tuple<int,int,string>> playerMoveHistory;
        // vector<istringstream> iss;
    public: 
        Game();
        ~Game(){}
        void setTestBool(bool test){this->test=test;}
        // void setTestInput(vector iss);
        void setPmove(tuple<string,char> p);
        void setP1();
        void setP2();
        void printPlayerMoveHistory();
        void run();
        void PlayerInput();
        void PlayerInput(int w,int h);
    // friend class TestGame;
};
#endif