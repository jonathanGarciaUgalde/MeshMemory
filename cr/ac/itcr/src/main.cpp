#include <cstdlib>
#include <iostream>
#include "xReference.h"
#include "API.h"
#include "enumValues.h"
#include "Application.h"

using namespace std;
/*
 * 
 */
int main() {    
    Application* inicio = new Application();
    inicio->menu();
    
    
//    API* prueba3 = new API();
//    
//    
//    xReference<int>* mallocI;
//    xReference<int>* mallocI2;
//    xReference<char>* mallocC;
//    
//    mallocI = prueba3->xMallocI(10, enumValue::xInt);
//    mallocC = prueba3->xMallocC(10, enumValue::xChar);
//    mallocI2 = prueba3->xMallocI(10, enumValue::xInt);
//    
//    mallocI->setID(22);
//    mallocI2->setID(21);
//    
//    char a = 'a';
//    void* value = &a;
//    prueba3->xAssing(mallocI, value);
//    
//    (*mallocI) != (*mallocI2);
//    
//    (*mallocI) == (*mallocI2);
//    
//    //bool estado = mallocI->operator !=(mallocI2);
//    //cout<<estado<<endl;
//    
//    *mallocI;
    
    return 0;
}

