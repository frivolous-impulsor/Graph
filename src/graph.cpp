#include <iostream>
#include <iostream>
#include <set>
#include <optional>
#include <include/edge.h>
#include <vector>

template <typename T>
class Graph{
public:
    //default constructor, only null graph can be constructed
    Graph() {}

    Graph(int numVertices, std::vector<T> &vertices)
        : m_numVertex{numVertices}
        , m_vertexList{vertices}

    void addVertex(T& content = 0){
        m_vertexList.push_back(content);
        m_numVertex++;
    }

    //only add edge from this vertex to that vertex
    void addEdge(Edge& e){
        const int u {e.getThisVertex()};
        int initSize{m_adjList[u].size()};
        m_adjList[u].insert(e);
        int finalSize{m_adjList[u].size()}
        m_nunEdge += (finalSize - initSize);
    }

    void addEdgeUndirected(Edge& e){
        this->addEdge(e);

        Edge f{e.getThatVertex(), e.getThisVertex(), e.getWeight() }
        this->addEdge(f);
    }

    

        

private:
    int m_numVertex{0}
    int m_numEdge{0}
    std::vector<set<Edge>> m_adjList{};  //a vector of sets of edges
    std::vector<T> m_vertexList{};
}