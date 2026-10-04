#ifndef BASE_OBJECT__
#define BASE_OBJECT__

#include "vectors.hpp"

class BaseObject{
protected:
    friend class Renderer;
    Vec::Vector2 size;
    Vec::Vector2 position;
    Vec::Vector4 color;
    
public:
    BaseObject() = default;
    virtual ~BaseObject() = default;

    BaseObject& setPosition(float,float);

    BaseObject& setSize(float,float);

    BaseObject& setColor(float,float,float,float);

    Vec::Vector2 getPosition();
    
    Vec::Vector2 getSize();

    Vec::Vector4 getColor();

    virtual void clicked();
};

#endif