#ifndef BASE_OBJECT__
#define BASE_OBJECT__

#include "vectors.hpp"

class baseObject{
protected:
    friend class Renderer;
    Vec::Vector2 size;
    Vec::Vector2 position;
    Vec::Vector4 color;
    
public:
    baseObject() = default;
    virtual ~baseObject() = default;

    baseObject& setPosition(float,float);

    baseObject& setSize(float,float);

    baseObject& setColor(float,float,float,float);

    Vec::Vector2 getPosition();
    
    Vec::Vector2 getSize();

    Vec::Vector4 getColor();

};

#endif