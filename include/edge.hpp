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

    bool operator<(const Edge& other) const;

    bool operator==(const Edge& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Edge& e);


private:
    int m_thisVertex{};
    int m_thatVertex{};
    double m_weight{1};
};


template <>
struct std::hash<Edge>
{
  std::size_t operator()(const Edge& e) const
  {
    using std::size_t;
    using std::hash;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<int>()(e.getThisVertex())
             ^ (hash<int>()(e.getThatVertex()) << 1)) >> 1);
  }
};


#endif