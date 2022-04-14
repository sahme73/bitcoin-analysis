#pragma once

#include <iostream>
#include <vector>

class Node {
    public:
        void TestFunction();
        Node();
        void inNetwork();
        bool inTrades();

    private:
        //int source_id_;
        //std::vector< std::pair<int, int> > trades_; //target, rating
        bool inUse;

};