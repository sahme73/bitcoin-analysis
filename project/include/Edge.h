

class Edge {
    public:
        Edge(int s, int t, int r, int ti);
        int getTarget() const;
        int getSource() const;
        int getRating() const;
        int getTime() const;
    private:
        int source;
        int target;
        int rating;
        int time;
}; 