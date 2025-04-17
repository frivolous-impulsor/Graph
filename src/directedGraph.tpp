#include "../include/directedGraph.hpp"
/*
An implementation of DirectedGraph weighted DirectedGraph
*/

template <typename T>
void DirectedGraph<T>::addEdgeOneWay(const Edge& e){
    int u {e.getThisVertex()};
    int v {e.getThatVertex()};
    if (!(u < this->getNumVertex() && v < this->getNumVertex())){
        throw std::invalid_argument("reached outside available vertex, ensure valid vertex before adding Edge");
    }
    int initSize{static_cast<int>(m_adjList[u].size())};
    m_adjList[u].insert(e);
    int finalSize{static_cast<int>(m_adjList[u].size())};
    m_numEdge += (finalSize - initSize);
}

template <typename T>
void DirectedGraph<T>::addVertex(T& content){
    m_vertexList.push_back(content);
    m_adjList.emplace_back();
    m_content2vertex[content] = m_numVertex;
    m_numVertex++;
}

template <typename T>
T DirectedGraph<T>::getContent(int vertex){
    if(!this->vertexInRange(vertex)){
        throw std::invalid_argument("vertex not in range");
    }
    return m_vertexList[vertex];
}