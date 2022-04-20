#pragma once

#include "../include/Node.h"
#include <string>

class Graph {
    public:
        Graph();
        Graph(std::string file_name);

        ~Graph();

        void TestPrint(int width, int height);
        void BasicDFS(std::vector<int>& trades);
        void BasicDFS(int input, std::vector<bool>& visited, int& count, std::vector<int>& trades);
        bool isClean();
        int getRating(int source, int target);

        std::vector<int> shortestPath(int start, int end);
        std::vector<int> incVert(int v);

        void TestFunction();

        float getRanking(int v);
        std::vector<float> getAllRanking();

    //Functions:
    private:
        void BuildGraph(std::string file_name);
        void BuildGraphHelper(std::vector<int> source_ids,
            std::vector<int> target_ids, 
            std::vector<int> ratings, size_t max);
        void Clear();

    //Variables:
    private:
        std::vector<Node*> nodes_;
        std::vector<std::vector<int>> adjacency_matrix_;
        size_t max;
        int node(std::pair<int, int> p);
        int dist(std::pair<int, int> p);
};