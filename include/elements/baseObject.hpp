#ifndef _BASE_OBJECT_
#define _BASE_OBJECT_

#include "vectors.hpp"
#include "wrapper.hpp"

class baseObject{
protected:
    Vec::Vector2 size;
    Vec::Vector2 position;
    Vec::Vector4 color;
    
public:
    baseObject() = default;

    baseObject& setPosition(float,float);

    baseObject& setSize(float,float);

    baseObject& setColor(float,float,float,float);

    Vec::Vector2 getPosition();
    
    Vec::Vector2 getSize();

    Vec::Vector4 getColor();

    virtual void draw(Window& target, unsigned int VBO);
};

#endif