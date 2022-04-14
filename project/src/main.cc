#include "../include/Node.h"
#include "../include/Graph.h"

int main() {

    std::cout << "CS 225 FINAL PROJECT!" << std::endl;

    //Node n;
    //n.TestFunction(); //function to test compiler linking

    Graph g1("./data/soc-sign-bitcoinalpha.csv");
    //Graph g2("./data/test.csv");
    //g.TestFunction(); //function to test compiler linking

    g1.TestPrint(20, 10);

    int counter = 0;
    std::string trade_network = "";
    int v = 24186; //total number of vertices
    std::vector<bool> visited(v, false); //visited vector for DFS
    int id;
    
    std::cout << "Enter the ID of the user: ";
    std::cin >> id;

    while (id < 0) {
        std::cout << "Please re-enter a valid ID: ";
        std::cin >> id;
    }

    std::cout << id << "'s Trading Network Subgraph: " << std::endl;
    std::vector<int> t_n;
    g1.BasicDFS(id, visited, counter, t_n);

    std::cout << trade_network;

    if (counter <= 1)
        std::cout << std::endl << id << " has not traded with any other account!" << std::endl;
    else
        std::cout << std::endl << id << "'s trading network subgraph contains " << counter << " accounts!" << std::endl;

    return -1;
}