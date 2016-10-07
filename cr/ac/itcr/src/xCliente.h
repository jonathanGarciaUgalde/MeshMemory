#ifndef XCLIENTE_H_
#define XCLIENTE_H_
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include "Application.h"

using namespace std;

class xCliente {
public:
	xCliente();
	virtual ~xCliente();
	void crearSocket();
	void ligarKernel();
	void getMensaje();
	void sendMensaje(const std::string menj);
	void run(const std::string msj, const std::string message);        
        
    ssize_t bytes_sent;
	int status;
	int len;
	int socketfd ;
	char incomming_data_buffer[1000];
};


#endif /* XCLIENTE_H_ */
