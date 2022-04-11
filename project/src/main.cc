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

    int counter = -1;
    std::string trades = "";
    int v = 24186; //total number of vertices
    std::vector<bool> visited(v, false); //visited vector for DFS
    int id;
    
    std::cout << "Enter the ID of the user: ";
    std::cin >> id;

    while (id < 0) {
        std::cout << "Please re-enter a valid ID: ";
        std::cin >> id;
    }

    std::cout << id << "'s Trades: " << std::endl;
    g1.BasicDFS(id, visited, counter, trades);

    int id_size = std::to_string(id).size();
    trades.erase(0, id_size + 1);

    std::cout << trades;

    if (counter == 0)
        std::cout << std::endl << id << " has not traded with any other account!" << std::endl;
    else
        std::cout << std::endl << id << " traded with " << counter << " accounts!" << std::endl;

    return -1;
}