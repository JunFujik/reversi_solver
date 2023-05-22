#ifndef DEBUG_HPP
#define DEBUG_HPP

//盤面出力
void debug_1(vest Board){
    std::cout << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7" << std::endl;
    for(int i = 0; i < 8; i++){
        std::cout << i << " ";
        for(int j = 0; j < 8; j++){
            std::cout << Board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//相手のマスの位置を確認
void debug_2(std::vector<inin> Opp, int Opp_num){
    std::cout << "debug_2" << std::endl;
    for(int i = 0; i < Opp_num; i++){
        std::cout << Opp[i].a << Opp[i].b << " ";
    }
}

//隣接を出力
void debug_3(std::vector<ininin> Neb){
    std::cout << std::endl << "debug_3" << std::endl;
    for(int i = 0; i < Neb.size(); i++){
        std::cout << Neb[i].a << Neb[i].b << Neb[i].c << ' ';
    }
}

#endif