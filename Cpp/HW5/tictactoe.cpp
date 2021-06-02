// #pragma Once
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstring>
using namespace std;

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
        Board(){
            char boardcpy[3][3] = {
                {' ',' ',' '},
                {' ',' ',' '},
                {' ',' ',' '}
            };
            memcpy(this->board,boardcpy,sizeof(this->board));
        }
        ~Board(){}
        void setMove(char p,int h,int w){this->board[h][w] = p;};
        bool checkBoard(int h,int w);
        bool checkWin(char c);
        void printBoard();
};
bool Board::checkBoard(int h,int w){
    if (this->board[h][w] == ' '){
        return true;
    }
    cout << "Coordinate space [" 
            << h << "] [" 
            << w << "] filled"
            << endl;
    return false;
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

class Game:public Board{
    private:
        int h,w,totalMoveCount;
        tuple<string,char>players[2];
        vector<tuple<int,int,string>> playerMoveHistory;
    public: 
        Game():Board(){
            this->setP1();
            this->setP2();
        }
        ~Game(){}
        void inputPmove(tuple<string,char> p);
        void setP1();
        void setP2();
        void printPlayerMoveHistory();
        void run();
};
void Game::run(){
    int flip = 0;
    while (this->playerMoveHistory.size()<9){
        this->inputPmove(this->players[flip]);
        this->printBoard();
        if (this->checkWin(get<1>(this->players[flip]))){
            cout << get<0>(this->players[flip]) << " won!" << endl;
            return;
        }
        flip = 1 - flip;
    }
    this->printBoard();
    cout << "draw" << endl;
}
void Game::setP1(){
    cout << "Please Enter P1 Name & character:\n" << endl;
    cin >> get<0>(this->players[0]) >> get<1>(this->players[0]);
}
void Game::setP2(){
    cout << "Please Enter P1 Name & character:\n" << endl;
    cin >> get<0>(this->players[1]) >> get<1>(this->players[1]);
}
void Game::inputPmove(tuple<string,char> p){
    cout << "Please Enter move coordinate [3x3]\n" << endl;
    cin >> this->h >> this->w;
    if (this->checkBoard(this->h,this->w)){
        this->playerMoveHistory.push_back( make_tuple(this->h,this->w,get<0>(p)));
        this->setMove(get<1>(p),this->h,this->w);
        return;
    }
    return this->inputPmove(p);
}  
void Game::printPlayerMoveHistory(){
    for (auto move:this->playerMoveHistory){
        cout << get<2>(move) << ":\n\t"
            << "Coordinates: ["
            << get<0>(move) << ","
            << get<1>(move) << "]"
            << endl;
    }
}

int main(void){
    Game one;
    one.run();
    return 0;
}