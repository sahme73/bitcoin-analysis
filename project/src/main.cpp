#include "../include/Node.h"
#include "../include/Graph.h"

int main() {

    std::cout << "CS 225 FINAL PROJECT!" << std::endl;

    Graph g1("./data/soc-sign-bitcoinalpha.csv");

    //g1.TestPrint(10, 10);

    int counter = 0;
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
    std::vector<int> t_n; //trade network output
    g1.BasicDFS(id, visited, counter, t_n);

    for (auto node : t_n) {
        std::cout << node << " ";
    }

    if (counter <= 1)
        std::cout << std::endl << id << " has not traded with any other account!" << std::endl;
    else
        std::cout << std::endl << id << "'s trading network subgraph contains " << counter << " accounts!" << std::endl;

    return 0;

}   