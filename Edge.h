#pragma once
#include "properties.h"
class Edge {
private:
    //static int _currentid;
    int _id;
    int _capacity;
    int _flow;
    int _VertexFrom;
    int _VertexTo;

public:
    Edge(int id, int capacity, int flow, int VertexFrom, int VertexTo) :_id(id), _capacity(capacity), _flow(flow), _VertexFrom(VertexFrom),
        _VertexTo(VertexTo) {}
        
    int getId()            { return this->_id;}
    int getCapacity()      { return this->_capacity; }
    int getFlow()          { return this->_flow; }
    int getVertexFrom()    { return this->_VertexFrom; }
    int getVertexTo()      { return this->_VertexTo; }
    void setFlow(int flow) { this->_flow = flow; }
    void setCapacity(int capacity) { this->_capacity = capacity; }
};
