#include "../include/Node.h"
#include "../include/Graph.h"

int main() {

    std::cout << "Hello World!" << std::endl;

    Node n;
    n.TestFunction(); //function to test compiler linking

    Graph g1("./data/soc-sign-bitcoinalpha.csv");
    Graph g2("./data/test.csv");
    //g.TestFunction(); //function to test compiler linking

    return -1;
}