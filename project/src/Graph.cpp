#include "../include/Graph.h"
#include <fstream>
#include <sstream>

Graph::Graph() {
    //Empty Graph
    for (int i = 0; i < 10000; i++) {
        std::vector<int> col(10000, 0);
        adjacency_matrix_.push_back(col);
    }
}

Graph::Graph(std::string file_name) {

    //Create an empty adjacency matrix - edit later for size
    // for (int i = 0; i < 10000; i++) {
    //     std::vector<int> col(10000, 0);
    //     adjacency_matrix_.push_back(col);
    // }

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
    std::vector<int> vec_source_ids;
    std::vector<int> vec_target_ids;
    std::vector<int> vec_ratings;
    std::vector<std::string> vec_times;

    //number of lines
    size_t i = 0;
    max = 0;

    std::ifstream data(file_name);
    if (data.is_open()) {
        while (!data.eof()) {
            std::getline(data, source_id, ',');
            if (source_id == "") break; //reached last line of data
            vec_source_ids.push_back(std::stoi(source_id));
            if(std::stoi(source_id) > (int)max)
                max = std::stoi(source_id);
            std::getline(data, target_id, ',');
            if(std::stoi(target_id) > (int)max)
                max = std::stoi(target_id);
            vec_target_ids.push_back(std::stoi(target_id));
            std::getline(data, rating, ',');
            vec_ratings.push_back(std::stoi(rating));
            std::getline(data, time, '\n');
            vec_times.push_back(time);

            i++; //tracking number of lines for testing
        }
        data.close();
        max = max + 1;
        std::cout << "Number of entries: " << i << std::endl;
    } else {
        std::cout << "[WARNING] No data read!" << std::endl;
        std::cerr << "[ERROR] Unable to open file!" << std::endl;
    }
    
    BuildGraphHelper(vec_source_ids, vec_target_ids, vec_ratings, max);
}

void Graph::BuildGraphHelper(std::vector<int> source_ids,
            std::vector<int> target_ids, 
            std::vector<int> ratings, size_t max) {
    
    for (int i = 0; i < (int)max; i++) {
        std::vector<int> col(max, 0);
        adjacency_matrix_.push_back(col);
        Node* temp = new Node();
        nodes_.push_back(temp);
    }

    for (size_t i = 0; i < source_ids.size(); i++) {
        adjacency_matrix_.at(source_ids.at(i)).at(target_ids.at(i)) = ratings.at(i) + 11;
        nodes_[source_ids.at(i)]->inNetwork();
        nodes_[target_ids.at(i)]->inNetwork();

    }
}

void Graph::BasicDFS(std::vector<int>& trades) {
    std::vector<bool> visited;
    for(size_t i = 0; i < max; i++) {
        visited.push_back(false);
    }

    for(size_t i = 0; i < max; i++) {
        if(!visited[i] && nodes_[i]->inTrades()) { //make sure it is actually in a network
            int a = 0;
            BasicDFS(i, visited, a, trades);
        }
    }
}

void Graph::BasicDFS(int input, std::vector<bool>& visited, int& counter, std::vector<int>& trades) {
    trades.push_back(input);

    visited.at(input) = true;
    counter++;

    for (size_t i = 0; i < adjacency_matrix_[input].size(); i++) {
        if (adjacency_matrix_[input][i] != 0 && (!visited[i]))
            BasicDFS(i, visited, counter, trades);
    }
}

void Graph::TestPrint(int width, int height) {
    int x = width;
    int y = height;

    if (x > 10000 || y > 10000 || x < 0 || y < 0) {
        std::cerr << "[ERROR] Out of bounds!" << std::endl;
        return;
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (adjacency_matrix_.at(y).at(x) >= 10) {
                std::cout << adjacency_matrix_.at(y).at(x) << "  ";    
            } else {
                std::cout << adjacency_matrix_.at(y).at(x) << "   ";
            }
        }
        std::cout << std::endl;
    }
}

void Graph::TestFunction() {
    std::cout << "In TestFunction()!" << std::endl;
}

bool Graph::isClean() {
    for (size_t y = 0; y < adjacency_matrix_.size(); y++) {
        for (size_t x = 0; x < adjacency_matrix_.at(y).size(); x++) {
            if (adjacency_matrix_.at(y).at(x) < 0) 
                return false;
        }
    }
    return true;
}

int Graph::getRating(int source, int target) {
    return adjacency_matrix_.at(source).at(target) - 11;
}

std::vector<int> Graph::shortestPath(int start, int end) {
    vector<int> sp;
    if(!nodes_[start] -> inNetwork() || !nodes_[end] -> inNetwork()) {
        sp.push(-1);
        return sp;
    }

    std::vector<int> d;
    std::vector<int> p;
    std::vector<bool> v;

    for(size_t i = 0; i < max; i++) {
        d.push_back(INT_MAX);
        p.push_back(-1);
        v.push_back(false);
    }
    d[start] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    for(size_t i = 0; i < max; i++) {
        pq.push(std::pair<int,int>(d[i], i));
    }

    while(node(pq.top()) != end) {
        std::pair<int,int> p = pq.top();
        v[node(p)] = true;
        std::vector<int> neighbors = incVert(node(p));
        for(size_t i = 0; i < neighbors.size(); i++) {
            if(!v[neighbors[i]]) {
                
            }
        }
    }

}

int Graph::node(std::pair<int,int> p) {
    return p.second;
}

int Graph::dist(std::pair<int,int> d) {
    return p.first;
}

std::vector<int> Graph::incVert(int v) {
    std::vector<int> ans;
    for(size_t i = 0; i < max; i++) {
        if(adjacency_matrix_.at(v).at(i) != 0) {
            ans.push_back(i);
        }
    }
    return ans;
}