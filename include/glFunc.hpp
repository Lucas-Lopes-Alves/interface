#pragma once

#include "glad/gl.h"
#include <cstddef>

GLuint createVBO(const void* vertices, std::size_t size);

GLuint createVAO();

GLuint createVertexShader(const char*& source, std::size_t count);

GLuint createFragmentShader(const char*& source, std::size_t count);
