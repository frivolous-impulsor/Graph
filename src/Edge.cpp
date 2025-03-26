#include "../include/edge.h"
#include <stdexcept>

Edge::Edge(const int thisV, const int thatV, const double weight)
    : m_thisVertex{thisV}
    , m_thatVertex{thatV}
    , m_weight{weight}
{
    if(thisV == thatV){
        throw std::invalid_argument("edge only connects to different vertices");
    }
}

bool Edge::operator<(const Edge& other) const {
    if (m_thisVertex != other.m_thisVertex) 
        return m_thisVertex < other.getThisVertex();
    return m_thatVertex < other.getThatVertex();
}


