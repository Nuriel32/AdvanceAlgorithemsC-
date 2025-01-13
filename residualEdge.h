#pragma once

class residualEdge {
private:
    int _id;
    int _vertexFrom;
    int _vertexTo;
    int _capacity;
    int _currentFlow;
public:
    residualEdge(int id, int vertexFrom, int vertexTo, int capacity) :_id(id), _vertexFrom(vertexFrom), _vertexTo(vertexTo),
        _capacity(capacity),_currentFlow(0){}
    int getId() {return this->_id;}
    int getVertexFrom() { return this->_vertexFrom;}
    int getVertexTo() {return this->_vertexTo;}
    int getCapacity() {return this->_capacity;}
    int getCurrentFlow() { return this->_currentFlow; }
    void setCurrentFlow(int currentFlow) {  this->_currentFlow = currentFlow;}
};