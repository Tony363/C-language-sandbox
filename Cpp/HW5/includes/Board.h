#ifndef BOARD_H
#define BOARD_H
// #pragma Once
#include <iostream>
#include <cstdio>
#include <cstring>

class Board{
    private:
        char board[3][3];
        const int winningCondition[8][3][2] = {
            {{0,0},{0,1},{0,2}},
            {{1,0},{1,1},{1,2}}, 
            {{2,0},{2,1},{2,2}},

            {{0,0},{1,0},{2,0}},
            {{0,1},{1,1},{2,1}},
            {{0,2},{1,2},{2,2}},

            {{0,0},{1,1},{2,2}},
            {{0,2},{1,1},{2,0}}
        };
    public:
        Board();
        ~Board(){}
        void setMove(char p,int h,int w){this->board[h][w] = p;};
        inline bool checkBoard(int h,int w){return this->board[h][w] == ' ';};
        bool checkWin(char c);
        void printBoard();
};
#endif