#include "aldeano.h"

using namespace std;

void Aldeano::setNombre(const string& nombre){
    this->nombre = nombre;
}
string Aldeano::getNombre() const{
    return this->nombre;
}

void Aldeano::setEdad(size_t edad){
    this->edad = edad;
}
size_t Aldeano::getEdad() const{
    return this->edad;
}

void Aldeano::setGenero(const string& genero){
    this->genero = genero;
}
string Aldeano::getGenero(){
    return this->genero;
}

void Aldeano::setSalud(float salud){
    this->salud = salud;
}
float Aldeano::getSalud() const{
    return this->salud;
}