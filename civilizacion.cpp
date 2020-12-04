#include <algorithm>
#include <fstream>
#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(string nombre, int ubicacion_x, int ubicacion_y, float puntuacion){
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string& v){
    this->nombre = v;
}
void Civilizacion::setUbicacionX(int v){
    this->ubicacion_x = v;
}
void Civilizacion::setUbicacionY(int v){
    this->ubicacion_y = v;
}
void Civilizacion::setPuntuacion(float v){
    this->puntuacion = v;
}

string Civilizacion::getNombre(){
    return this->nombre;
}
int Civilizacion::getUbicacionX(){
    return this->ubicacion_x;
}
int Civilizacion::getUbicacionY(){
    return this->ubicacion_y;
}
float Civilizacion::getPuntuacion(){
    return this->puntuacion;
}

Civilizacion::~Civilizacion(){}

///Aldeano metodos

void Civilizacion::encabezado_aldeano(){
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(8) << "Edad";
    cout << setw(12) << "Genero";
    cout << setw(6) << "Salud";
    cout << endl;
}

void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
}

void Civilizacion::mostrarAldeanos(){
    encabezado_aldeano();

    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string& nombre){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarSalud(float salud){
    aldeanos.remove_if([salud](const Aldeano& a){ return a.getSalud() < salud; });
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if([](const Aldeano& a){ return a.getEdad() >= 60; });
}

void Civilizacion::clasificarNombre(){
    aldeanos.sort();
}

void Civilizacion::clasificarEdad(){
    aldeanos.sort([](const Aldeano& a, const Aldeano& b){ return a.getEdad() > b.getEdad(); });
}

void Civilizacion::clasificarSalud(){
    aldeanos.sort([](const Aldeano& a, const Aldeano& b){ return a.getSalud() > b.getSalud(); });
}

Aldeano* Civilizacion::buscarAldeano(const Aldeano& a){
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if(it == aldeanos.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

bool Civilizacion::vacia(){
    return aldeanos.empty();
}

void Civilizacion::respaldar_aldeanos(){
    ofstream aldeanos_archivo(getNombre() + ".txt", ios::out);

    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano& aldeano = *it;

        aldeanos_archivo << aldeano.getNombre() << endl;
        aldeanos_archivo << aldeano.getEdad() << endl;
        aldeanos_archivo << aldeano.getGenero() << endl;
        aldeanos_archivo << aldeano.getSalud() << endl;
    }
    aldeanos_archivo.close();
}

void Civilizacion::recuperar_aldeanos(string& nombre){
    ifstream aldeanos_archivo(nombre + ".txt");

    if(aldeanos_archivo.is_open()){
        Aldeano aldeano;
        string aux;

        while(true)
        {
            getline(aldeanos_archivo, aux);

            if(aldeanos_archivo.eof()) break;

            aldeano.setNombre(aux);

            getline(aldeanos_archivo, aux);
            aldeano.setEdad(stoi(aux));

            getline(aldeanos_archivo, aux);
            aldeano.setGenero(aux);

            getline(aldeanos_archivo, aux);
            aldeano.setSalud(stof(aux));

            agregarFinal(aldeano);
        }

        aldeanos_archivo.close();
    }
}