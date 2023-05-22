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

int line(vest Board, inin Opp, int k, int l);

//周りを確認
std::vector<ininin> round(vest Board, inin Opp){
    int Jug = -1, Count = -1; //判定用
    std::vector<ininin> Temp(0);

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(Opp.a+i < 0 || Opp.b+j < 0 || Opp.a+i > 7 || Opp.b+j > 7){ //配列がマイナス方向にいかないようにする
                continue;
            }
            Jug = judge(Board, Board[Opp.a+i][Opp.b+j]);
            if(Jug == 0){
                int k = -1*i, l = -1*j;
                Count = line(Board, Opp, k, l);
                if(Count != 0){
                    Temp.push_back( {Opp.a+i, Opp.b+j, Count} );
                }
            }
        }
    }

    return Temp;
}

//列を確認
int line(vest Board, inin Opp, int k, int l){
    int Count = 0;
    for(int i = 0; i < 7; i++){

        if(Opp.a+k*i < 0 || Opp.b+l*i < 0 || Opp.a+k*i > 7 || Opp.b+l*i > 7){ //配列がマイナス方向にいかないようにする
                Count = 0;
                continue;
        }

        if(Board[Opp.a+k*i][Opp.b+l*i] == '@'){
            Count++;
        }
        else if(Board[Opp.a+k*i][Opp.b+l*i] == '#'){
            break;
        }
        else if(Board[Opp.a+k*i][Opp.b+l*i] == '.'){
            Count = 0;
            break;
        }
        else{
            Count = 0;
            break;
        }
    }

    if(Count >= 7){ //端に置こうとするとCount=7を返しそうになるので
            Count = 0;
    }

    return Count;
}