#pragma once

#include "glad/gl.h"
#include "glFunc.hpp"
#include "wrapper.hpp"
#include <vector>

class App{
    std::vector<Window> windows;
    
    App();

    App(const App&) = delete;
    App(const App&&) = delete;
    App& operator=(App&) = delete;
    App& operator=(App&&) = delete;

    
};