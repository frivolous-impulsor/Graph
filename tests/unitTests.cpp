#include "../include/catch_amalgamated.hpp"
#include "../include/Edge.h"

TEST_CASE( "Edges valid containers", "[Edge]" ) {
    Edge e{0, 1, 3};
    SECTION("edge constructor"){
        REQUIRE( e.getThisVertex() == 0 );
        REQUIRE( e.getThatVertex() == 1 );
        REQUIRE( e.getWeight() == 3 );
    }

    SECTION("edge setters"){
        e.setWeight(5);
        REQUIRE(e.getWeight() == 5);
    }

    SECTION("create double or float weighted edge"){
        try
        {
            Edge<double> d{1,2, 2.2};
            Edge<float> f{2,3, 4.1f};
            REQUIRE(true);
        }
        catch(const std::exception& e)
        {
            REQUIRE(false);
        }
        
    }

    SECTION("edge cannot connect 2 same vertices"){
        try
        {
            Edge e{1,1, 2};
            REQUIRE(false);
        }
        catch(const std::invalid_argument& e)
        {
            REQUIRE(true);
        }
        
        
    }
}