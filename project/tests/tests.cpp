#include "../include/Node.h"
#include "../include/Graph.h"
#include "../catch/catchmain.cpp"
#include "../catch/catch.hpp"


//int main() {
TEST_CASE("Test Cleaning", "[weight=1][part=1]") {
    //std::cout << "TEST CLEAN" << std::endl;
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
        //std::cout << "Found: "<< t1[i] << " expected: "<< t1s[i] << std::endl;
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
        //std::cout << "Found: "<< t2[i] << " expected: "<< t2s[i] << std::endl;
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
       // std::cout << "Found: "<< t3[i] << " expected: "<< t3s[i] << std::endl;
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
        //std::cout << "Found: "<< t4[i] << " expected: "<< t4s[i] << std::endl;
        REQUIRE(t4[i] == t4s[i]);
    }

}

TEST_CASE("Test 1 DFS Edge Cases", "[weight=1][part=2]") {
    Graph g5a("./data/test_worthless.csv");


    std::vector<int> t1;
    int c1 = 0;
    std::vector<bool> v1(10, false);
    std::vector<int> t2;
    int c2 = 0;
    std::vector<bool> v2(10, false);
    std::vector<int> t3;
    int c3 = 0;
    std::vector<bool> v3(10, false);

    g5a.BasicDFS(-1, v1, c1, t1);
    g5a.BasicDFS(100, v2, c2, t2);
    g5a.BasicDFS(4, v3, c3, t3);

    REQUIRE(c1 == 0);
    REQUIRE(c2 == 0);
    REQUIRE(c3 == 0);

    REQUIRE(t1.size() == 0);
    REQUIRE(t2.size() == 0);
    REQUIRE(t3.size() == 0);
}

TEST_CASE("Test Dijsktra Basic", "[weight=1][part=3]") {
    Graph g5("./data/dijk_basic.csv");

    std::vector<int> t5_a;
    std::vector<int> t5_as = {0, 1, 2, 7};

    t5_a = g5.shortestPath(0, 7);
    
    for (size_t i = 0; i < t5_a.size(); i++) {
        REQUIRE(t5_a[i] == t5_as[i]);
    }

    std::vector<int> t5_b;
    std::vector<int> t5_bs = {0, 5, 4};

    t5_b = g5.shortestPath(0, 4);
    
    for (size_t i = 0; i < t5_b.size(); i++) {
        REQUIRE(t5_b[i] == t5_bs[i]);
    }

    std::vector<int> t5_c;
    std::vector<int> t5_cs = {7, 4, 2};

    t5_c = g5.shortestPath(7, 2);
    
    for (size_t i = 0; i < t5_c.size(); i++) {
        REQUIRE(t5_c[i] == t5_cs[i]);
    }

    std::vector<int> t5_d;
    std::vector<int> t5_ds = {5, 4};

    t5_d = g5.shortestPath(5, 4);
    
    for (size_t i = 0; i < t5_d.size(); i++) {
        REQUIRE(t5_d[i] == t5_ds[i]);
    }

}

TEST_CASE("Test Dijsktra Cycles", "[weight=1][part=3]") {
    Graph g6("./data/dijk_cycle_1.csv");
    Graph g7("./data/dijk_cycle_2.csv");

    std::vector<int> t6_a;
    std::vector<int> t6_as = {0, 2, 3, 4, 5, 6, 7, 1};

    t6_a = g6.shortestPath(0, 1);

    for (size_t i = 0; i < t6_a.size(); i++) {
        REQUIRE(t6_a[i] == t6_as[i]);
    }

    std::vector<int> t6_b;
    std::vector<int> t6_bs = {0, 1};

    t6_b = g7.shortestPath(0, 1);

    for (size_t i = 0; i < t6_b.size(); i++) {
        REQUIRE(t6_b[i] == t6_bs[i]);
    }

    std::vector<int> t6_c;
    std::vector<int> t6_cs = {0};

    t6_c = g7.shortestPath(0,0);
    REQUIRE(t6_c.size() == 1);
    REQUIRE(t6_c[0] == 0);
}

