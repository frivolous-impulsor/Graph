#include "../include/Edge.h"

template <class T>
Edge<T>::Edge(const int thisV, const int thatV, const T weight)
    : m_thisVertex{thisV}
    , m_thatVertex{thatV}
    , m_weight{weight}
{}

void TemporaryFunction ()
{
    Edge<int> e{0,0,0};
}
