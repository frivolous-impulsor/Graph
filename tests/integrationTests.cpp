#include "../include/catch_amalgamated.hpp"
#include "../include/edge.hpp"
#include "../src/graph.cpp"
#include "../src/indexPriorityQueue.cpp"
#include <stdexcept>
	


TEST_CASE("index priority queue", "[Index PQ]"){
    SECTION("insert"){
        IndexPriorityQueue<Edge> q {};
        q.insert({0,1}, 2);
        q.insert({1,2}, 1);
        q.insert({1,3}, 3);
        q.insert({1,3}, 4);
        q.insert({1,3}, 8);
        std::vector<int> positionMap {2, 3, 4, 1, 0};
        std::vector<int> inverseMap {4, 3, 0, 1, 2};
        REQUIRE(q.getPositionMap() == positionMap);
        REQUIRE(q.getInverseMap() == inverseMap);
        REQUIRE(q.getSize() == 5);
    }

    SECTION("peek top"){
        IndexPriorityQueue<Edge> q {};
        Edge highestEdge {1,3};
        q.insert({0,1}, 2);
        q.insert({1,2}, 1);
        q.insert(highestEdge, 10);
        q.insert({1,3}, 4);
        q.insert({1,3}, 8);

        REQUIRE(q.peek() == highestEdge);
    }

    SECTION("pop top"){
        IndexPriorityQueue<Edge> q {};
        Edge highestEdge {1,3};
        Edge secondHighestEdge {2,3};
        q.insert({0,1}, 4);
        q.insert(secondHighestEdge, 12);
        q.insert(highestEdge, 100);
        q.insert({1,3}, 4.4);
        q.insert({1,3}, 8);

        REQUIRE(q.pop() == highestEdge);
        REQUIRE(q.pop() == secondHighestEdge);
        REQUIRE(q.getSize() == 3);
    }

    SECTION("update"){
        IndexPriorityQueue<Edge> q {};
        Edge highestEdge {3,4};
        Edge secondEdge {0,3};
        q.insert({0,1}, 2);
        q.insert({1,2}, 1);
        q.insert({2,3}, 3);
        q.insert(highestEdge, 8);
        q.insert(secondEdge, 4);
        
        REQUIRE(q.peek() == highestEdge);

        q.update(highestEdge, 3);
        REQUIRE(q.peek() == secondEdge);

        std::vector<int> positionMap {2, 3, 4, 1, 0}; 
        std::vector<int> inverseMap {4, 3, 0, 1, 2};
        REQUIRE(q.getPositionMap() == positionMap);
        REQUIRE(q.getInverseMap() == inverseMap); 
    }

    SECTION("integration test for insert, peek, pop, update"){
        IndexPriorityQueue<Edge> q {};
        Edge a{0,1};
        Edge b{0,2};
        Edge c{0,3};
        Edge d{1,4};
        Edge e{2,4};
        Edge f{6,1};
        Edge g{2,8};
        q.insert(a, 9);
        q.insert(b, 2);
        q.insert(c, 7.7);
        q.insert(d, 3);
        q.insert(e, 9);
        q.insert(f, 9);
        q.insert(g, 1.4);

        Edge r {q.pop()};
        REQUIRE(r == a);
    }

}