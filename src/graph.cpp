#include <iostream>
#include <set>
#include "../include/edge.hpp" 
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "../include/indexPriorityQueue.hpp"
#include "../include/location.hpp"

/*
An implementation of undirected weighted graph
*/



template <typename T> 
class Graph{
public:
    //default constructor, only null graph can be constructed
    Graph() {}

    int getNumVertex(){return m_numVertex;}

    int getNumEdge(){return m_numEdge;}
    
    std::vector<T>& getVertexList(){return m_vertexList;}

    std::vector<std::set<Edge>>& getAdjList(){return m_adjList;}


    
    void addVertex(T& content){
        m_vertexList.push_back(content);
        m_adjList.emplace_back();
        m_content2vertex[content] = m_numVertex;
        m_numVertex++;
    }

    int getVertex(T& content){
        return m_content2vertex[content];
    }

    T getContent(int vertex){
        if(!this->vertexInRange(vertex)){
            throw std::invalid_argument("vertex not in range");
        }
        return m_vertexList[vertex];
    }

    void addEdge(const Edge& e){
        this->addEdgeOneWay(e);
        const Edge f{e.getThatVertex(), e.getThisVertex(), e.getWeight()};
        this->addEdgeOneWay(f);
    }

    std::set<Edge> minimumSpanningTree(){
        if(this->getNumVertex() < 2){
            return {};
        }
        double inf {std::numeric_limits<float>::infinity()};
        Edge dummy {-1, -2};
        std::vector<Edge> mst {};
        std::set<Edge> result {};
        for(int i {0}; i<this->getNumVertex(); ++i){
            mst.push_back(dummy);
        }
        int s {0};
        std::set<int> mstSet {};
        mstSet.insert(s);
        IndexPriorityQueue<int> minPQ {false};
        for (int i {0}; i<this->getNumVertex(); ++i){
            minPQ.insert(i, inf);
            //std::cout<<minPQ.getValue(i)<<'\n';
        }
        minPQ.insert(s, 0);

        while(mstSet.size() < this->getNumVertex()){
            int u {minPQ.pop()};
            mstSet.insert(u);
            for(auto edge: this->getAdjList()[u]){
                int v {edge.getThatVertex()};
                if (mstSet.find(v) == mstSet.end() && edge.getWeight() < minPQ.getValue(v)){
                    minPQ.update(v, edge.getWeight());
                    mst[v] = edge;
                }
            }
        }
        for(int i {1}; i<this->getNumVertex(); ++i){
            result.insert(mst[i]);
        }
        return result;
    }

    std::vector<double> shortestPath(T& content){
        int start {this->getVertex(content)};
        std::vector<int> fromArray(this->getNumVertex(), -1);
        std::vector<double> distArray(this->getNumVertex(), 0);
        double inf {std::numeric_limits<double>::infinity()};
        IndexPriorityQueue<int> minDistancePQ {false};
        for(int v {0}; v < this->getNumVertex(); ++v){
            minDistancePQ.insert(v, inf);
            distArray[v] = inf;
        }
        minDistancePQ.update(start, 0);
        distArray[start] = 0;
        while(!minDistancePQ.empty()){
            int u {minDistancePQ.pop()};
            double midDistanceToStart {distArray[u]};
            for(auto edge: this->getAdjList()[u]){
                int v {edge.getThatVertex()};
            
                if(!minDistancePQ.inQueue(v)){
                    continue;
                }
                double oldDistToStart {distArray[v]};
                double newDistToStart {edge.getWeight() + midDistanceToStart};
                if(newDistToStart < oldDistToStart){
                    minDistancePQ.update(v, newDistToStart);
                    distArray[v] = newDistToStart;
                    fromArray[v] = u;
                }
            }
        }
        return distArray;
    }


    std::vector<double> shortestPathHeuristic(Location& content){
        int start {this->getVertex(content)};
        std::vector<int> fromArray(this->getNumVertex(), -1);
        std::vector<double> distArray(this->getNumVertex(), 0);
        double inf {std::numeric_limits<double>::infinity()};
        IndexPriorityQueue<int> minDistancePQ {false};
        for(int v {0}; v < this->getNumVertex(); ++v){
            minDistancePQ.insert(v, inf);
            distArray[v] = inf;
        }
        minDistancePQ.update(start, 0);
        distArray[start] = 0;
        while(!minDistancePQ.empty()){
            int u {minDistancePQ.pop()};
            double midDistanceToStart {distArray[u]};
            for(auto edge: this->getAdjList()[u]){
                int v {edge.getThatVertex()};
            
                if(!minDistancePQ.inQueue(v)){
                    continue;
                }
                double oldDistToStart {distArray[v]};
                Location a {this->getContent(u)};
                Location b {this->getContent(v)};
                double newDistToStart {edge.getWeight() + midDistanceToStart};
                if(newDistToStart < oldDistToStart){
                    double heuristic {euclideanDist(a, b)};
                    minDistancePQ.update(v, newDistToStart + heuristic);
                    distArray[v] = newDistToStart;
                    fromArray[v] = u;
                }
            }
        }
        return distArray;
    }



private:
    int m_numVertex{0};
    int m_numEdge{0};
    std::vector<std::set<Edge>> m_adjList{};  //a vector of sets of edges
    std::vector<T> m_vertexList{};
    std::unordered_map<T, int> m_content2vertex {};



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

    bool vertexInRange(int v){
        return (0 <= v && v < this->getNumVertex());
    }


};