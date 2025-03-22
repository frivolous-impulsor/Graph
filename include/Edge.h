#ifndef EDGE_H
#define EDGE_H

template <typename T>
class Edge{
public:
    Edge(const int thisV, const int thatV, const T weight);

    void setWeight(T newWeight){
        this->m_weight = newWeight;
    }

    T getWeight(){
        return this->m_weight;
    }

    int getThisVertex(){
        return this->m_thisVertex;
    }

    int getThatVertex(){
        return this->m_thatVertex;
    }

private:
    int m_thisVertex{};
    int m_thatVertex{};
    T m_weight{};
};

#endif