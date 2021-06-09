// #pragma Once
#include <iostream>
#include <Game.h>
#include <Board.h>
#include <test.h>
#include <vector>
using namespace std;

Game::Game():Board(),TestRun(){
    this->setP1();
    this->setP2();
    this->test = false;
}

void Game::run(){
    int flip = 0;
    while (this->playerMoveHistory.size()<9){
        this->setPmove(this->players[flip]);
        this->printBoard();
        if (this->checkWin(get<1>(this->players[flip]))){
            cout << get<0>(this->players[flip]) << " won!" << endl;
            this->printPlayerMoveHistory();
            return;
        }
        flip = 1 - flip;
    }
    cout << "draw" << endl;
    this->printPlayerMoveHistory();
}
void Game::setP1(){
    cout << "Please Enter P1 Name & character:\n" << endl;
    cin >> get<0>(this->players[0]) >> get<1>(this->players[0]);
}
void Game::setP2(){
    cout << "Please Enter P1 Name & character:\n" << endl;
    cin >> get<0>(this->players[1]) >> get<1>(this->players[1]);
}
// void Game::setTestInput(vector testInputs){
//     memcpy(this->iss,testInputs,sizeof(testInputs));
//     cin.rdbuf(this->iss[0].rdbuf());
// }

void Game::setPmove(tuple<string,char> p){
    if (this->test && !cin.eof()){
        if (cin.fail()){
            cin.clear();
            string dummy;
            cin >> dummy;
            return ;
        }
        cin >> this->h >> this->w;
    }else{
        this->PlayerInput();
    }
    
    if (this->checkBoard(this->h,this->w)){
        this->playerMoveHistory.push_back( make_tuple(this->h,this->w,get<0>(p)));
        this->setMove(get<1>(p),this->h,this->w);
        return;
    }else{
        cout << "Coordinate space [" 
            << h << "] [" 
            << w << "] filled"
            << endl;
    }
    return this->setPmove(p);
}  
void Game::PlayerInput(){
    cout << "Please Enter move coordinate [3x3]\n" << endl;
    cin >> this->h >> this->w;
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