#include<iostream>
#include "nodo.h"
using namespace std;

int main(){
    //Creamos dos nodos
    cout<<"Probando nuestro codigo con int"<<endl;
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

    //Probando con floats
    cout<<endl<<"Probando nuestro codigo con float"<<endl;
    //Creamos dos nodos
    Nodo <float>prueba4(5.3),prueba5(6.2);
    Nodo <float>prueba6;
    //El nodo 1 apuntara al nodo 2
    prueba4.setsiguiente(&prueba5);
    //Imprimimos datos de prueba
    cout<<prueba4.getdato()<<endl;
    cout<<prueba4.getsiguiente()<<endl;
    //Imprimimos datos de prueba 2
    cout<<prueba5.getdato()<<endl;
    cout<<prueba5.getsiguiente()<<endl;
    prueba6=prueba4;
    //Imprimimos sus datos
    cout<<prueba6.getdato()<<endl;
    cout<<prueba6.getsiguiente()<<endl;

    //Probando con char
    cout<<endl<<"Probando nuestro codigo con char"<<endl;
    //Creamos dos nodos
    Nodo <char>prueba7('a'),prueba8('b');
    Nodo <char>prueba9;
    //El nodo 1 apuntara al nodo 2
    prueba7.setsiguiente(&prueba8);
    //Imprimimos datos de prueba
    cout<<prueba7.getdato()<<endl;
    cout<<prueba7.getsiguiente()<<endl;
    //Imprimimos datos de prueba 2
    cout<<prueba8.getdato()<<endl;
    cout<<prueba8.getsiguiente()<<endl;
    prueba9=prueba7;
    //Imprimimos sus datos
    cout<<prueba9.getdato()<<endl;
    cout<<prueba9.getsiguiente()<<endl;
}