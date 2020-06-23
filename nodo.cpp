#include<iostream>
#include "nodo.h"
using namespace std;

int main(){
    //Creamos dos nodos
    Nodo <int>prueba(5),prueba2(6);
    Nodo <int>prueba3;
    //El nodo 1 apuntara al nodo 2
    prueba.setsiguiente(&prueba2);
    //Imprimimos datos de prueba
    cout<<prueba.getdato()<<endl;
    cout<<prueba.getsiguiente()<<endl;
    //Imprimimos datos de prueba 2
    cout<<prueba2.getdato()<<endl;
    cout<<prueba2.getsiguiente()<<endl;
    //Hacemos uso del constructor copia
    prueba3=prueba;
    //Imprimimos sus datos
    cout<<prueba3.getdato()<<endl;
    cout<<prueba3.getsiguiente()<<endl;
}