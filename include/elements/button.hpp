#ifndef BUTTON__
#define BUTTON__

#include "elements/baseObject.hpp"
#include "style/style.hpp"
#include "vectors.hpp"
#include <vector>

class Button : public BaseObject{
    void clicked() override;
    std::vector<void(*)()> callbacks;
    Style style;
public:
    Button();
    void connect(void (*func)());
    
    Button& setColor(float,float,float,float);
    Vec::Vector4 getColor();
};

#endif