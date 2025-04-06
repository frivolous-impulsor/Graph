#include "../include/catch_amalgamated.hpp"
#include "../include/indexPriorityQueue.hpp"
#include <stdexcept>
#include "../include/location.hpp"
#include <unordered_map>
#include <set>
	

TEST_CASE("location", "[Location]"){
    Location a {0, 0};
    Location b {1, 0};
    Location c {1, 1};
    SECTION("location construct"){
        
        REQUIRE(euclideanDist(a,b) == 1);
        REQUIRE(euclideanDist(a,c) == std::sqrt(2));
    }

    SECTION("Location object suitable for set and unordered_map"){
        std::unordered_map<Location, int> map{};
        map[a] = 0;
        map[b] = 1;
        map[c] = 2;
        REQUIRE(true);
        std::set<Location> setLoc{};
        setLoc.insert(a);
        setLoc.insert(b);
        setLoc.insert(c);
        REQUIRE(true);
    }

}

