#pragma once
#include "properties.h"
#include "Graph.h"
void Graph::addEdge(int capacity, int VertexFrom, int VertexTo) {
    Edge edge(this->_numOfEdges, capacity, 0, VertexFrom, VertexTo);
    this->_edges.push_back(edge);
    this->_adjList[VertexFrom].push_back(edge);
    this->_residualAdjList[VertexFrom].push_back(residualEdge(this->_numOfEdges, VertexFrom, VertexTo, capacity));
    this->_numOfEdges++;
}

void Graph::AddEdge(int id, int capacity, int VertexFrom, int VertexTo) {
    Edge edge(id, capacity, 0, VertexFrom, VertexTo);
    this->_edges.push_back(edge);
    this->_adjList[VertexFrom].push_back(edge);
    this->_residualAdjList[VertexFrom].push_back(residualEdge(id, VertexFrom, VertexTo, capacity));
    this->_residualAdjList[VertexTo].push_back(residualEdge(id, VertexTo, VertexFrom, 0));
    this->_numOfEdges++;
}

void Graph::makeResidualGraph() {
    for (int i = 0; i < this->_numOfVertices; i++) {
        for (auto edge : this->_adjList[i]) {
            this->_residualAdjList[edge.getVertexFrom()].push_back(residualEdge(edge.getId(), edge.getVertexFrom(), edge.getVertexTo(), edge.getCapacity()));
            this->_residualAdjList[edge.getVertexTo()].push_back(residualEdge(edge.getId(), edge.getVertexTo(), edge.getVertexFrom(), 0));
        }
    }
}
void Graph::printGraph() {
    for (int i = 0; i < this->_numOfVertices; i++) {
        cout << "Vertex " << i << ": ";
        for (auto edge : this->_adjList[i]) {
            cout << edge.getVertexTo() << " ";
        }
        cout << endl;
    }
}

void Graph::printResidualGraph() {
    for (int i = 0; i < this->_numOfVertices; i++) {
        cout << "Vertex " << i << ": ";
        for (auto edge : this->_residualAdjList[i]) {
            cout << edge.getVertexTo() << " ";
        }
        cout << endl;
    }
}

void Graph::printEdges() {
    for (auto edge : this->_edges) {
        cout << "Edge " << edge.getId() << ": " << edge.getVertexFrom() << " " << edge.getVertexTo() << " " << edge.getCapacity() << endl;
    }
}

int Graph::getNumOfVertices() {
    return this->_numOfVertices;
}
int Graph::getNumOfEdges() {
    return this->_numOfEdges;
}
vector<vertex>& Graph::getVertices() {
    return this->_vertices;
}
vector<Edge>& Graph::getEdges() {
    return this->_edges;
}
vector<vector<Edge>>& Graph::getAdjList() {
    return this->_adjList;
}

void Graph::RemoveEdge(int id) {
    for (int i = 0; i < this->_numOfVertices; i++) 
    {
        for (int j = 0; j < _adjList[i].size();j++) {
            if (_adjList[i][j].getId() == id) {
                _adjList[i].erase(_adjList[i].begin() + j);
                //this->_residualAdjList[i].remove(residualEdge(id, edge.getVertexFrom(), edge.getVertexTo(), 0));//?
               // this->_residualAdjList[i].remove(residualEdge(id, edge.getVertexTo(), edge.getVertexFrom(), 0));///?
                this->_numOfEdges--;
                return;
            }
        }
       

    }
}


