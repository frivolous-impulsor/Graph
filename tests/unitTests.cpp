#include "../include/catch_amalgamated.hpp"
#include "../include/Edge.h"

TEST_CASE( "Edges valid containers", "[Edge]" ) {
    Edge e{0, 1, 3};
    REQUIRE( e.getThisVertex() == 0 );
    REQUIRE( e.getThatVertex() == 1 );
}