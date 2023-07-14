#include <iostream>
#include "graph.h"
#include <stack>
#define MAX 1000
using namespace std;

Graph::Graph() : size(1), vCount(0) {
    arrGraph = new int* [size];
    for (int i = 0; i < size; i++) {
        arrGraph[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arrGraph[i][j] = 0;
        }
    }
}
Graph::Graph(int s) : size(s), vCount(0) {
    arrGraph = new int* [size];
    for (int i = 0; i < size; i++) {
        arrGraph[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arrGraph[i][j] = 0;
        }
    }
}
Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete[] arrGraph[i];
    }
    delete[] arrGraph;
}

int Graph::getCount() {
    return vCount;
}
int Graph::minDist(int* distance, bool* sptS) {
    int max = MAX, index = 0;
    for (int i = 0; i < size; i++) {
        if (sptS[i] == false && distance[i] <= max) {
            max = distance[i];
            index = i;
        }
    }
    return index;
}
void Graph::addEdge(int v1, int v2, int weight) {
    if (v1 == v2 || v1 >= size || v2 >= size || arrGraph[v1][v2] != 0) {
        throw "ERROR.";
    }
    arrGraph[v1][v2] = weight;
    arrGraph[v2][v1] = weight;
    ++vCount;
}
void Graph::removeEdge(int v1, int v2) {
    if (v1 == v2 || v1 >= size || v2 >= size) {
        throw "ERROR.";
    }
    arrGraph[v1][v2] = 0;
    arrGraph[v2][v1] = 0;
    --vCount;
}


int Graph::dijkstra(int from, int to)
{
    if (from >= size || to >= size) {
        throw "ERROR.";
    }
    int* distance = new int[size];
    int* parent = new int[size];
    bool* sptSet = new bool[size];
    for (int i = 0; i < size; i++) {
        distance[i] = MAX;
        sptSet[i] = false;
    }
    distance[from] = 0;
    parent[from] = -1;
    for (int count = 0; count < size - 1; count++) {
        int minD = minDist(distance, sptSet);
        sptSet[minD] = true;
        for (int i = 0; i < size; ++i) {
            if (!sptSet[i] && arrGraph[minD][i] != 0 && distance[minD] != MAX && distance[minD] + arrGraph[minD][i] < distance[i]) {
                distance[i] = distance[minD] + arrGraph[minD][i];
                parent[i] = minD;
            }
        }
    }
    if (distance[to] == MAX) {
        cout << "No path found from " << from << " to " << to << '\n';
        return -1;
    }
    else {
        cout << "Shortest path from " << from << " to " << to << ": ";
        int v = to;
        stack<int> path;
        while (v != -1) {
            path.push(v);
            v = parent[v];
        }
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << "with distance " << distance[to] << '\n';
    }

  
    print(distance);
    return distance[to];
}

void Graph::print(int* g) const {
    cout << "Vertex  Distance" << endl;
    for (int i = 0; i < size; i++) {
        cout << "#" << i  << "\t" << g[i] << endl;
    }
    cout << "\n";
}


