#include "../include/Edge.h"

Edge::Edge(int s, int t, int r, int ti) {
    source = s;
    target = t;
    rating = r;
    time = ti;
}

int Edge::getSource() const {
    return source;
}

int Edge::getTarget() const {
    return target;
}

int Edge::getRating() const {
    return rating;
}

int Edge::getTime() const {
    return time;
}