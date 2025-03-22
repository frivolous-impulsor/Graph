#include "../include/edge.h"
#include <stdexcept>

template <class T>
Edge<T>::Edge(const int thisV, const int thatV, const T weight)
    : m_thisVertex{thisV}
    , m_thatVertex{thatV}
    , m_weight{weight}
{
    if(thisV == thatV){
        throw std::invalid_argument("edge only connects to different vertices");
    }
}

void TemporaryFunction ()
{
    Edge<int> e{0,1,0};
    Edge<double> f{0, 1,1.1};
    Edge<float> g{0, 1, 1.2f};
}
