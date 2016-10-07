#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "cstdlib"
#include "API.h"
#include "xReference.h"
#include "xCliente.h"
#include "LinkedList.h"
#include "enumValues.h"
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"

using namespace std;

class Application {
public:
	Application();
	
	int temp_2; //
	int temp_id; //
        int temp_size; //
        string temp_sizeS;
        string temp_type; //
        string temp_msg; //
        string temp_value;
        string separador;
        string host;
        string port;
        
        
        
	void menu();
	void menu_1();	
private:
    xReference<int>* mallocI;
    xReference<char>* mallocC;
    xReference<double>* mallocD;
};

#endif /* APPLICATION_H_ */
