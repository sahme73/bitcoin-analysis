#include "../include/Node.h"

Node::Node() {
    inUse = false;
}

void Node::TestFunction() {
    std::cout << "In TestFunction()!" << std::endl;
}

void Node::inNetwork() {
    inUse = true;
}

bool Node::inTrades() {
    return inUse;
}
