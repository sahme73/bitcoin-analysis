#include "../include/Node.h"
#include "../include/Graph.h"

void DFSCall(Graph& g1) {
    int counter = 0;
    int v = 24186; //total number of vertices
    std::vector<bool> visited(v, false); //visited vector for DFS
    int id;
    
    std::cout << "Enter the ID of the user: ";
    std::cin >> id;

    while (id < 0) {
        std::cout << "Please re-enter a valid user ID: ";
        std::cin >> id;
    }

    std::cout << id << "'s Trading Network Subgraph: " << std::endl;
    std::vector<int> t_n; //trade network output
    g1.BasicDFS(id, visited, counter, t_n);

    for (auto node : t_n) {
        std::cout << node << " ";
    }

    if (counter <= 1)
        std::cout << std::endl << id << " has not traded with any other account!" << std::endl;
    else
        std::cout << std::endl << id << "'s trading network subgraph contains " << counter << " accounts!" << std::endl;
}

void TerminalHelper1(unsigned int skips) {
    unsigned int lines_to_skip = skips;
    for (unsigned int i = 0; i < lines_to_skip; i++) {
        std::cout << std::endl;
    }
}

void ShortestPathCall(Graph& g1) {
    std::vector<int> output;
    int source;
    int target;
    
    std::cout << "Enter the ID of the user (source user): ";
    std::cin >> source;
    while (source < 0) {
        std::cout << "Please re-enter a valid user ID (source user): ";
        std::cin >> source;
    }

    std::cout << "Enter the ID of the user (target user): ";
    std::cin >> target;
    while (target < 0) {
        std::cout << "Please re-enter a valid user ID (target user): ";
        std::cin >> target;
    }

    std::cout << std::endl << "Please wait!" << std::endl << std::endl << "Loading..." << std::endl << std::endl;
    output = g1.shortestPath(source, target);
    if (output.size() != 0) {
        std::cout << "The path between " << source << " and " << target << ":" << std::endl;
        for (auto e : output) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "There is no valid path between " << source << " and " << target << "!" << std::endl;
    }
}

void PageRankSingleCall(Graph& g1) {
    int id;
    
    std::cout << "Enter the ID of the user: ";
    std::cin >> id;

    while (id < 0) {
        std::cout << "Please re-enter a valid user ID: ";
        std::cin >> id;
    }

    std::cout << id << "'s PageRank Value is: " << g1.getRanking(id) << "!" << std::endl;
}

void PageRankAllCall(Graph& g1) {
    std::vector<float> output = g1.getAllRanking();

    std::cout << "The following is the PageRank of every user:" << std::endl;

    //float min = 100.0f;
    //size_t min_idx = 0;
    //float max = 0.0f;
    //size_t max_idx = 0;

    std::vector<int> highest;
    std::vector<int> lowest;

    for (size_t i = 0; i < output.size(); i++) {
        if (output.at(i) != -1) {

            // if (output.at(i) < min && output.at(i) != 0.0f) {
            //     min = output.at(i);
            //     min_idx = i;
            // }

            // if (output.at(i) > max) {
            //     max = output.at(i);
            //     max_idx = i;
            // }

            if(output.at(i) == 21) 
                highest.push_back(i);

            if(output.at(i) == 1)
                lowest.push_back(i);

            std::cout << "(" << i << ": " << output.at(i) << ") ";
        }
    }
    TerminalHelper1(2);

    std::cout << "Users with the highest rating: ";
    for(size_t i = 0; i < highest.size(); i++) {
        std::cout << highest[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Users with the lowest rating: ";
    for(size_t i = 0; i < lowest.size(); i++) {
        std::cout << lowest[i] << " ";
    }
    std::cout << std::endl;

    // std::cout << max_idx << " has the highest PageRanking of " << max << std::endl;
    // std::cout << min_idx << " has the lowest PageRanking of "<< min << std::endl;
}

int main() {

    std::cout << "CS 225 FINAL PROJECT!" << std::endl;

    Graph g1("./data/soc-sign-bitcoinalpha.csv");

    bool continue_flag = true;

    do {

        unsigned int input1; //1: DFS | 2: Shortest Path | 3: PageRank Single | 4: PageRank All
        do {
            std::cout << "1: DFS | 2: Shortest Path | 3: PageRank Single | 4: PageRank All" << std::endl;
            std::cout << "Enter desired algorithm: ";
            std::cin >> input1;
        } while (input1 != 1 && input1 != 2 && input1 != 3 && input1 != 4);

        TerminalHelper1(20);

        if (input1 == 1) {
            std::cout << "DFS Algorithm" << std::endl;
            DFSCall(g1);
        } else if (input1 == 2) {
            std::cout << "Shortest Path Algorithm" << std::endl;
            ShortestPathCall(g1);
        } else if (input1 == 3) {
            std::cout << "PageRank Single" << std::endl;
            PageRankSingleCall(g1);
        } else if (input1 == 4) {
            std::cout << "PageRank All" << std::endl;
            PageRankAllCall(g1);
        }

        TerminalHelper1(1);
        char input2;
        do {
            std::cout << "Would you like to continue? (Y/N): ";
            std::cin >> input2;
        } while (input2 != 'Y' && input2 != 'N');

        if (input2 == 'N')
            continue_flag = false;
        else
            TerminalHelper1(20);

    } while (continue_flag);

    return 0;

}   