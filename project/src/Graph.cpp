#include "../include/Graph.h"
#include <fstream>
#include <sstream>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

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
        //std::cout << "Number of entries: " << i << std::endl;
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
    if(input >= (int)max || input < 0 || !(nodes_[input] -> inTrades()))
        return;
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

    int max_as_int = (int)max;
    if (start < 0 || start > max_as_int || end < 0 || end > max_as_int) {
        return std::vector<int>();
    }

    if(start == end) {
        std::vector<int> one;
        one.push_back(start);
        return one;
    }

    std::vector<int> sp;
    if(!(nodes_[start] -> inTrades()) || !(nodes_[end] -> inTrades())) {
        return sp;
    }

    std::vector<int> d;
    std::vector<int> p;
    std::vector<bool> v;

    for(size_t i = 0; i < max; i++) {
        d.push_back(__INT_MAX__);
        p.push_back(-1);
        v.push_back(false);
    }
    d[start] = 0;
    p[start] = start;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>> , std::greater<std::pair<int, int>>> pq;
    pq.push(std::pair<int,int>(0,start));

    while(!pq.empty()) {
        std::pair<int,int> pa = pq.top();
        pq.pop();
        v[node(pa)] = true;
        std::vector<int> neighbors = incVert(node(pa));
        for(size_t i = 0; i < neighbors.size(); i++) {
            if(d[neighbors[i]] > dist(pa) + adjacency_matrix_.at(node(pa)).at(neighbors[i])) {
                d[neighbors[i]] = dist(pa) + adjacency_matrix_.at(node(pa)).at(neighbors[i]);
                p[neighbors[i]] = node(pa);
            }
            if(!v[neighbors[i]]) {
                pq.push(std::pair<int, int>(dist(pa) + adjacency_matrix_.at(node(pa)).at(neighbors[i]), neighbors[i]));
            }
        }
    }

    if(d[end] == __INT_MAX__) {
        return sp;
    }

    std::vector<int> backward;
    int loc = end;
    while(loc != start) {
        backward.push_back(loc);
        loc = p[loc];
    }

    sp.push_back(start);
    for(int i = (int)backward.size() - 1; i >= 0; i--) {
        sp.push_back(backward[i]);
    }

    return sp;

}

int Graph::node(std::pair<int,int> p) {
    return p.second;
}

int Graph::dist(std::pair<int,int> p) {
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

float Graph::getRanking(int v) {
    float num = 0;
    float denom = 0;

    if(v < 0 || v >= (int)max) {
        return -1.0f;
    }

    for(size_t i = 0; i < adjacency_matrix_.size(); i++) {
        int rate = adjacency_matrix_.at(i).at(v);
        if(rate != 0) {
            num += (float)rate;
            denom ++;
        }
    }
    if(denom == 0.0f) {
        return 0.0f;
    }
    return num / denom;
}

std::vector<float> Graph::getAllRanking() {
    std::vector<float> vf;
    for(size_t i = 0; i < max; i++) {
        if(nodes_[i]->inTrades()) {
            vf.push_back(getRanking(i));
        } else{
            vf.push_back(-1);
        }
    }
    return vf;
}