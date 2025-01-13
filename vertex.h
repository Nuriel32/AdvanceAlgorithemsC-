#pragma once
#include "properties.h"
class vertex {
private:
    int _id;

    int _parent;
    int _delta=0;
public:
    vertex() {}
    vertex(int id) :_id(id), _parent(-1) {}
    int getId() { return this->_id; }
    int getParent() {return this->_parent;}
    int getDelta() { return this->_delta; }
    void setParent(int parent) {  this->_parent = parent;}
    void setDelta(int delta) {this->_delta = delta;}
};


