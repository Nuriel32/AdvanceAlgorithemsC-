#pragma once
#include "properties.h"
#include "Graph.h"
class BFS {
private:
    Graph* _graph;
    int _source;
    int _target;
    vector<int> _parents;
    vector<int> _delta;

public:
    queue<int> queue;
    BFS(Graph* graph, int source, int target):_graph(graph),_source(source), _target(target){
        this->_parents.resize(graph->getNumOfVertices());
        this->_delta.resize(graph->getNumOfVertices());
        for (int i = 0; i < graph->getNumOfVertices(); i++) {
            this->_parents[i] = -1;
            this->_delta[i] = INT_MAX;
        }
        this->_delta[source] = 0;
        this->queue.push(source);
    }
    vector<int>& getParents() {return this->_parents;}
    vector<int>& getDelta() { return this->_delta;}
    void setParents(vector<int>& parents) {  this->_parents = parents;}
    void setDelta(vector<int>& delta) {this->_delta = delta;}
    void BFS_Search() {
        while (!this->queue.empty()) {
            int u = this->queue.front();
            this->queue.pop();
            for (auto& edge : this->_graph->getAdjList()[u]) {
                if (this->_delta[edge.getVertexTo()] == INT_MAX) {
                    this->_delta[edge.getVertexTo()] = this->_delta[u] + 1;
                    this->_parents[edge.getVertexTo()] = u;
                    this->queue.push(edge.getVertexTo());
                }
            }
        }
    }
    vector<int> getShortestPath() {
        vector<int> path;
        int u = this->_target;
        while (u != this->_source) {
            path.push_back(u);
            u = this->_parents[u];
        }
        path.push_back(this->_source);
        reverse(path.begin(), path.end());
        return path;
    }
};