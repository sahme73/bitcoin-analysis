#include "../include/Graph.h"
#include <fstream>
#include <sstream>

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
    std::string source_id, target_id, rating, time; //variables
    std::vector<std::string> vec_source_id;
    std::vector<std::string> vec_target_id;
    std::vector<std::string> vec_rating;
    std::vector<std::string> vec_time;

    //number of lines
    size_t i = 0;

    std::ifstream data(file_name);
    if (data.is_open()) {
        while (!data.eof()) {
            std::getline(data, source_id, ',');
            vec_source_id.push_back(source_id);
            std::getline(data, target_id, ',');
            vec_target_id.push_back(target_id);
            std::getline(data, rating, ',');
            vec_rating.push_back(rating);
            std::getline(data, time, '\n');
            vec_time.push_back(time);

            i++; //tracking number of lines for testing
        }
        data.close();
        std::cout << "Number of entries: " << i << std::endl;
    } else {
        std::cout << "[ERROR] Unable to open file!" << std::endl;
    }
    
}

void Graph::TestFunction() {
    std::cout << "In TestFunction()!" << std::endl;
}