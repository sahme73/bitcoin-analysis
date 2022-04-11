#pragma once

#include "../include/Node.h"
#include <string>

class Graph {
    public:
        Graph();
        Graph(std::string file_name);

        ~Graph();

        void TestPrint(int width, int height);
        void BasicDFS(int input, std::vector<bool>& visited, int& count, std::string& trades);

        void TestFunction();

    //Functions:
    private:
        void BuildGraph(std::string file_name);
        void BuildGraphHelper(std::vector<int> source_ids,
            std::vector<int> target_ids, 
            std::vector<int> ratings);
        void Clear();

    //Variables:
    private:
        std::vector<Node*> nodes_;
        std::vector<std::vector<int>> adjacency_matrix_;
};