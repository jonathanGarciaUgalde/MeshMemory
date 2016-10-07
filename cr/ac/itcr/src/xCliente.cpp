#include "xCliente.h"

	 struct addrinfo host_info;
 	 struct addrinfo *host_info_list;

xCliente::xCliente() {
	// TODO Auto-generated constructor stub
}

xCliente::~xCliente() {
	// TODO Auto-generated destructor stub
}
/*El metodo run() es el metodo principal que se encarga de hacer las llamadas de los demas metodos que pertenecen a nuestra clase socket cliente*/
void xCliente::run(const std::string menj, const std::string message){

		crearSocket();
		ligarKernel();
                if(status == -1){
                    cout<<"No se pudo realizar la conexion"<<endl;
                }
                else{
                    sendMensaje(message);
                }
		
		//getMensaje();

}
/*Metodo que se encarga de crear el cliente define la IP,Puerto y protocolo de envio*/
void xCliente::crearSocket(){
	 	 	memset(&host_info, 0, sizeof host_info);
		    host_info.ai_family = AF_UNSPEC;
		    host_info.ai_socktype = SOCK_STREAM;
		    status = getaddrinfo("192.168.1.10", "8080", &host_info, &host_info_list);
		    if (status != 0)  cout << "getaddrinfo error" << gai_strerror(status) ;
}
/*Este metodo liga la liga el kernel , asignando los datos q definimos en el metodo anterior en status*/
void xCliente::ligarKernel(){
	 	 	cout << "Creando socket..."  << endl;
		    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,host_info_list->ai_protocol);
		    if (socketfd == -1) cout << "Socket error " ;
		    cout << "Conectando..."  << endl;
		    status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
		    if (status == -1)  cout << "Connect error" << endl;
                    
}
void xCliente::sendMensaje(const std::string msj){
			cout << "Enviando mensaje..."  << endl;
                        len = msj.length() + 1;
                        char message[len];
                        strcpy(message, msj.c_str());
                        message[len-1] = '\n';
			bytes_sent = send(socketfd, message, len, 0);
                        cout << "Mensaje enviado" << bytes_sent << endl;
}
void xCliente::getMensaje(){
    		cout << "Esperando recibir datos..."<< endl;
    		ssize_t bytes_recieved = -1;
                cout << "Esperando recibir datos..."<< endl;
    		bytes_recieved = recv(socketfd, incomming_data_buffer,1000, 0);
                cout << "Esperando recibir datos..."<< endl;

    		if (bytes_recieved == 0) cout << "host shut down." << endl ;
    		if (bytes_recieved == -1)cout << "recieve error!" << endl ;
    		cout << bytes_recieved << " bytes recibidos :" << endl ;
    		incomming_data_buffer[bytes_recieved] = '\0' ;
    		cout << incomming_data_buffer << endl;
    		cout << "Recibido Completo. Cerrando socket..." << endl;
    		freeaddrinfo(host_info_list);

	        //close(socketfd);

}