#pragma once
#include "properties.h"
#include "Graph.h"
#include "BFS.h"
class Ford_Fulkerson {
private:
    Graph* _graph;
    int _source;
    int _target;

public:
    Ford_Fulkerson(Graph* graph, int source, int target) :_graph(graph), _source(source), _target(target) {}
    int Ford_Fulkerson_Algorithm() {
        int flow = 0;
        while (true) {
            BFS bfs(this->_graph, this->_source, this->_target);
            bfs.BFS_Search();
            vector<int> path = bfs.getShortestPath();
            if (path.empty()) {
                break;
            }
            int minCapacity = INT_MAX;
            for (int i = 0; i < path.size() - 1; i++) {
                for (auto edge : this->_graph->getAdjList()[path[i]]) {
                    if (edge.getVertexTo() == path[i + 1]) {
                        minCapacity = min(minCapacity, edge.getCapacity());
                    }
                }
            }
            flow += minCapacity;
            for (int i = 0; i < path.size() - 1; i++) {
                for (auto edge : this->_graph->getAdjList()[path[i]]) {
                    if (edge.getVertexTo() == path[i + 1]) {
                        edge.setCapacity(edge.getCapacity() - minCapacity);
                        this->_graph->RemoveEdge(edge.getId());
                        this->_graph->AddEdge(edge.getId(), edge.getVertexFrom(), edge.getVertexTo(), edge.getCapacity());
                        break;
                    }
                }
            }
        }
        return flow;
    }
};