#include "../include/Node.h"
#include "../include/Graph.h"
#include "../catch/catch.hpp"
#include "../catch/catchmain.cpp"

//int main() {
    bool passed = true;
    bool allPassed = true;
TEST_CASE("Test Cleaning", "[weight=1][part=1]") {
    std::cout << "TEST CLEAN" << std::endl;
    Graph gc("./data/test_cleaning.csv");
    REQUIRE(gc.isClean());
}

TEST_CASE("Test Adjacency Matrix", "[weight=1][part=1]") {
    Graph gc("./data/test_cleaning.csv");
    int r;
    r = gc.getRating(0,1);
    REQUIRE(r == -4);
    r = gc.getRating(0,5);
    REQUIRE(r == -10);
    r = gc.getRating(1,4);
    REQUIRE(r == 3);
    r = gc.getRating(1,2);
    REQUIRE(r == 0);
    r = gc.getRating(2,3);
    REQUIRE(r == 4);

}


TEST_CASE("Test DFS Basic", "[weight=1][part=2]") {
    Graph g1("./data/test_basic.csv");
    std::vector<int> t1;
    std::vector<int> t1s;
    t1s.push_back(0);
    t1s.push_back(1);
    t1s.push_back(2);
    t1s.push_back(3);
    t1s.push_back(5);
    t1s.push_back(6);
    g1.BasicDFS(t1);
    for(size_t i = 0; i < t1.size(); i++) {
        std::cout << "Found: "<< t1[i] << " expected: "<< t1s[i] << std::endl;
        REQUIRE(t1[i] == t1s[i]);
    }
}

TEST_CASE("Test DFS Cycle", "[weight=1][part=2]") {
    Graph g2("./data/test_cycle.csv");
    std::vector<int> t2;
    std::vector<int> t2s;
    t2s.push_back(0);
    t2s.push_back(1);
    t2s.push_back(2);
    t2s.push_back(3);
    t2s.push_back(4);
    g2.BasicDFS(t2);
    for(size_t i = 0; i < t2.size(); i++) {
        std::cout << "Found: "<< t2[i] << " expected: "<< t2s[i] << std::endl;
        REQUIRE(t2[i] == t2s[i]);
    }
}

TEST_CASE("Test DFS Disjoint", "[weight=1][part=2]") {
    Graph g3("./data/test_disjoint.csv");
    std::vector<int> t3;
    std::vector<int> t3s;
    t3s.push_back(0);
    t3s.push_back(1);
    t3s.push_back(2);
    t3s.push_back(3);
    t3s.push_back(4);
    t3s.push_back(5);
    g3.BasicDFS(t3);
    for(size_t i = 0; i < t3.size(); i++) {
        std::cout << "Found: "<< t3[i] << " expected: "<< t3s[i] << std::endl;
        REQUIRE(t3[i] == t3s[i]);
    }
}

TEST_CASE("Test DFS Worthless", "[weight=1][part=2]") {
    Graph g4("./data/test_worthless.csv");
    std::vector<int> t4;
    std::vector<int> t4s;
    t4s.push_back(0);
    t4s.push_back(1);
    t4s.push_back(2);
    t4s.push_back(3);
    t4s.push_back(5);
    t4s.push_back(7);
    g4.BasicDFS(t4);
    for(size_t i = 0; i < t4.size(); i++) {
        std::cout << "Found: "<< t4[i] << " expected: "<< t4s[i] << std::endl;
        REQUIRE(t4[i] == t4s[i]);
    }
}


    //return 0;
//}