#ifndef API_H
#define API_H
#include "xReference.h"
#include "enumValues.h"
#include "xCliente.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "cstdlib"


class API {
    
private:    
    const char* token;
    const char* Host;
    const char* Port;
    xReference<int> xIntR;
    xReference<char> xIntC;
    xReference<double> xIntD;
    const std::string _host;
    const std::string _port;
    

public:
    API();
    
    //char* init(strin)
    char* initialize(const std::string host, const std::string port, const std::string message);
        
    void xAssing(xReference<int>* reference, void* value);
    template<typename T>
    void xFree(xReference<T> toFree);
        
    void* xMalloc(int size, enumValue::xType type, const std::string message);
    void* xMalloc(int size, enumValue::xType type, void* value, const std::string message);
       
    
    virtual ~API();
};

#endif /* API_H */

