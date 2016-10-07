#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_
#include <iostream>

#include "Node.h"

using namespace std;

/**
 * Clase Lista Doblemente Enlazada
 */
template<class k>
class LinkedList{

private:
	int _length;
	Node<k>* _head;
	Node<k>* _tail;

public:
	LinkedList();
	void insertTail(k);
	void deleteData(k);
	void showData();
	void vaciar();
	Node<k>* getHead();
	Node<k>* getTail();
	int getLength();
	bool isEmpty();
};

template<class k>
Node<k>* LinkedList<k>::getHead(){ return _head; }

template<class k>
Node<k>* LinkedList<k>::getTail(){ return _tail; }

template<class k>
int LinkedList<k>::getLength(){ return _length; }

template<class k>
bool LinkedList<k>::isEmpty()
{
	if(_head != 0){return false;}
	return true;
}

/**
 * Constructor de la clase en el que se
 * definen el head y el tail como nulos, además
 * el tamaño inicial de la lista en 0.
 */
template<class k>
LinkedList<k>::LinkedList(){
	_length = 0;
	_head = 0;
	_tail = 0;
}

/**
 * Método que permite insertar al final
 * de la lista, haciendo las operaciones correspondientes
 * para el movimiento de los nodos doblemente enlazados.
 */
template<class k>
void LinkedList<k>::insertTail(k pData){
	Node<k>* tmp = new Node<k>(pData);

	if(_head == 0){
		_length++;
		_head = tmp;
		_tail = _head;
	}
	else{
		_length++;
		_tail->setNext(tmp);
		tmp->setPrevious(_tail);
		_tail = tmp;
		_tail->setNext(_head);
		_head->setPrevious(_tail);
	}
}

/**
 * Método que permite borrar un dato específico
 * de la lista.
 */
template<class k>
void LinkedList<k>::deleteData(k pData){
	if(_head == 0){
		cout << "La lista esta vacía" << endl;
		return;
	}
	if(_head->getData() == pData){
		_head = _head->getNext();
		_tail->setNext(_head);
		_length--;
		return;
	}

	Node<k>* tmpNode = _head;
	while(tmpNode->getNext()!= _head && tmpNode->getNext()->getData() != pData){
		tmpNode = tmpNode->getNext();
	}

	if(tmpNode->getNext() == _head){
		return;
	}
	else{
		if(tmpNode->getNext() == _tail){
			_tail = tmpNode;
			_tail->setNext(_head);
			_length--;
			return;
		}
		else{
			tmpNode->setNext(tmpNode->getNext()->getNext());
			_length--;
			return;
		}
	}
}

/**
 * Método que muestra todos los elementos
 * de la lista. Recorriendola desde el head
 * hasta el tail. Utilizando con condición de finalización
 * en el ciclo for, su largo (_length)
 */
template<class k>
void LinkedList<k>::showData(){
	Node<k>* tmpNode = _head;
	for(int i=0; i < _length; i++){
		cout << "Dato: " << tmpNode->getData() << endl;
		tmpNode = tmpNode->getNext();
	}
}

/**
 * Limpiar la lista por completo
 */
template<class k>
void LinkedList<k>::vaciar(){
	this->_head = 0;
	this->_tail = 0;
	this->_length = 0;
}


#endif /* SRC_LINKEDLIST_H_ */