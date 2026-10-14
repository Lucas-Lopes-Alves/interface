#ifndef BUTTON__
#define BUTTON__

#include "elements/baseObject.hpp"
#include "style/style.hpp"
#include <vector>

class Button : public Element<Button>{
    void clicked() override;
    std::vector<void(*)()> callbacks;
    Style style;
public:
    Button();
    void connect(void (*func)());
    
    Button* setColor(float,float,float,float);

    Button* setBorderSize(float);

    Button* setBorderColor(float,float,float,float);

    Button* setVisibility(bool);

    bool getVisibility();
    
    Style getStyle() const override;
};

#endif