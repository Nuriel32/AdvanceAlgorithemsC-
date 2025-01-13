#pragma once
#include "properties.h"
class Graph {
private:
    int _numOfVertices;
    int _numOfEdges;
    vector<vertex> _vertices;
    vector<Edge> _edges;
    vector<vector<Edge>> _adjList;
    vector<vector<residualEdge>> _residualAdjList;
public:
    Graph(int numOfVertices):_numOfVertices(numOfVertices),_numOfEdges(0)
    {
        this->_vertices.resize(numOfVertices);
        this->_adjList.resize(numOfVertices);
        this->_residualAdjList.resize(numOfVertices);
    }
    void addEdge(int capacity, int VertexFrom, int VertexTo);
    void AddEdge(int id, int capacity, int VertexFrom, int VertexTo);

    void makeResidualGraph();
    void printGraph();

    void printResidualGraph();

    void printEdges();
    int getNumOfVertices();
    int getNumOfEdges();
    vector<vertex>& getVertices();
    vector<Edge>& getEdges();
    vector<vector<Edge>>& getAdjList();
    void RemoveEdge(int id);




};