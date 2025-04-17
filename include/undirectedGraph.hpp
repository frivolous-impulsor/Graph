#ifndef UNDIR_GRAPH_H
#define UNDIR_GRAPH_H

#include "../include/directedGraph.hpp"

template <typename T> 
class UndirectedGraph: public DirectedGraph<T>
{
public:
    void addEdge(const Edge& e);

    std::set<Edge> minimumSpanningTree();

    std::vector<double> shortestPath(T& content);

    std::vector<double> shortestPathHeuristic(Location& content);
};

#include "../src/undirectedGraph.tpp"

#endif