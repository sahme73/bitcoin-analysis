#include "../include/Node.h"
#include "../include/Graph.h"

int main() {

    std::cout << "Hello World!" << std::endl;

    Node n;
    n.TestFunction();

    Graph g("soc-sign-bitcoinalpha.csv");
    g.TestFunction();

    return -1;
}