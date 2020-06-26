#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include "nodo.h"
#include "punto.h"
#include<iostream>
using namespace std;
template<typename T>
class Lista_Enlazada{
private:
    Nodo<T>* cabeza;
    int size;
public:
    Lista_Enlazada();
    Lista_Enlazada(T);
    Lista_Enlazada(Lista_Enlazada<T>&);
    ~Lista_Enlazada();
    void insertarCabeza(T);
    void insertarCola(T);
    void insertarPos(T, int);
    void eliminarCabeza();
    void eliminarCola();
    void eliminarPos(int);
    void imprimir();
    class Iterador {
		friend class Lista_Enlazada;
		private:
			Nodo<T> *nodo;
			Iterador(Nodo<T> *defecto){
				nodo = defecto;
			}
		public:
			Iterador(){	
			}
			bool operator == (const Iterador &it) const {
				return nodo == it.nodo;
			}
			bool operator != (const Iterador &i) const {
					return !(*this == i);
			}	
			Iterador &operator ++ (){
					nodo = nodo->getsiguiente();
					return *this;
			}
			Iterador &operator = (const Iterador &it) {
				if (this != &it)
					*nodo = *it.nodo;
				return *this;
			}
			const T &operator * () const {
				return nodo->getdato();
			}
		};
		Iterador begin() const{ 
			return Iterador(cabeza); 
		}
		Iterador end() const{ 
			return NULL; 
		}
};

template<typename T>
Lista_Enlazada<T>::Lista_Enlazada(){
    cabeza=NULL;
    size=0;
}
template<typename T>
Lista_Enlazada<T>::Lista_Enlazada(T valor){
    cabeza=new Nodo<T>(valor);
    size=1;
}

template<typename T>
Lista_Enlazada<T>::Lista_Enlazada(Lista_Enlazada<T>& lista){ 
    this->size=lista.size;
    while(lista.cabeza!=NULL){
        this->insertarCola((lista.cabeza)->getdato());
        (lista.cabeza)=(lista.cabeza)->getsiguiente();
    }
}

template<typename T>
Lista_Enlazada<T>::~Lista_Enlazada(){
    while (cabeza != NULL){
        delete cabeza;
        cabeza = cabeza->getsiguiente();
    }
    cout<<"Destructor invocado"<<endl;
}

template<typename T>
void Lista_Enlazada<T>::insertarCabeza(T valor){
    Nodo<T>* nuevo_nodo = new Nodo<T>;
    nuevo_nodo->setdato(valor);
    nuevo_nodo->setsiguiente(cabeza);
    cabeza = nuevo_nodo;
    size++;
}

template<typename T>
void Lista_Enlazada<T>::insertarPos(T valor,int pos){
    if (pos<0)
        cout<<"Las posiciones empiezan en 1"<<endl;
    else if (pos == 1)
        this->insertarCabeza(valor);
    else{
        Nodo<T>* nuevo_nodo = new Nodo<T>; 
        nuevo_nodo->setdato(valor);

        Nodo<T>* aux1 = cabeza;
        Nodo<T>* aux2 = NULL;
        int i= 1;
        while ((aux1!=NULL) && (i<pos)){
            aux2=aux1;
            aux1=aux1->getsiguiente();
            i++;
        }
        nuevo_nodo->setsiguiente(aux2->getsiguiente());
        aux2->setsiguiente(nuevo_nodo);
        size++;
    }
}

template<typename T>
void Lista_Enlazada<T>::insertarCola(T valor){
    Nodo<T>* newNodo = new Nodo<T>(); 
    newNodo->setdato(valor);
    newNodo->setsiguiente(NULL); 
    if(cabeza == NULL) 
        cabeza = newNodo; 
    else{
        Nodo<T>* temp = cabeza;
        while (temp->getsiguiente() != NULL) 
            temp = temp->getsiguiente(); 
        temp->setsiguiente(newNodo);
        size++;
    }
}


template<typename T>
void Lista_Enlazada<T>::imprimir(){
    Nodo<T>* aux=cabeza;
    while(aux!=NULL){
        cout<<aux->getdato()<<"->";
        aux=aux->getsiguiente();
    }
}

template<typename T>
void Lista_Enlazada<T>::eliminarCabeza(){
    if(cabeza==NULL)
        cout<<"Lista vacia"<<endl;
    else{
        delete cabeza;
        cabeza=cabeza->getsiguiente();
        size--;
    }
}
template<typename T>
void Lista_Enlazada<T>::eliminarPos(int pos){
    if(cabeza==NULL)
        cout<<"Lista vacia"<<endl;
    else{
        Nodo<T>* aux1=cabeza;
        Nodo<T>* aux2=NULL;
        for(int i=1;i<pos;i++){
            aux2=aux1;
            aux1=aux1->getsiguiente();
        }
        aux2->setsiguiente(aux1->getsiguiente());
        delete aux1;
        size--;
    }
}
template<typename T>
void Lista_Enlazada<T>::eliminarCola(){
    if(cabeza==NULL)
        cout<<"Lista vacia"<<endl;
    else{
        Nodo<T>* aux1=cabeza;
        Nodo<T>* aux2=NULL;
        while(aux1->getsiguiente()!=NULL){
            aux2=aux1;
            aux1=aux1->getsiguiente();
        }
        aux2->setsiguiente(aux1->getsiguiente());
        delete aux1;
        size--;
    }
}
#endif