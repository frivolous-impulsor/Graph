#include "../include/edge.hpp"
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
    return m_weight < other.getWeight();
}

bool Edge::operator==(const Edge& other) const {
    const bool go   = (m_thisVertex == other.getThisVertex()) && (m_thatVertex == other.getThatVertex());
    const bool come = (m_thisVertex == other.getThatVertex()) && (m_thatVertex == other.getThisVertex());
    return (go || come);
}

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os <<"["<< e.getThisVertex() << " - " << e.getThatVertex() << " : " << e.getWeight() <<"]";
    return os;
}

