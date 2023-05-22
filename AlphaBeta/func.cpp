#ifndef FUNC_CPP
#define FUNC_CPP

#include "prot.hpp"
#include "debug.hpp"

//プロトタイプ宣言
int line(std::vector<std::string> Board, std::vector<std::vector<int>> weight, inin Opp, int k, int l);



//マスがなにか判定
int judge(std::vector<std::string> Board, int Pin){  //Pin=マスの中身
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
void round(std::vector<std::string> Board, std::vector<std::vector<int>> weight, inin Opp, std::vector<std::vector<int>> &Score){
    int Jug = -1, score = NEGA_INF; //判定用
    std::vector<ininin> Temp(0);

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(Opp.a+i < 0 || Opp.b+j < 0 || Opp.a+i > 7 || Opp.b+j > 7){ //配列がマイナス方向にいかないようにする
                break;
            }
            Jug = judge(Board, Board[Opp.a+i][Opp.b+j]);
            //std::cout << "jug"<<Jug<< std::endl;
            if(Jug == 0){
                score = line(Board, weight, Opp, i, j);
                //std::cout << "score " << score << std::endl;
                if(score != NEGA_INF){
                    score+=weight[Opp.a+i][Opp.b+j];
                    //std::cout << "score " << score << std::endl;
                }
            }

            if(Score[Opp.a+i][Opp.b+j] == NEGA_INF){
                Score[Opp.a+i][Opp.b+j] = score;
            }
            else if(Score[Opp.a+i][Opp.b+j] != NEGA_INF  && score != NEGA_INF){
                Score[Opp.a+i][Opp.b+j] += score;
            }
            score=NEGA_INF;
//debug_4(Score);
        //std::cout << Opp.a << " " << Opp.b << std::endl;
        //std::cout << i << " " << j << std::endl << std::endl; 
        }
    }
}


//列を確認
int line(std::vector<std::string> Board, std::vector<std::vector<int>> weight, inin Opp, int i, int j){
    int Count = 0, score=0;
    int k = -1*i, l = -1*j;
    for(int t = 0; t < 7; t++){
        if(Opp.a+k*t < 0 || Opp.b+l*t < 0 || Opp.a+k*t > 7 || Opp.b+l*t > 7){ //配列がマイナス方向にいかないようにする
                Count = 0;
                score = NEGA_INF;
                break;
        }

        if(Board[Opp.a+k*t][Opp.b+l*t] == '@'){
            Count++;
            score+=weight[Opp.a+k*t][Opp.b+l*t];
        }
        else if(Board[Opp.a+k*t][Opp.b+l*t] == '#'){
            break;
        }
        else if(Board[Opp.a+k*t][Opp.b+l*t] == '.'){
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


//置ける場所を探索&スコアの算出
std::vector<inin> select(std::vector<std::string> Board, std::vector<std::vector<int>> weight, std::vector<std::vector<int>> &Score){
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
//debug_2(Opp, Opp_num);
    std::vector<inin> Able(0);  //配置可能マスを記録

    //相手の駒の周りを確かめつつ、その列を見て置けるか判断する
    for(int i = 0; i < Opp_num; i++){
        round(Board, weight, Opp[i], Score);    //(座標, 重み表, 相手のコマ, 取れる重みのスコア(参照渡し))
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(Score[i][j] != NEGA_INF){
                    Able.push_back(inin{i, j});
                }
            }
        }
    }
}


//列を確認(Ver.シミュレーション)
int put_line(std::vector<std::string> VBoard, inin Put, int k, int l){
    int Count = 0;
    for(int t = 1; t < 8; t++){
        if(Put.a+k*t < 0 || Put.b+l*t < 0 || Put.a+k*t > 8 || Put.b+l*t > 8){ //配列がマイナス方向にいかないようにする
                Count = 0;
                break;
        }

        if(VBoard[Put.a+k*t][Put.b+l*t] == '@'){
            Count++;
        }
        else if(VBoard[Put.a+k*t][Put.b+l*t] == '#'){
            break;
        }
        else if(VBoard[Put.a+k*t][Put.b+l*t] == '.'){
            Count=0;
            break;
        }
    }

    std::cout << Count << std::endl;
    return Count;
}


//石を置く
std::vector<std::string> put(inin Point, std::vector<std::string> Board){
    Board[Point.a][Point.b] = '#';
    for(int k = -1; k < 1; k++){
        for(int l = -1; l < 1; l++){
            int count = put_line(Board, {Point.a, Point.b}, k, l);
            for(int j = 1; j <= count; j++){
                Board[Point.a+k*j][Point.b+k*j] = '#';
            }
        }
    }
    //debug_1(Board);
    return Board;
}

#endif