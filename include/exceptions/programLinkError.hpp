#ifndef GLPROGRAM_LINK_ERROR__
#define GLPROGRAM_LINK_ERROR__

#include <exception>
#include <string>

class glProgram_link_error: public std::exception{
    std::string log;
public:
    explicit glProgram_link_error(const char * errorLog): log(errorLog){
        
    }
    
    virtual const char* what() const noexcept override{
        return log.c_str();
    }
};

#endif