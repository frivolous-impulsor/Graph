#include <iostream>
#include "edge.cpp"

/*
g++ main.cpp edge.cpp -std=c++17 -o main
*/

int main(int argc, char const *argv[])
{
    Edge e{0, 1, 5};
    int u = e.getThisVertex();
    int v = e.getThatVertex();
    int w = e.getWeight();
    std::cout<<u<<v<<w;
    return 0;
}
