#include<iostream>
#include "punto.h"
using namespace std;

int main(){
    Punto punto(4.5,5.2);
    cout<<punto.getx()<<endl;
    cout<<punto.gety()<<endl;
    punto.setx(6.3);
    punto.sety(9.2);
    cout<<punto.getx()<<endl;
    cout<<punto.gety()<<endl;
    return 0;
}