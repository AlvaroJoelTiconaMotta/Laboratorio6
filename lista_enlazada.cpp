#include <iostream>
#include "lista_enlazada.h"
using namespace std;
int main(){
    Lista_Enlazada<float> lista1;
    cout<<"Trabajando con float"<<endl;
    lista1.insertarCabeza(1.2);
    lista1.insertarCabeza(2.3);
    lista1.insertarCabeza(3.0);
    lista1.imprimir();
    cout<<endl;
    lista1.insertarCola(0.4);
    lista1.insertarCola(9.8);
    lista1.imprimir();
    cout<<endl;
    lista1.insertarPos(-1.3,1);
    lista1.insertarPos(-1.4,3);
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

    cout<<endl<<endl<<"Trabajando con char"<<endl;
    //Probando con strings
    Lista_Enlazada<char> lista2;
    lista2.insertarCabeza('a');
    lista2.insertarCabeza('b');
    lista2.insertarCabeza('c');
    lista2.imprimir();
    cout<<endl;
    lista2.insertarCola('h');
    lista2.insertarCola('m');
    lista2.imprimir();
    cout<<endl;
    lista2.insertarPos('d',1);
    lista2.insertarPos('e',3);
    lista2.imprimir();
    cout<<endl;
    lista2.eliminarCabeza();
    lista2.imprimir();
    cout<<endl;
    lista2.eliminarCola();
    lista2.imprimir();
    cout<<endl;
    lista2.eliminarPos(3);
    lista2.imprimir();
    cout<<endl<<endl<<"Trabajando con enteros"<<endl;
    //Probando con enteros
    Lista_Enlazada<int>lista3;
    lista3.insertarCabeza(1);
    lista3.insertarCabeza(2);
    lista3.insertarCabeza(4);
    lista3.imprimir();
    cout<<endl;
    lista3.insertarCola(3);
    lista3.insertarCola(6);
    lista3.imprimir();
    cout<<endl;
    lista3.insertarPos(-1,1);
    lista3.insertarPos(-4,3);
    lista3.imprimir();
    cout<<endl;
    lista3.eliminarCabeza();
    lista3.imprimir();
    cout<<endl;
    lista3.eliminarCola();
    lista3.imprimir();
    cout<<endl;
    lista3.eliminarPos(3);
    lista3.imprimir();
    cout<<"\n\nHaciendo uso del iterador con floats: "<<endl;
    for (Lista_Enlazada<float>::Iterador it = lista1.begin(); it!= lista1.end(); ++it)
		cout<<(*it)<< " -> ";
    cout<<endl<<endl;
    cout<<"Haciendo uso del iterador con chars: "<<endl;
    for (Lista_Enlazada<char>::Iterador it2 = lista2.begin(); it2!= lista2.end(); ++it2)
		cout<<(*it2)<< " -> ";
    cout<<endl<<endl;
    cout<<"Haciendo uso del iterador con ints: "<<endl;
    for (Lista_Enlazada<int>::Iterador it3 = lista3.begin(); it3!= lista3.end(); ++it3)
		cout<<(*it3)<< " -> ";
    cout<<endl<<endl;

    Punto punto;
    Punto punto2(4.5,5.2);
    punto.setx(6.3);
    punto.sety(9.2);
    Punto punto3=punto;
    
    Lista_Enlazada<Punto>lista4;
    lista4.insertarCabeza(punto);
    lista4.insertarCola(punto2);
    lista4.insertarPos(punto3,2);

    for (Lista_Enlazada<Punto>::Iterador it4 = lista4.begin(); it4!= lista4.end(); ++it4)
		cout<<(*it4)<< " -> ";
    
    cout<<endl<<endl;

    Lista_Enlazada<float> lista5=lista1;
    lista5.imprimir();
    cout<<endl;
}
