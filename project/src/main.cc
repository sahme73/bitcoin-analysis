#include "../include/Node.h"
#include "../include/Graph.h"

int main() {

    // std::cout << "CS 225 FINAL PROJECT!" << std::endl;

    // //Node n;
    // //n.TestFunction(); //function to test compiler linking

    // Graph g1("./data/soc-sign-bitcoinalpha.csv");
    // //Graph g2("./data/test.csv");
    // //g.TestFunction(); //function to test compiler linking

    // g1.TestPrint(20, 10);

    // int counter = 0;
    // std::string trade_network = "";
    // int v = 24186; //total number of vertices
    // std::vector<bool> visited(v, false); //visited vector for DFS
    // int id;
    
    // std::cout << "Enter the ID of the user: ";
    // std::cin >> id;

    // while (id < 0) {
    //     std::cout << "Please re-enter a valid ID: ";
    //     std::cin >> id;
    // }

    // std::cout << id << "'s Trading Network Subgraph: " << std::endl;
    // std::vector<int> t_n;
    // g1.BasicDFS(id, visited, counter, t_n);

    // std::cout << trade_network;

    // if (counter <= 1)
    //     std::cout << std::endl << id << " has not traded with any other account!" << std::endl;
    // else
    //     std::cout << std::endl << id << "'s trading network subgraph contains " << counter << " accounts!" << std::endl;

    // return -1;
    bool passed = true;
    bool allPassed = true;

    std::cout << "TEST CLEAN" << std::endl;
    Graph gc("./data/test_cleaning.csv");
    passed = gc.isClean();
    if(passed) {
        std::cout << "CLEAN TEST PASSED" << std::endl;
    } else {
        std::cout << "CLEAN TEST FAILED" << std::endl;
    }
    allPassed = passed && allPassed;
    passed = true;

    std::cout << "TEST ADJACENCY MATRIX" << std::endl;
    
    int r;
    r = gc.getRating(0,1);
    passed = passed && r == -4;
    r = gc.getRating(0,5);
    passed = passed && r == -10;
    r = gc.getRating(1,4);
    passed = passed && r == 3;
    r = gc.getRating(1,2);
    passed = passed && r == 0;
    r = gc.getRating(2,3);
    passed = passed && r == 4;

    if(passed) {
        std::cout << "MATRIX TEST PASSED" << std::endl;
    } else {
        std::cout << "MATRIX TEST FAILED" << std::endl;
    }

    allPassed = passed && allPassed;
    passed = true;


    std::cout << "BASIC TEST" << std::endl;
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
        passed = passed && t1[i] == t1s[i];
    }
    if(passed) {
        std::cout << "Basic Test PASSED." << std::endl;
    } else {
        std::cout << "Basic Test FAILED." << std::endl;
    }

    allPassed = passed && allPassed;
    passed = true;

    std::cout << "CYCLE TEST" << std::endl;
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
        passed = passed && t2[i] == t2s[i];
    }
    if(passed) {
        std::cout << "Cycle Test PASSED." << std::endl;
    } else {
        std::cout << "Cycle Test FAILED." << std::endl;
    }

    allPassed = passed && allPassed;
    passed = true;

    std::cout << "DISJOINT TEST" << std::endl;
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
        passed = passed && t3[i] == t3s[i];
    }
    if(passed) {
        std::cout << "Disjoint Test PASSED." << std::endl;
    } else {
        std::cout << "Disjoint Test FAILED." << std::endl;
    }

    allPassed = passed && allPassed;
    passed = true;

    std::cout << "WORTHLESS TEST" << std::endl;
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
        passed = passed && t4[i] == t4s[i];
    }
    if(passed) {
        std::cout << "Worthless Test PASSED." << std::endl;
    } else {
        std::cout << "Worthless Test FAILED." << std::endl;
    }

    allPassed = passed && allPassed;
    passed = true;

    if(allPassed) {
        std::cout << "All tests passed. Congratulations!" << std::endl;
    }

    return 0;
}   