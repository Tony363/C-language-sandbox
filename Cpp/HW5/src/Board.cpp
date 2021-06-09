// #pragma Once
#include <iostream>
#include <Board.h>
using namespace std;

Board::Board(){
    char boardcpy[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    memcpy(this->board,boardcpy,sizeof(this->board));
}
bool Board::checkWin(char c){
    for (auto cond : this->winningCondition){
        if (this->board[cond[0][0]][cond[0][1]] == c 
        && this->board[cond[1][0]][cond[1][1]] == c
        && this->board[cond[2][0]][cond[2][1]] == c){
            return true;
        }
    }
    return false;
}
void Board::printBoard(){
    for (int i=0;i<3;i++){
        printf("[");
        for (int j=0;j<3;j++){
            printf("%c",this->board[i][j]);
        }
        printf("]\n");
    }
}