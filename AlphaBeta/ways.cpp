#ifndef WAYS_CPP
#define WAYS_CPP

#include "prot.hpp"
#include "func.cpp"
#include "debug.hpp"



void Change_turn(std::vector<std::string> &VBoard, std::vector<std::vector<int>> &Vweight){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Vweight[i][j] *= -1;
            if (VBoard[i][j] == '#'){
                VBoard[i][j] = '@';
            }
            else if(VBoard[i][j] == '@'){
                VBoard[i][j] = '#';
            }
        }
    }
}



//n手読み
void expect(std::vector<std::string> Board, std::vector<inin> Able, std::vector<std::vector<int>> Vweight, std::vector<std::vector<int>> Score){
    std::vector<std::string> VBoard(8);

    for(int i = 0; i < Able.size(); i++){
        VBoard = put({Able[i].a, Able[i].b}, Board);
        Change_turn(VBoard, Vweight);
        std::vector<inin> Able = select(Board, weight, Score);
    }
}


#endif