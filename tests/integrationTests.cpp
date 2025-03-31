#include "../include/catch_amalgamated.hpp"
#include "../include/edge.hpp"
#include "../src/graph.cpp"
#include "../src/indexPriorityQueue.cpp"
#include <stdexcept>
	


TEST_CASE("integration test", "[edge and indexPQ]"){
    SECTION("create min pq with edge elements"){
        try{
            IndexPriorityQueue<Edge> q{false};
            REQUIRE(true);
        }catch (std::exception e){
            REQUIRE(false);
        }
    }

    SECTION("integration testing on edge min queue: insert, update, peek, pop"){
        IndexPriorityQueue<Edge> q{false};
        q.insert({0,1}, 5);
        q.insert({1,3}, 1);
        q.insert({1,2}, 4);
        q.insert({1,2}, 0);
        Edge e {1,2};
        Edge f {1,3};
        Edge g {0,1};
        REQUIRE(q.pop() == e);
        REQUIRE(q.pop() == f);
        REQUIRE(q.pop() == g);
        REQUIRE(q.empty());

        Edge h {1,9};
        q.insert(e, 5);
        q.insert(f, 12);
        q.insert(g, 1);
        q.insert(h, 10);
        q.insert({2,9}, 13);
        REQUIRE(q.peek() == g);
        q.pop();
        q.pop();
        REQUIRE(q.peek() == h);
        
    }
}