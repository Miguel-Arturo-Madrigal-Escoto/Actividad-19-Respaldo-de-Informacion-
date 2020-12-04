#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <list>

#include "aldeano.h"

class Civilizacion{
    private:
        std::string nombre;
        int ubicacion_x;
        int ubicacion_y;
        float puntuacion;

        std::list<Aldeano> aldeanos;

    public:
        Civilizacion();
        Civilizacion(std::string nombre, int ubicacion_x, int ubicacion_y, float puntuacion);

        void setNombre(const std::string& v);
        void setUbicacionX(int v);
        void setUbicacionY(int v);
        void setPuntuacion(float v);

        std::string getNombre();
        int getUbicacionX();
        int getUbicacionY();
        float getPuntuacion();

        /// metodos aldeano
        void agregarFinal(const Aldeano& a);
        void agregarInicio(const Aldeano& a);

        void mostrarAldeanos();

        void eliminarNombre(const std::string& nombre);
        void eliminarSalud(float salud);
        void eliminarEdad();

        void clasificarNombre();
        void clasificarEdad();
        void clasificarSalud();

        Aldeano* buscarAldeano(const Aldeano& a);

        bool vacia();

        void respaldar_aldeanos();
        void recuperar_aldeanos(std::string& nombre);

        friend std::ostream& operator<<(std::ostream& out, const Civilizacion& c){

            out << std::left;
            out << std::setw(25) << c.nombre; 
            out << std::setw(20) << c.ubicacion_x;
            out << std::setw(20) << c.ubicacion_y;
            out << std::setw(10) << c.puntuacion;
            out << std::endl;

            return out;
        }

        friend std::istream& operator>>(std::istream& in, Civilizacion& c){

            std::cin.sync();

            std::cout << "Nombre de la civilizacion: ";
            getline(std::cin, c.nombre);

            std::cout << "Ubicacion en x: ";
            std::cin >> c.ubicacion_x;
            std::cin.sync();

            std::cout << "Ubicacion en y: ";
            std::cin >> c.ubicacion_y;
            std::cin.sync();

            std::cout << "Puntuacion: ";
            std::cin >> c.puntuacion;
            std::cin.sync();

            return in;
        }

        bool operator == (const Civilizacion& c){
            return nombre == c.nombre;
        }
        bool operator == (const Civilizacion& c) const{
            return nombre == c.nombre;
        }
        bool operator < (const Civilizacion& c){
            return nombre < c.nombre;
        }
        bool operator < (const Civilizacion& c) const{
            return nombre < c.nombre;
        }

        void encabezado_aldeano();

        ~Civilizacion();
};

#endif