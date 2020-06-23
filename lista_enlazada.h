#include "nodo.h"
#include<iostream>
using namespace std;
template<typename T>
class Lista_Enlazada{
private:
    Nodo<T>* cabeza;
    T size;
public:
    Lista_Enlazada();
    Lista_Enlazada(T valor);
    Lista_Enlazada(Lista_Enlazada<T>& lista);
    ~Lista_Enlazada();
    void insertarCabeza(T valor);
    void insertarCola(T valor);
    void insertarPos(T valor, int pos);
    void eliminarCabeza();
    void eliminarCola();
    void eliminarPos(int pos);
    void imprimir();
    friend class <T>Iterador;
};
template<typename T>
class Iterador{
private:
    Nodo<T>* retornar;
public:
    Iterador(Lista_Enlazada<T> lista);
    ~Iterador();
    Nodo<T> Begin(){
        return retornar;
    }
    Nodo<T> End(){
        while(retornar->getsiguiente()!=NULL){
            retornar=retornar->getsiguiente();
        }
        return retornar->getsiguiente;
    }
    Nodo<T>* operator++(){
        retornar=retornar->getsiguiente();
        return retornar;
    }
    T operator*(){
        return this->retornar->getdato;
    }
    void operator=(Iterador it){
        this->retornar=it.retornar;
    }
};

template<typename T>
Iterador<T>::Iterador(Lista_Enlazada<T> lista){
    retornar=lista.cabeza;
}

template<typename T>
Iterador<T>::~Iterador(){
}
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
    cabeza = NULL; 
    this->size = lista.size;
    Nodo<T>* aux = NULL;
    Nodo<T>* temp = lista.cabeza;
    while (temp != NULL)
    {
        Nodo<T>* nodo_copia = new Nodo<T>;
        nodo_copia->setdato(temp->getdato());
        if(aux == NULL)
            cabeza = nodo_copia;
        else
            aux->setsiguiente(nodo_copia);
        aux = nodo_copia;
        temp = aux->getsiguiente();
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