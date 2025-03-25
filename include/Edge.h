#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge{
public:
    Edge(const int thisV, const int thatV, const double weight = 1);

    void setWeight(double newWeight){
        this->m_weight = newWeight;
    }

    double getWeight() const{
        return this->m_weight;
    }

    int getThisVertex() const{
        return this->m_thisVertex;
    }

    int getThatVertex() const{
        return this->m_thatVertex;
    }

    bool operator<(const Edge& other) const ;

private:
    int m_thisVertex{};
    int m_thatVertex{};
    double m_weight{1};
};

#endif