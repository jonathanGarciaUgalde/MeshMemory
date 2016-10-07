#include <stddef.h>

#include "API.h"

/*
 * Metodo constructor de la clase API
 */
API::API() {
    
}


/*
 *  Se encarga de solicitar un token a Mesh Mem Manager 
 *  para identificar al cliente
 */
char* API::initialize(const std::string host, const std::string port, const std::string message) {
    xCliente* cliente = new xCliente();
    string action = "Iniciar";    
    //this->_port = port;
    //cliente->run(action, message);
    //solicitar a mesh men manager un token
    //host: IP de Mesh Men manager
    //port: Puerto al que se conectara
    //this->token = valor del token regresado por MMM    
}

/*
 * Se comunica con el Mesh Mem Manager para solicitar un espacio
 * y especificar el tipo a almacenar. Retorna una instancia de xReference. 
 */
void* API::xMalloc(int size, enumValue::xType type, const std::string message) {
    switch(type){
        case enumValue::xInt:
            xIntR.meshCall(size, type, message);
            return &(xIntR);
        case enumValue::xChar:
            xIntC.meshCall(size, type, message);
            return &(xIntC);
        case enumValue::xDouble:
            xIntD.meshCall(size, type, message);
            return &(xIntD);    
    }                
}

/*
 * Se comunica con el Mesh Mem Manager para solicitar un espacio, 
 * especificar el tipo a almacenar y el valor a almacenar. 
 * Retorna una instancia de xReference.    
 */
void* API::xMalloc(int size, enumValue::xType type, void* value, const std::string message) {
    switch(type){
        case enumValue::xInt:
            xIntR.meshCall(size, type, value, message);
            return &(xIntR);
        case enumValue::xChar:
            xIntC.meshCall(size, type, value, message);
            return &(xIntC);
        case enumValue::xDouble:
            xIntD.meshCall(size, type, value, message);
            return &(xIntD);    
    }     
}

/*
 * Asigna un valor al espacio apuntado por un xReference, 
 * luego de asignar el valor se debe liberar la memoria.
 */
void API::xAssing(xReference<int>* reference, void* value) {
    reference->assingValue(value);
    value = NULL;       
}

/*
 * Contacta a Mesh Mem Manager para liberar el espacio indicado.
 */
template<typename T>
void API::xFree(xReference<T> toFree) {
    //Cantacta a Mesh Mem Manager para liberar espacio de toFree
}



//
//
//template<typename T>
//xReference<T> API::xMalloc(int size, xType type) {
//    switch(type){       
//        case xInt:
//            xReference<int>* xInt = new xReference<T>;
//            return xInt;
//        case xChar:
//            xReference<char>* xChar = new xReference<T>;
//            return xChar;
//        case xDouble:
//            xReference<double>* xDouble = new xReference<T>;
//            return xDouble;
//        case xBool:
//            xReference<bool>* xBool = new xReference<T>;
//            return xBool;
//    }    
//    //xReference<type>* prueba = new xReference<T>;
//    //instancia->setSize(size);
//    //return prueba;
//    //Retorna una instancia de xReference
//}
//
//template<typename T>
//xReference<T> API::xMalloc(int size, xType type, void* value) {
//    //Retorna una instancia de xReference
//}
//
//

API::~API() {
}

