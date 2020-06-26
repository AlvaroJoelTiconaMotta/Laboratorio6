#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;
class Punto{
private:
    double x;
    double y;
public:
    Punto();
    Punto(double,double);
    Punto(Punto&);
    void setx(double);
    void sety(double);
    double getx();
    double gety();
    ~Punto();
    friend ostream& operator<<(ostream &salida, const Punto &p);
};

ostream& operator<<(ostream &salida, const Punto &p){
    salida<<"("<<p.x<<","<<p.y<<")";
    return salida;
}

Punto::Punto(){
    x=0.0;
    y=0.0;
}

Punto::Punto(double x,double y){
    this->x=x;
    this->y=y;
}

Punto::Punto(Punto& punto){
    this->x=punto.x;
    this->y=punto.y;
}

void Punto::setx(double x){
    this->x=x;
}

void Punto::sety(double y){
    this->y=y;
}

double Punto::getx(){
    return x;
}

double Punto::gety(){
    return y;
}
Punto::~Punto(){
}

#endif