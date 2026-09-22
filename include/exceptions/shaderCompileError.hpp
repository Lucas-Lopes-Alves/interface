#ifndef SHADER_COMPILER_ERROR__
#define SHADER_COMPILER_ERROR__

#include <exception>
#include <iostream>
#include <string>

class shader_compile_error: public std::exception{
    std::string log;
public:
    explicit shader_compile_error(const char * errorLog): log(errorLog){
        
    }
    
    virtual const char* what() const noexcept override{
        std::cerr << log;
        return log.c_str();
    }
};

#endif