#include <iostream>
#include <set>
#include "../include/edge.h" 
#include <vector>
#include <stdexcept>

template <typename T> 
class Graph{
public:
    //default constructor, only null graph can be constructed
    Graph() {}

    int getNumVertex(){return m_numVertex;}

    int getNumEdge(){return m_numEdge;}
    
    std::vector<T>& getVertexList(){return m_vertexList;}

    std::vector<std::set<Edge>>& getAdjList(){return m_adjList;}
    
    void addVertex(T& content = 0){
        m_vertexList.push_back(content);
        m_adjList.emplace_back();
        m_numVertex++;
    }

    //only add edge from this vertex to that vertex
    void addEdgeOneWay(const Edge& e){
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

    void addEdge(const Edge& e){
        this->addEdgeOneWay(e);
        const Edge f{e.getThatVertex(), e.getThisVertex(), e.getWeight()};
        this->addEdgeOneWay(f);
    }

private:
    int m_numVertex{0};
    int m_numEdge{0};
    std::vector<std::set<Edge>> m_adjList{};  //a vector of sets of edges
    std::vector<T> m_vertexList{};
};