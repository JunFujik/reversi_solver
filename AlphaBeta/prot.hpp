#ifndef PROT_HPP
#define PROT_HPP

#include <iostream>
#include <string>
#include <vector>

#define NEGA_INF -1000000

//重み
const std::vector<std::vector<int>> weight={
    {1000,-100,50,1,1,50,-100,1000},
    {-100,-100,50,1,1,50,-100,-100},
    {50,50,50,1,1,50,50,50},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {50,50,50,1,1,50,50,50},
    {-100,-100,50,1,1,50,-100,-100},
    {1000,-100,50,1,1,50,-100,1000},
};

struct inin{
    int a;
    int b;
};

struct ininin{
    int a;
    int b;
    int c;
};

#endif