#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

template <typename T>
class Nodo{
    private:
        T dato;
        Nodo<T>* siguiente;
    public:
        Nodo();
        Nodo( T nuevoDato);
        Nodo(Nodo &);
        ~Nodo();
        T getdato();
        Nodo<T>* getsiguiente ();
        void setdato (T dato);
        void setsiguiente(Nodo<T>* Nodo_siguiente);
        
};

template <typename T>
Nodo<T>::Nodo(){
    siguiente = NULL;
}


template <typename T>
Nodo<T>::Nodo( T nuevoDato){
    siguiente = NULL;
    dato = nuevoDato;
}

template<typename T>
Nodo<T>::Nodo(Nodo &nodo){
    this->dato=nodo.dato;
    this->siguiente=nodo.siguiente;
}

template<typename T>
Nodo<T>::~Nodo(){
}

template <typename T>
T Nodo<T>::getdato(){
    return dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getsiguiente(){
    return siguiente;
}

template <typename T>
void Nodo<T>::setdato(T nuevoDato){
    dato = nuevoDato;
}

template <typename T>
void Nodo<T>::setsiguiente(Nodo<T> *Nodo_siguiente){
    siguiente = Nodo_siguiente;
}
#endif