
#include "Application.h"
xCliente *cliente = new xCliente();

LinkedList<void*>* referencias = new LinkedList<void*>();

Application::Application()
{
	this->temp_2 = 0;
        this->separador = "/";
}

void Application::menu(){
	 cout <<"==============================================================="<<endl;
	 cout <<"||.......................BIENVENIDO..........................||"<<endl;
	 cout <<"||..............##....##..######..######..##...##............||"<<endl;
         cout <<"||..............###..###..##......##......##...##............||"<<endl;
         cout <<"||..............##.##.##..####....######..#######............||"<<endl;
         cout <<"||..............##....##..##..........##..##...##............||"<<endl;
	 cout <<"||..............##....##..######..######..##...##............||"<<endl;
	 cout <<"||...........................................................||"<<endl;
	 cout <<"||..##....##..######..##....##..######..#######...##....##...||"<<endl;
	 cout <<"||..###..###..##......###..###..##..##..##..##.....##..##....||"<<endl;
	 cout <<"||..##.##.##..####....##.##.##..##..##..####........####.....||"<<endl;
	 cout <<"||..##....##..##......##....##..##..##..##..##.......##......||"<<endl;
	 cout <<"||..##....##..######..##....##..######..##....##.....##......||"<<endl;
	 cout <<"==============================================================="<<endl;
	 menu_1();

}
void Application::menu_1(){
    host = "192.168.1.10";
    port = "8080";
    
    
    API* Api = new API();
    cout <<">> Por favor seleccione el número de la acción que desea realizar"<<endl;
    cout <<">> 1 : Crear un Objecto"<<endl;
    cout <<">> 2 : Borrar un Objecto"<<endl;
    cout <<">> 3 : Asignar Valor a un Objecto"<<endl;
    cout <<">> Cualquier tecla : Salir de terminal"<<endl;
    cin>>temp_2;
    if (temp_2==1)
    {        
        cout <<">> Por favor seleccione el tipo de creación que desea realizar"<<endl;
        cout <<">> 1 : Crear un Objecto sin valor"<<endl;
        cout <<">> 2 : Crear un Objecto con valor"<<endl;
        cout <<">> 3 : Cancelar creación"<<endl;
        cin>>temp_id;
                
        if(temp_id == 1){
            cout <<">> Por favor introduzca el tamaño del objeto a crear(en digitos)"<<endl;
            cin>>temp_sizeS;
            cout <<">> Por favor introduzca el tipo del objeto a crear"<<endl;
            cout <<">>xInt"<<endl;
            cout <<">>xChar"<<endl;
            cout <<">>xDouble"<<endl;
            cin>>temp_type;
            if(temp_type=="xInt"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador;                                
                Api->initialize(host, port, temp_msg);                                
                mallocI = (xReference<int>*)(Api->xMalloc(temp_size, enumValue::xInt, temp_msg));
                referencias->insertTail(mallocI);
            }
            
            else if(temp_type=="xChar"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador;                                
                Api->initialize(host, port, temp_msg);                                
                mallocC = (xReference<char>*)(Api->xMalloc(temp_size, enumValue::xChar, temp_msg));
                referencias->insertTail(mallocC);
            }
            else if(temp_type=="xDouble"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador;                                
                Api->initialize(host, port, temp_msg);                                
                mallocD = (xReference<double>*)(Api->xMalloc(temp_size, enumValue::xDouble, temp_msg));
                referencias->insertTail(mallocD);
            }
            else{
                cout<<"Error, opción inválida"<<endl;
            }            
            menu();
        }
        else if(temp_id == 2){
            cout <<">> Por favor introduzca el tamaño del objeto a crear(en digitos)"<<endl;
            cin>>temp_sizeS;
            cout <<">> Por favor introduzca el tipo del objeto a crear"<<endl;
            cout <<">>xInt"<<endl;
            cout <<">>xChar"<<endl;
            cout <<">>xDouble"<<endl;
            cin>>temp_type;
            cout<<"Ingrese el valor del dato que desea guardar"<<endl;
            cin>>temp_value;
            if(temp_type=="xInt"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador + temp_value;                                
                Api->initialize(host, port, temp_msg);                                
                void* valor = &(temp_value); 
                mallocI = (xReference<int>*)(Api->xMalloc(temp_size, enumValue::xInt, valor, temp_msg));
                referencias->insertTail(mallocI);
            }
            
            else if(temp_type=="xChar"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador + temp_value;                                
                Api->initialize(host, port, temp_msg);                                
                void* valor = &(temp_value); 
                mallocC = (xReference<char>*)(Api->xMalloc(temp_size, enumValue::xChar, valor, temp_msg));
                referencias->insertTail(mallocC);
            }
            else if(temp_type=="xDouble"){
                temp_size = atoi(temp_sizeS.c_str());
                temp_msg = temp_sizeS + this->separador + temp_type + this->separador + temp_value;                                
                Api->initialize(host, port, temp_msg);                                
                void* valor = &(temp_value); 
                mallocD = (xReference<double>*)(Api->xMalloc(temp_size, enumValue::xDouble, valor, temp_msg));
                referencias->insertTail(mallocD);
            }
            else{
                cout<<"Error, opción inválida"<<endl;
            }            
            menu();
        }
        else if(temp_id == 3){
            menu_1();
        }
        else{
            cout<<"Por favor introduzca una opción válida"<<endl;
        }
    }
    else if(temp_2==2){        
    }
    else if(temp_2==3){        
    }
    else{
        cout<<"Muchas Gracias por utilizar Mesh Memory!" <<endl;
    }
}

