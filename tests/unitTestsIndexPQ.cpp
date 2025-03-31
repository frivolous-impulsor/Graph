#include "../include/catch_amalgamated.hpp"
#include "../src/indexPriorityQueue.cpp"
#include <stdexcept>
	

TEST_CASE("index priority queue", "[Index PQ]"){
    SECTION("insert"){
        IndexPriorityQueue<int> q {};
        q.insert(0, 2);
        q.insert(1, 1);
        q.insert(2, 3);
        q.insert(3, 4);
        q.insert(4, 8);
        std::vector<int> positionMap {2, 3, 4, 1, 0};
        std::vector<int> inverseMap {4, 3, 0, 1, 2};
        REQUIRE(q.getPositionMap() == positionMap);
        REQUIRE(q.getInverseMap() == inverseMap);
        REQUIRE(q.getSize() == 5);
    }


    SECTION("peek top"){
        IndexPriorityQueue<int> q {};
        q.insert(0, 2);
        q.insert(1, 1);
        q.insert(2, 10);
        q.insert(3, 4);
        q.insert(4, 8);

        REQUIRE(q.peek() == 2);
    }

    SECTION("pop top"){
        IndexPriorityQueue<int> q {};

        try{    //pop empty queue should throw exception
            q.pop();
            REQUIRE(false);
        }catch (std::underflow_error u){
            REQUIRE(true);
        }

        q.insert(233, 4);
        q.insert(912, 12);
        q.insert(241, 100);
        q.insert(234, 4.4);
        q.insert(4, 8);

        REQUIRE(q.pop() == 241);
        REQUIRE(q.pop() == 912);
        REQUIRE(q.getSize() == 3);


    }

    SECTION("update"){
        IndexPriorityQueue<int> q {};
        q.insert(421, 2);
        q.insert(43145, 1);
        q.insert(3414, 3);
        q.insert(22, 221);
        q.insert(45, 4);
        
        REQUIRE(q.peek() == 22);

        q.update(22, 3);
        REQUIRE(q.peek() == 45);

        std::vector<int> positionMap {2, 3, 4, 1, 0}; 
        std::vector<int> inverseMap {4, 3, 0, 1, 2};
        REQUIRE(q.getPositionMap() == positionMap);
        REQUIRE(q.getInverseMap() == inverseMap); 
    }

    SECTION("insert duplicate item only update "){
        IndexPriorityQueue<int> q {};
        q.insert(421, 60);
        q.insert(22, 50);
        REQUIRE(q.getSize() == 2);
        q.insert(421, 40);
        REQUIRE(q.getSize() == 2);
        REQUIRE(q.peek() == 22);
    }


    SECTION("integration test for insert, peek, pop, update"){
        IndexPriorityQueue<int> q {};
        q.insert(4, 9);
        q.insert(12, 2);
        q.insert(1, 7.7);
        q.insert(55, 3);
        q.insert(53, 9);
        q.insert(67, 9);
        q.insert(98, 1.4);

        int a {q.pop()};
        REQUIRE(a == 4);
        q.update(67, 50);
        REQUIRE(q.getSize() == 6);
        REQUIRE(q.peek() == 67);
        q.insert(67, 0);
        REQUIRE(q.getSize() == 6);
        REQUIRE(q.peek() == 53);
        q.pop();
        REQUIRE(q.getSize() == 5);
        REQUIRE(q.peek() == 1);
        q.pop();
        REQUIRE(q.peek() == 55);
        q.insert(99, -50);
        REQUIRE(q.peek() == 99);
        q.pop();
    }
}