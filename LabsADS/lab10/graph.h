#pragma once
#include <vector>
using std::vector;
class Graph
{
private:
    int size;
    int vCount;
    int** arrGraph;
    int minDist(int* distance, bool* sptS);
public:
    Graph();
    Graph(int s);
    ~Graph();

    int getCount();
    void addEdge(int v1, int v2, int weight);
    void removeEdge(int v1, int v2);
    int dijkstra(int from, int to);
    
    void print(int* g) const;
    
};