TEST_CASE("Test Dijsktra Disjoint", "[weight=1][part=3]") {
    Graph g8("./data/test_disjoint.csv");

    std::vector<int> t7_a;

    t7_a = g8.shortestPath(0, 3);

    REQUIRE(t7_a.size() == 0);

    std::vector<int> t7_b;
    std::vector<int> t7_bs = {5, 4};

    t7_b = g8.shortestPath(5, 4);

    for (size_t i = 0; i < t7_b.size(); i++) {
        REQUIRE(t7_b[i] == t7_bs[i]);
    }

    std::vector<int> t7_c;
    std::vector<int> t7_cs = {};

    t7_c = g8.shortestPath(4, 5);

    REQUIRE(t7_c.size() == 0);

}

TEST_CASE("Test Dijsktra Worthless", "[weight=1][part=3]") {
    Graph g9("./data/test_worthless.csv");

    std::vector<int> t8;

    t8 = g9.shortestPath(1, 6);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(6, 1);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(-5, 1);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(1, -5);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(-5, -5);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(20, 1);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(1, 20);
    REQUIRE(t8.size() == 0);

    t8 = g9.shortestPath(20, 20);
    REQUIRE(t8.size() == 0);
}

TEST_CASE("Test PageRank", "[weight=1][part=4]") 
{
    Graph gc("./data/test_pageRank.csv");
    float r0;
    float r1;
    float r2;
    float r3;
    r0=gc.getRanking(0);
    r1=gc.getRanking(1);
    r2=gc.getRanking(2);
    r3=gc.getRanking(3);
    REQUIRE(r0 == 2.0f);
    REQUIRE(r1 == 4.5f);
    REQUIRE(r2 == 6.0f);
    REQUIRE(r3 == 2.5f);
}

TEST_CASE("Test PageRank Disjoint", "[weight=1][part=4]") {
    Graph gc("./data/test_pagerank_sa.csv");
    REQUIRE(gc.getRanking(0) == 1.0f);
    REQUIRE(gc.getRanking(5) == 11.0f);
    REQUIRE(gc.getRanking(3) == 18.5f);
    
}

TEST_CASE("Test PageRank 0 Values", "[weight=1][part=4]") 
{
    //std::cout << "TEST PAGERANK" << std::endl;
    Graph gc("./data/test_pageRank_Lu.csv");
    float r0;
    float r1;
    float r2;
    float r3;
    float r4;
    float r5;
    float r6;
    float r7;
    r0=gc.getRanking(0);
    r1=gc.getRanking(1);
    r2=gc.getRanking(2);
    r3=gc.getRanking(3);
    r4=gc.getRanking(4);
    r5=gc.getRanking(5);
    r6=gc.getRanking(6);
    r7=gc.getRanking(7);
    REQUIRE(r0 == 0);
    REQUIRE(r1 == 4.25);
    REQUIRE(r2 == 6);
    REQUIRE(r3 == 6);
    REQUIRE(r4 == 3.5f);
    REQUIRE(r5 == 3.5);
    REQUIRE(r6 == 7);
    REQUIRE(r7 == 0);
    
    
}

TEST_CASE("Test PageRank All", "[weight=1][part=4]") {
    Graph gc("./data/test_PageRank_mtc.csv");
    std::vector<float> out = gc.getAllRanking();
    std::vector<float> sol = {5.5f, 5.0f, (49.0f/3.0f), 8.0f, 8.75f, 10.5f, 0.0f};
    REQUIRE(out.size() == sol.size());
    for(size_t i = 0; i < sol.size(); i++) {
        REQUIRE(out[i] == sol[i]);
    }
}

TEST_CASE("Test PageRank Worthless", "[weight=1][part=4]") {
    Graph gc("./data/test_PageRank_mtc.csv");
    REQUIRE(gc.getRanking(-5) == -1.0f);
    REQUIRE(gc.getRanking(100) == -1.0f);
}

