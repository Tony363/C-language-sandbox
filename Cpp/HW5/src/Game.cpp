#pragma Once
#include <iostream>
#include <Game.h>
#include <Board.h>
#include <vector>
using namespace std;

Game::Game():Board(){
    this->setP1();
    this->setP2();
    this->test = false;
    this->cinbuf = nullptr;
}
Game::Game(bool test,istringstream& line):Board(){
    this->test=test;
    this->cinbuf = cin.rdbuf();
    cin.rdbuf(line.rdbuf());
    this->setP1();
    this->setP2();
}
void Game::run(){
    int flip = 0;
    while (this->playerMoveHistory.size()<9){
        this->inputPmove(this->players[flip]);
        this->printBoard();
        if (this->checkWin(get<1>(this->players[flip]))){
            cout << get<0>(this->players[flip]) << " WON!\n" << endl;
            this->printPlayerMoveHistory();
            return;
        }
        flip = 1 - flip;
    }
    cout << "----DRAW----" << endl;
    this->printPlayerMoveHistory();
}
void Game::setP1(){
    if (this->test){
        cin >> get<0>(this->players[0]) >> get<1>(this->players[0]);
    }else {
        cout << "Please Enter P1 Name & character:\n" << endl;
        cin >> get<0>(this->players[0]) >> get<1>(this->players[0]);
    }
}
void Game::setP2(){
    if (this->test){
        cin >> get<0>(this->players[1]) >> get<1>(this->players[1]);
    }else{
        cout << "Please Enter P1 Name & character:\n" << endl;
        cin >> get<0>(this->players[1]) >> get<1>(this->players[1]);
    }
}
void Game::inputPmove(tuple<string,char> p){
    if (this->test){
        cin >> this->h >> this->w;
    }else{
        cout << "Please Enter move coordinate [3x3]\n" << endl;
        cin >> this->h >> this->w;
    }
    
    if (this->checkBoard(this->h,this->w)){
        this->playerMoveHistory.push_back( make_tuple(this->h,this->w,get<0>(p)));
        this->setMove(get<1>(p),this->h,this->w);
        return;
    }else {
        cout << "Coordinate space [" 
            << h << "] [" 
            << w << "] filled"
            << endl;
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