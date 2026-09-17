#ifndef __BASE_OBJECT__
#define __BASE_OBJECT__

#include "vectors.hpp"

class Renderer;

class baseObject{
protected:
    friend Renderer;
    Vec::Vector2 size;
    Vec::Vector2 position;
    Vec::Vector4 color;
    virtual void draw(Renderer&){}
    
public:
    baseObject() = default;

    baseObject& setPosition(float,float);

    baseObject& setSize(float,float);

    baseObject& setColor(float,float,float,float);

    Vec::Vector2 getPosition();
    
    Vec::Vector2 getSize();

    Vec::Vector4 getColor();

};

#endif