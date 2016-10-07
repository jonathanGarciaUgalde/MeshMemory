#ifndef XREFERENCE_H
#define XREFERENCE_H
#include "enumValues.h"
#include <iostream>
#include "xCliente.h"
#include <sstream>

template<class T>
class xReference{
    private:
    //se realiza un  cambio al xReference .
        T num1;
        T _ID;
        T _size;
        T _type;
        void* _value;
    public:
        xReference();
        void setID(T);
        T getID();
        void meshCall(int size, enumValue::xType type, const std::string message);
        void meshCall(int size, enumValue::xType type, void* value,
                const std::string message);
        void assingValue(void* value);
        
        /*
         * Retorna el valor guardado en la mesh memory
         * Crea un espacio de memoria en el cliente usando malloc
         * Asigna el valor a ese espacio y retorna el puntero (void*)
         * para que sea usadopor el cliente
         */
        xReference& operator*()
        {
            std::cout<<"hola"<<std::endl;
            
//            solicita al MMM que regrese la informacion del valor en el espacio
//            de memoria, luego crea un espacio de memoria en el cliente
//            con malloc y guarda ahi la informacion, retornando el puntero
            //malloc(_size);
            //return ;
        }                    
        friend bool operator ==(xReference& obj1, xReference& obj2){
            bool estado;
            if(obj1._ID == obj2._ID){
                estado = true;
            }
            else{
                estado = false;
            }
            return estado;
        }
        friend bool operator !=(xReference& obj1, xReference& obj2){
            bool estado;
            if(obj1._ID != obj2._ID){
                estado = true;
            }
            else{
                estado = false;
            }
            return estado;
        }
//        void operator =(){
//            //Incrementa el conteo de referencias en Mesh Mem Manager
//        }
        void operator+(const xReference& left);
        //{
            //std::cout<<"hola"<<std::endl;
//            llamada al MMM con el ID, indicandole que debe aumentar las
//            referencias a ese espacio de memoria
        //}
};

template<class T>
void xReference<T>::operator+(const xReference& left){
    std::cout<<"hola"<<std::endl;
}
        
template<class T>
xReference<T>::xReference(){
    _size = 0;
}

template<class T>
void xReference<T>::setID(T id){
    _ID = id;
}

template<class T>
T xReference<T>::getID(){
    return _ID;
}

template<class T>
void xReference<T>::meshCall(int size, enumValue::xType type, const std::string message){
    _size = size;    
//    llamada al MMM para solicitar un espacio de tamaño size
//    y de tipo type
}

template<class T>
void xReference<T>::meshCall(int size, enumValue::xType type, void* value,
        const std::string message){
    xCliente* cliente = new xCliente();
    _size = size;
    _type = type;    
    
    cliente->run(message,message);
//    llamada al MMM para solicitar un espacio de tamaño size,
//    de tipo type y el valor a guardar value
}

template<class T>
void xReference<T>::assingValue(void* value){
    _value = value;    
    stringstream ss;
    ss << value;
    string str = ss.str();
    
//    llamada al MMM para asignar un valor a un espacio de memoria
}

#endif /* XREFERENCE_H */

