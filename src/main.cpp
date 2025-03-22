#include <iostream>
#include "../include/Edge.h"

int main(int argc, char const *argv[])
{
    Edge e{0, 1, 88};
    int u = e.getThisVertex();
    int v = e.getThatVertex();
    int w = e.getWeight();
    std::cout<<u<<v<<w;
    return 0;
}
