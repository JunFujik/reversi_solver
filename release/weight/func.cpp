#include "prot.hpp"
#include "debug.hpp"

//プロトタイプ宣言
int line(vest Board, veve_int weight, inin Opp, int k, int l);



//マスがなにか判定
int judge(vest Board, int Pin){  //Pin=マスの中身
    int Jug = -1;
    if(Pin == '#'){
        Jug = 1;
    }
    else if(Pin == '.'){
        Jug = 0;
    }
    else if(Pin == '@'){
        Jug = 2;
    }

    return(Jug);
}


//周りを確認
std::vector<ininin> round(vest Board, veve_int weight, inin Opp){
    int Jug = -1, score = -1; //判定用
    std::vector<ininin> Temp(0);

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(Opp.a+i < 0 || Opp.b+j < 0 || Opp.a+i > 7 || Opp.b+j > 7){ //配列がマイナス方向にいかないようにする
                break;
            }
            Jug = judge(Board, Board[Opp.a+i][Opp.b+j]);
            
            if(Jug == 0){
                int k = -1*i, l = -1*j;
                score = line(Board, weight, Opp, k, l);
                if(score != NEGA_INF){
                    score+=weight[Opp.a+i][Opp.b+j];
                    Temp.push_back( {Opp.a+i, Opp.b+j, score} );
                }
            }
        }
    }

    return Temp;
}


//列を確認
int line(vest Board, veve_int weight, inin Opp, int k, int l){
    int Count = 0, score=0;
    for(int i = 0; i < 7; i++){

        if(Opp.a+k*i < 0 || Opp.b+l*i < 0 || Opp.a+k*i > 7 || Opp.b+l*i > 7){ //配列がマイナス方向にいかないようにする
                Count = 0;
                score = NEGA_INF;
                break;
        }

        if(Board[Opp.a+k*i][Opp.b+l*i] == '@'){
            Count++;
            score+=weight[Opp.a+k*i][Opp.b+l*i];
        }
        else if(Board[Opp.a+k*i][Opp.b+l*i] == '#'){
            break;
        }
        else if(Board[Opp.a+k*i][Opp.b+l*i] == '.'){
            Count=0;
            score=NEGA_INF;
            break;
        }
    }

    if(Count >= 7){ //端に置こうとするとCount=7を返しそうになるので
            Count=0;
            score=NEGA_INF;
    }

    return score;
}