#include "../include/directedGraph.hpp"


/*
An implementation of undirected weighted UndirectedGraph
*/

template <typename T> 
class UndirectedGraph: public DirectedGraph<T>
{
public:
    void addEdge(const Edge& e){
        this->addEdgeOneWay(e);
        const Edge f{e.getThatVertex(), e.getThisVertex(), e.getWeight()};
        this->addEdgeOneWay(f);
}
};