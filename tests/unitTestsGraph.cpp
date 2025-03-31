#include "../include/catch_amalgamated.hpp"
#include "../include/edge.hpp"
#include "../src/graph.cpp"
#include "../src/indexPriorityQueue.cpp"
#include <stdexcept>
	

TEST_CASE( "Edges valid containers", "[Edge]" ) {
    Edge e{0, 1, 3.2};
    SECTION("edge constructor"){
        REQUIRE( e.getThisVertex() == 0 );
        REQUIRE( e.getThatVertex() == 1 );
        REQUIRE( e.getWeight() == 3.2 );
    }

    SECTION("default edge is of weight 1"){
        Edge d{1,2};
        REQUIRE(d.getWeight() == 1);
    }

    SECTION("edge setters"){
        e.setWeight(5);
        REQUIRE(e.getWeight() == 5);
    }

    SECTION("create double or float or int weighted edge"){
        try
        {
            Edge i{0,1, 5};
            Edge d{1,2, 2.2};
            Edge f{2,3, 4.1f};
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

TEST_CASE( "Graph Unit Tests", "[Graph]") {
    
    SECTION("construct empty graph and add vertices of any content type"){
        Graph<std::vector<int>> g{};
        Edge e{0, 1};
        REQUIRE(g.getNumVertex() == 0);
        std::vector<int> testContent{};
        g.addVertex(testContent);
        g.addVertex(testContent);
        g.addVertex(testContent);
        REQUIRE(g.getNumVertex() == 3);
        REQUIRE(g.getVertexList()[0].size() == 0);
    }

    SECTION("added vertices each take a spot in adjList"){
        Graph<int> g{};
        int testContent = -1;
        g.addVertex(testContent);
        g.addVertex(testContent);
        REQUIRE(g.getAdjList()[0].size() == 0);
        REQUIRE(g.getAdjList()[1].size() == 0);
    }
    /*
    SECTION("add edges one way to graph"){
        Graph<int> g{};
        
        //add 3 vertices 0, 1, 2 to graph
        int dummyContent = -1;
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);

        //add edge 0 -> 1, 1 -> 2, 0 -> 2
        double dummyWeight {8.2};
        double dummyWeightDiff {5.3};
        const Edge e{0, 1, dummyWeight};
        const Edge f{1, 2, dummyWeight};
        const Edge h{0, 2, dummyWeight};
        g.addEdgeOneWay(e);
        g.addEdgeOneWay(f);
        g.addEdgeOneWay(h);

        REQUIRE(g.getAdjList()[0].size() == 2);
        REQUIRE(g.getAdjList()[1].size() == 1);
        REQUIRE(g.getAdjList()[2].size() == 0);

        const Edge i{0, 2, dummyWeightDiff};    //edge i has same vertices of h, only different weight. h should be regarded duplicate of edge h and ignored
        g.addEdgeOneWay(i);
        REQUIRE(g.getAdjList()[0].size() == 2);

        REQUIRE(g.getAdjList()[0].find(e) != g.getAdjList()[0].end());
        
    }
    */

    SECTION("throw exception when attempting to add invalid edge that has undefined vertex"){
        Graph<int> g{};
        int dummyContent = -1;

        //add vertex 0, 1, 2
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);
        g.addEdge({0,1});
        try{
            //vertex 3 undefined, should throw invalid_argument exception
            g.addEdge({1, 3});
            REQUIRE(false);
        }catch(std::invalid_argument e){
            REQUIRE(true);
        }
    }

    SECTION("add edges 2 ways to graph"){
        Graph<int> g{};
        
        //add 3 vertices 0, 1, 2 to graph
        int dummyContent = -1;
        g.addVertex(dummyContent);
        g.addVertex(dummyContent);

        const Edge e {0, 1};

        g.addEdge(e);
        REQUIRE(g.getAdjList()[0].size() == 1);
        REQUIRE(g.getAdjList()[1].size() == 1);

        REQUIRE((*g.getAdjList()[0].begin()).getThisVertex() == 0);
        REQUIRE((*g.getAdjList()[0].begin()).getThatVertex() == 1);
        REQUIRE((*g.getAdjList()[1].begin()).getThisVertex() == 1);
        REQUIRE((*g.getAdjList()[1].begin()).getThatVertex() == 0);
    }
}
/*
TEST_CASE( "Graph Operation Unit Tests", "[Graph Operation]") {
    SECTION("minimum spanning tree validation"){
        Graph<int> g{};
        int dummyContent = -1;
        for(int i {0} ; i < 9; ++i){
            g.addVertex(dummyContent);
        }
        g.addEdge({0,1,4});
        g.addEdge({0,7,8});
        g.addEdge({1,2,8});
        g.addEdge({1,7,11});

        g.addEdge({7,8,7});
        g.addEdge({7,6,1});
        g.addEdge({2,3,7});
        g.addEdge({6,8,6});
        g.addEdge({2,8,2});
        
        g.addEdge({2,5,4});
        g.addEdge({5,6,2});
        g.addEdge({3,5,14});
        g.addEdge({3,4,9});
        g.addEdge({5,4,10});
        
        std::vector<Edge> answer {};
        answer.push_back({0,1,4});
        REQUIRE(g.mst() == answer);
    }
}
*/