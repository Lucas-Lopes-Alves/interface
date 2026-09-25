#include "elements/baseObject.hpp"

// Setters
baseObject& baseObject::setPosition(float x, float y){
    position.x = x;
    position.y = y;
    return *this;
}

baseObject& baseObject::setSize(float x, float y){
    size.x = x;
    size.y = y;
    return *this;
}

baseObject& baseObject::setColor(float x,float y,float z,float a){
    color.x = x;
    color.y = y;
    color.z = z;
    color.a = a;
    return *this;
}

// Getters
Vec::Vector2 baseObject::getPosition(){
    return position;
}

Vec::Vector2 baseObject::getSize(){
    return size;
}

Vec::Vector4 baseObject::getColor(){
    return color;
}

void baseObject::clicked(){}