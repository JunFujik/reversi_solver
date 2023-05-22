#include "prot.hpp"
#include "func.cpp"
#include "ways.cpp"
#include "debug.hpp"

int main(){
    std::vector<std::string> Board(8);  //盤面, 変更用盤面
    for(int i = 0; i < 8; i++) std::cin >> Board[i];


    std::vector<std::vector<int>> Score(8, std::vector<int>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Score[i][j]=NEGA_INF;
        }
    }

    std::vector<inin> Able = select(Board, weight, Score);

    int mx = NEGA_INF;
    inin mxc;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            mx = std::max(mx, Score[i][j]);
            if(mx == Score[i][j]){
                mxc = {i, j};
            }
        }
    }



    put({mxc.a, mxc.b}, Board);

    std::cout << mxc.a+1 << ' ' << mxc.b+1 << std::endl;
}

