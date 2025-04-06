#ifndef LOCATION_H
#define LOCATION_H

#include <cmath>

class Location{
public:
    Location(double x, double y)
        :m_x{x}
        ,m_y{y}
    {}

    double getX() const{
        return m_x;
    }

    double getY() const{
        return m_y;
    }

    bool operator<(const Location& other) const {
        return (m_x < other.m_x && m_y < other.m_y);
    }
    
    bool operator==(const Location& other) const {
        return (m_x == other.m_x && m_y == other.m_y);
    }

friend double euclideanDist(Location a, Location b);    

private:
    double m_x {};
    double m_y {};
};

double euclideanDist(Location a, Location b){
    return std::sqrt( std::pow(a.m_x-b.m_x, 2) + std::pow(a.m_y-b.m_y, 2) );
}

template <>
struct std::hash<Location>
{
  std::size_t operator()(const Location& e) const
  {
    using std::size_t;
    using std::hash;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<double>()(e.getX())
             ^ (hash<double>()(e.getY()) << 1)) >> 1);
  }
};

#endif