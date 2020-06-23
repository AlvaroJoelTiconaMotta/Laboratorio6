#include <iostream>
#include "lista_enlazada.h"
using namespace std;
int main(){
    Lista_Enlazada<float> lista1;
    lista1.insertarCabeza(1);
    lista1.insertarCabeza(2);
    lista1.insertarCabeza(3);
    lista1.imprimir();
    cout<<endl;
    lista1.insertarCola(0);
    lista1.insertarCola(9);
    lista1.imprimir();
    cout<<endl;
    lista1.insertarPos(3,1);
    lista1.insertarPos(-1,3);
    lista1.imprimir();
    cout<<endl;
    lista1.eliminarCabeza();
    lista1.imprimir();
    cout<<endl;
    lista1.eliminarCola();
    lista1.imprimir();
    cout<<endl;
    lista1.eliminarPos(3);
    lista1.imprimir();
    cout<<endl;
    Lista_Enlazada<float> lista2=lista1;
    lista2.imprimir();
    Iterador <float>it(lista1);
    for(it.Begin();it.End();it++){
        cout<<(*it);
    }
}