#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "civilizacion.h"

class VideoGame{
    private:
        std::string nombre_usuario;
        std::vector<Civilizacion> civilizaciones;
    public:
        VideoGame();

        void setNombreUsuario(const std::string& v);
        std::string getNombreUsuario();
        
        void agregarCivilizacion(const Civilizacion& c);
        void insertar(const Civilizacion& c, size_t pos);
        void inicializar(const Civilizacion& c, size_t n);
        bool eliminar(const Civilizacion& c);
        void encabezado_tabla();
        void mostrar();

        void ordenarNombre();
        void ordenarUbicacionX();
        void ordenarUbicacionY();
        void ordenarPuntuacion();

        Civilizacion primera();
        Civilizacion ultima();
        Civilizacion* buscar(const Civilizacion& c);

        size_t total();

        void respaldar_civ();
        void recuperar_civ();

        friend VideoGame& operator<<(VideoGame& v, const Civilizacion& c){
            v.agregarCivilizacion(c);

            return v;
        }

        ~VideoGame();
};

#endif