#ifndef DIR_GRAPH_H
#define DIR_GRAPH_H

#include <iostream>
#include <set>
#include "../include/edge.hpp" 
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "../include/indexPriorityQueue.hpp"
#include "../include/location.hpp"
/*
An implementation of DirectedGraph weighted DirectedGraph
*/
template <typename T> 
class DirectedGraph{
public:
    //default constructor, only null DirectedGraph can be constructed
    DirectedGraph() {}

    int getNumVertex(){return m_numVertex;}

    int getNumEdge(){return m_numEdge;}
    
    std::vector<T>& getVertexList(){return m_vertexList;}

    std::vector<std::set<Edge>>& getAdjList(){return m_adjList;}

    void addVertex(T& content);

    int getVertex(T& content){return m_content2vertex[content];}

    T getContent(int vertex);

    void addEdge(const Edge& e){this->addEdgeOneWay(e);}


protected:
    void addEdgeOneWay(const Edge& e);

private:
    int m_numVertex{0};
    int m_numEdge{0};
    std::vector<std::set<Edge>> m_adjList{};  //a vector of sets of edges
    std::vector<T> m_vertexList{};
    std::unordered_map<T, int> m_content2vertex {};
    bool vertexInRange(int v){
        return (0 <= v && v < this->getNumVertex());
    }

};

#include "../src/directedGraph.tpp"
#endif