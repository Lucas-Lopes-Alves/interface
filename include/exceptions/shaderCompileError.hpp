#ifndef SHADER_COMPILER_ERROR__
#define SHADER_COMPILER_ERROR__

#include <exception>
#include <iostream>

class shader_compile_error: public std::exception{
    const char* message;
    const char* log;
public:
    explicit shader_compile_error(const char* msg,const char * errorLog): message(msg), log(errorLog){}
    
    virtual const char* what() const noexcept override{
        std::cerr << log;
        return message;
    }
};

#endif