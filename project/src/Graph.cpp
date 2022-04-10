#include "../include/Graph.h"
#include <fstream>

Graph::Graph() {
    //Empty Graph
}

Graph::Graph(std::string file_name) {
    BuildGraph(file_name);
}

Graph::~Graph() {
    Clear();
}

void Graph::Clear() {
    for (size_t i = 0; i < nodes_.size(); i++) {
        delete nodes_.at(i);
    }
}

void Graph::BuildGraph(std::string file_name) {
    std::string file = "../data/" + file_name;
    std::ifstream data(file.c_str());
}

void Graph::TestFunction() {
    std::cout << "In TestFunction()!" << std::endl;
}