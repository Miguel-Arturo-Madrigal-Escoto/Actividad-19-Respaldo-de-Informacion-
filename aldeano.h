#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
#include <string>

class Aldeano{
    private:
        std::string nombre;
        size_t edad;
        std::string genero;
        float salud;
    public:
        Aldeano(){};
        Aldeano(const std::string& nombre, size_t edad, const std::string& genero, float salud)
        : nombre(nombre), edad(edad), genero(genero), salud(salud){}

        void setNombre(const std::string& nombre);
        std::string getNombre() const;

        void setEdad(size_t edad);
        size_t getEdad() const;

        void setGenero(const std::string& genero);
        std::string getGenero();

        void setSalud(float salud);
        float getSalud() const;
        
        void encabezado_aldeano();

        friend std::istream& operator>>(std::istream& in, Aldeano& a){

            std::cin.sync();

            std::cout << "Nombre: ";
            getline(std::cin, a.nombre);

            std::cout << "Edad: ";
            std::cin >> a.edad;
            std::cin.sync();

            std::cout << "Genero: ";
            getline(std::cin, a.genero);

            std::cout << "Salud: ";
            std::cin >> a.salud;
            std::cin.sync();

            return in;
        }

        friend std::ostream& operator << (std::ostream& out, const Aldeano& a){
            out << std::left;

            out << std::setw(10) << a.nombre;
            out << std::setw(8) << a.edad;
            out << std::setw(12) << a.genero;
            out << std::setw(6) << a.salud;

            return out;
        }

        bool operator < (const Aldeano& a) const{
            return nombre < a.getNombre();
        }

        bool operator == (const Aldeano& a){
            return nombre == a.getNombre();
        }
        bool operator == (const Aldeano& a) const{
            return nombre == a.getNombre();
        }
};

#endif