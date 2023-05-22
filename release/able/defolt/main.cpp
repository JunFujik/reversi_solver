#include "prot.hpp"
#include "func.cpp"
#include "debug.hpp"

int main(){
    vest Board(8);  //盤面
    for(int i = 0; i < 8; i++) std::cin >> Board[i];

    std::vector<inin> Opp(0);   //相手の石の位置
    int Opp_num=0;   //Oppの要素数

    //相手のマスを確認
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(Board[i][j] == '@'){
                Opp.push_back( {i, j} );
                Opp_num++;
            }
        }
    }

    //Oppをもとに確かめる
    std::vector<ininin> Neb(0);  //ルール的に置けるマス 座標,座標,方角
    std::vector<ininin> Temp(0); 

    //相手の駒の周りを確かめつつ、その列を見て置けるか判断する
    for(int i = 0; i < Opp_num; i++){
        Temp = round(Board, Opp[i]);    //(0.空 1.自分 2.相手, 自分のマスか空のマスまたは端っこが来るまでの数)

        for(int i = 0; i < Temp.size(); i++){
            Neb.push_back( {Temp[i]} );
        }
    }

    int mx = 0;
        inin mxc;

    for(int i = 0; i < Neb.size(); i++){
        mx = std::max(mx, Neb[i].c);
        if(mx == Neb[i].c){
            mxc = {Neb[i].a, Neb[i].b};
        }
    }

    std::cout << mxc.a+1 << ' ' << mxc.b+1 << std::endl;
}