#pragma once

#include "../include/Node.h"
#include <string>

class Graph {
    public:
        Graph();
        Graph(std::string file_name);

        ~Graph();

        void TestFunction();

    //Functions:
    private:
        void BuildGraph(std::string file_name);
        void Clear();

    //Variables:
    private:
        std::vector<Node*> nodes_;
};