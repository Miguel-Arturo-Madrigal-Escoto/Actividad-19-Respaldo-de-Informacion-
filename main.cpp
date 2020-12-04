#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "videogame.h"
#include "menucivilizacion.h"

using namespace std;

int main()
{
    VideoGame vg;
    Civilizacion civ;
    string str;
    size_t n;

    cout << "Nombre de usuario: ";
    getline(cin, str);
    vg.setNombreUsuario(str);
    system("cls");

    do{
        cout << "\tActividad 19" << endl << endl;
        cout << "Bienvenido/a: "  << vg.getNombreUsuario() << endl;
        cout << "1) Cambiar nombre de usuario" << endl;
        cout << "2) Agregar civilizacion" << endl;
        cout << "3) Insertar civilizacion" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Primer civilizacion" << endl;
        cout << "6) Ultima civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar civilizacion" << endl;
        cout << "9) Buscar civilzacion" << endl;
        cout << "10) Modificar civilizacion" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar" << endl;
        cout << "13) Recuperar" << endl;
        cout << "14) Salir" << endl;
        cout << "-> Elige una opcion: ";
        getline(cin, str);

        if(str == "1"){
            cout << "Nombre de usuario: ";
            getline(cin, str);
            vg.setNombreUsuario(str); 
        }
        else if(str == "2"){
            cin >> civ;
            vg.agregarCivilizacion(civ);
        }
        else if(str == "3"){
            cin >> civ;

            cout << "Posicion: ";
            cin >> n;
            cin.sync();

            if(n >= vg.total()){
                cout << "Posicion invalida" << endl;
            }else{
                vg.insertar(civ, n);
            }
        }
        else if(str == "4"){
            cout << "Cantidad de civilizaciones: ";
            cin >> n;
            cin.sync();

            cout << endl;

            cin >> civ;

            vg.inicializar(civ, n);
        }
        else if(str == "5"){
            if(vg.total() > 0){
                vg.encabezado_tabla();
                cout << vg.primera() << endl;
            }
            else{
                cout << "El vector esta vacio. No hay civilizaciones" << endl;
            }
        }
        else if(str == "6"){
            if(vg.total() > 0){
                vg.encabezado_tabla();
                cout << vg.ultima() << endl;
            }
            else{
                cout << "El vector esta vacio. No hay civilizaciones" << endl;
            }
        }
        else if(str == "7"){
            if(vg.total() > 0){
                cout << "\n1) Ordenar por nombre" << endl;
                cout << "2) Ordenar por ubicacion en x" << endl;
                cout << "3) Ordenar por ubicacion en y" << endl;
                cout << "4) Ordenar por puntuacion - descendente" << endl;
                cout << "-> Elige una opcion: ";
                getline(cin, str);

                if(str == "1"){
                    vg.ordenarNombre();
                    cout << " * Civilizaciones ordenadas correctamente * " << endl;
                }
                else if(str  == "2"){
                    vg.ordenarUbicacionX();
                    cout << " * Civilizaciones ordenadas correctamente * " << endl;
                }
                else if(str == "3"){
                    vg.ordenarUbicacionY();
                    cout << " * Civilizaciones ordenadas correctamente * " << endl;
                }
                else if(str == "4"){
                    vg.ordenarPuntuacion();
                    cout << " * Civilizaciones ordenadas correctamente * " << endl;
                }
                else{
                    cout << "Opcion invalida" << endl;
                }
            }
            else{
                cout << "No es posible ordenar. No hay civilizaciones registradas" << endl;
            }
        }
        else if(str == "8"){
            if(vg.total() > 0){
                cout << "Civilizacion a eliminar: ";
                getline(cin, str);
                civ.setNombre(str);

                bool eliminar = vg.eliminar(civ);

                if(!eliminar){
                    cout << "No eliminado. No existe una civilizacion llamada " << civ.getNombre() << endl;
                }else{
                    cout << "Civilizacion eliminada correctamente" << endl;
                }
            }
            else{
                cout << "No es posible eliminar. No hay civilizaciones registradas" << endl;
            }
        }
        else if(str == "9"){
            if(vg.total() > 0){
                cout << "Civilizacion a buscar: ";
                getline(cin, str);
                civ.setNombre(str);

                Civilizacion *ptr = vg.buscar(civ);

                if(ptr == nullptr){
                    cout << "Civilizacion no encontrada" << endl;
                }else{
                    menuCivilizacion(*ptr);
                }
            }
            else{
                cout << "No es posible buscar. No hay civilizaciones registradas" << endl;
            }
        }
        else if(str == "10"){
            if(vg.total() > 0){
                cout << "Civilizacion a modificar: ";
                getline(cin, str);
                civ.setNombre(str);

                Civilizacion *ptr = vg.buscar(civ);

                if(ptr == nullptr){
                    cout << "Civilizacion no encontrada" << endl;
                }else{
                    cout << "Civilizacion encontrada: " << endl;

                    while(true)
                    {
                        vg.encabezado_tabla();
                        cout << *ptr << endl;
                        
                        cout << "\n1) Modificar nombre" << endl;
                        cout << "2) Modificar ubicacion en x" << endl;
                        cout << "3) Modificar ubicacion en y" << endl;
                        cout << "4) Modificar puntuacion" << endl;
                        cout << "0) Volver al menu principal" << endl;
                        cout << "-> Elige una opcion: ";
                        getline(cin, str);

                        if(str == "0"){
                            break;
                        }
                        else if(str == "1"){
                            cout << "Nuevo nombre: ";
                            getline(cin, str);
                            ptr->setNombre(str);

                            cout << " * Civilizacion actualizada * " << endl;
                            cout << " * Presiona una tecla para ver los cambios * "<< endl;
                        }
                        else if(str == "2"){
                            cout << "Nueva ubicacion en x: ";
                            cin>>n;
                            ptr->setUbicacionX(n);

                            cin.sync();
                            cout << " * Civilizacion actualizada * " << endl;
                            cout << " * Presiona una tecla para ver los cambios * "<< endl;
                        }
                        else if(str == "3"){
                            cout << "Nueva ubicacion en y: ";
                            cin>>n;
                            ptr->setUbicacionY(n);

                            cin.sync();
                            cout << " * Civilizacion actualizada * " << endl;
                            cout << " * Presiona una tecla para ver los cambios * "<< endl;
                        }
                        else if(str == "4"){
                            float p;
                            cout << "Nueva puntuacion: ";
                            cin >> p;
                            ptr->setPuntuacion(p);

                            cin.sync();
                            cout << " * Civilizacion actualizada * " << endl;
                            cout << " * Presiona una tecla para ver los cambios * "<< endl;
                        }
                        else{
                            cout << "Opcion invalida" << endl;
                        }
                                
                        getch();
                        system("cls");
                    }
                }         
            }
            else{
                    cout << "No es posible modificar. No hay civilizaciones registradas" << endl;
            }
        }
        else if(str == "11"){
            if(vg.total() > 0){
                vg.mostrar();
            }else{
                cout << "No hay civilizaciones registradas" << endl;
            }
        }
        else if(str == "12"){
            if(vg.total() > 0){
                vg.respaldar_civ();
            }else{
                cout << "No hay civilizaciones registradas. Error al respaldar" << endl;
            }
        }
        else if(str == "13"){
            vg.recuperar_civ();
        }
        else if(str == "14"){
            cout << "Fin del programa";
        }
        else{
            cout << "Opcion invalida" << endl;
        }

        cout << endl;
        system("pause");
        system("cls");

    }while(str != "14");
    
    return 0;
}