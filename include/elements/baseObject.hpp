#ifndef BASE_OBJECT__
#define BASE_OBJECT__

#include "style/style.hpp"
#include "vectors.hpp"

class BaseObject{
protected:
    friend class Renderer;
    Vec::Vector2 size;
    Vec::Vector2 position;
    
public:
    BaseObject() = default;
    virtual ~BaseObject() = default;

    BaseObject(const BaseObject&) = delete;
    BaseObject& operator=(const BaseObject&) = delete;
    
    BaseObject& setPosition(float,float);

    BaseObject& setSize(float,float);

    Vec::Vector2 getPosition();
    
    Vec::Vector2 getSize();

    virtual Style getStyle() const = 0;
    
    virtual void clicked() = 0;
};

template <typename Class_name>
class Element : public BaseObject{
public:
    Class_name& setPosition(float x,float y){
        BaseObject::setPosition(x, y);
        return static_cast<Class_name&>(*this);
    }
    
    Class_name& setSize(float x,float y){
        BaseObject::setSize(x, y);
        return static_cast<Class_name&>(*this);
    }
};

#endif