#include "../include/location.hpp"

double euclideanDist(Location a, Location b){
    return std::sqrt( std::pow(a.m_x-b.m_x, 2) + std::pow(a.m_y-b.m_y, 2) );
}