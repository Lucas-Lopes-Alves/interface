#include "elements/baseObject.hpp"

// Setters
BaseObject& BaseObject::setPosition(float x, float y){
    position.x = x;
    position.y = y;
    return *this;
}

BaseObject& BaseObject::setSize(float x, float y){
    size.x = x;
    size.y = y;
    return *this;
}

// Getters
Vec::Vector2 BaseObject::getPosition(){
    return position;
}

Vec::Vector2 BaseObject::getSize(){
    return size;
}

void BaseObject::clicked(){}