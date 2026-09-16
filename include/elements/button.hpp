#include "vectors.hpp"

class baseButton{
    float vertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };
    Vec::Vector2 size;
    Vec::Vector2 position;
public: 
    baseButton();

    void setPosition(Vec::Vector2);

    void setSize(Vec::Vector2);
};