#ifndef BUTTON__
#define BUTTON__

#include "elements/baseObject.hpp"
#include <vector>

class Button : public BaseObject{
    void clicked() override;
    std::vector<void(*)()> callbacks;
public:
    Button();
    void connect(void (*func)());
};

#endif