#pragma once

#include "glad/gl.h"
#include <cstddef>

GLuint createVBO(const void* vertices, std::size_t size);

GLuint createVAO(int location = 0, int quantity = 0, int size = 0, std::size_t start =0);

GLuint createVertexShader(const char*& source, std::size_t count);

GLuint createFragmentShader(const char*& source, std::size_t count);
