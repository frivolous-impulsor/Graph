#include "../include/undirectedGraph.hpp"


/*
An implementation of undirected weighted UndirectedGraph
*/


template <typename T> 
void UndirectedGraph<T>::addEdge(const Edge& e){
    this->addEdgeOneWay(e);
    const Edge f{e.getThatVertex(), e.getThisVertex(), e.getWeight()};
    this->addEdgeOneWay(f);
}



template <typename T> 
std::set<Edge> UndirectedGraph<T>::minimumSpanningTree(){
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

template <typename T> 
std::vector<double> UndirectedGraph<T>::shortestPath(T& content){
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

template <typename T> 
std::vector<double> UndirectedGraph<T>::shortestPathHeuristic(Location& content){
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