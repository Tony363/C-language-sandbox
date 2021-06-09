#ifndef GAME_H
#define GAME_H
#pragma Once
#include <iostream>
#include <Board.h>
#include <vector>
#include <tuple>
#include <sstream>
using namespace std;

class Game:public Board{
    private:
        bool test;
        int h,w,totalMoveCount;
        tuple<string,char>players[2];
        vector<tuple<int,int,string>> playerMoveHistory;
        streambuf* cinbuf;
    public: 
        Game();
        Game(bool test, istringstream& line);
        ~Game(){}
        void inputPmove(tuple<string,char> p);
        void setP1();
        void setP2();
        void printPlayerMoveHistory();
        void run();
};
#endif