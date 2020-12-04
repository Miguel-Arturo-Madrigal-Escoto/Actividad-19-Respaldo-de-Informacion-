#include <iostream>
#include <cstdlib>
#include "civilizacion.h"
#include "videogame.h"

using namespace std;

void menuCivilizacion(Civilizacion& civ){
    VideoGame vg;
    Aldeano a;
    string str;

    while(true)
    {
        system("cls");
        cout << "Civilizacion encontrada: " << endl;
        vg.encabezado_tabla();
        cout << civ << endl;

        /// submenu aldeanos
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeanos" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << "Elige una opcion: ";
        getline(cin, str);

        if(str == "0"){
            break;
        }
        else if(str == "1"){
            cout << "1) Agregar el objeto aldeano al inicio." << endl;
            cout << "2) Agregar el objeto aldeano al final." << endl;
            cout << "Elige una opcion: ";
            getline(cin, str);

            if(str != "1" && str != "2"){
                cout << "Opcion invalida" << endl;
            }
            else{
                cin >> a;

                if(str == "1"){
                    civ.agregarInicio(a);
                    civ.setPuntuacion(civ.getPuntuacion() + 100);
                }
                else if(str == "2"){
                    civ.agregarFinal(a);
                    civ.setPuntuacion(civ.getPuntuacion() + 100);
                }            
            } 
        }
        else if(str == "2"){
            if(civ.vacia()){
                cout << "No se puede eliminar. La lista esta vacia" << endl;
            }
            else{
                cout << "1) Eliminar por nombre" << endl;
                cout << "2) Eliminar con salud menor a: ?" << endl;
                cout << "3) Eliminar con edad mayor o igual a 60" << endl;
                cout << "Elige una opcion: ";
                getline(cin, str);

                if(str == "1"){
                    cout << "Aldeano a eliminar: ";
                    getline(cin, str);
                    civ.eliminarNombre(str);
                }
                else if(str == "2"){
                    float salud;
                    cout << "Eliminar aldeanos con salud menor a: ";
                    cin >> salud; cin.sync();
                                    
                    civ.eliminarSalud(salud);
                }
                else if(str == "3"){
                    civ.eliminarEdad();
                }
                else{
                    cout << "Opcion invalida" << endl;
                }
            }
        }
        else if(str == "3"){
            if(civ.vacia()){
                cout << "No se puede clasificar. La lista esta vacia" << endl;
            }
            else{
                cout << "1) Clasificar la lista de aldeanos por nombre (ascendente)" << endl;
                cout << "2) Clasificar la lista de aldeanos por edad (descendente)" << endl;
                cout << "3) Clasificar la lista de aldeanos por salud (descendente)" << endl;
                cout << "Elige una opcion: ";
                getline(cin, str);

                if(str == "1"){
                    civ.clasificarNombre();
                }
                else if(str == "2"){
                    civ.clasificarEdad();
                }
                else if(str == "3"){
                    civ.clasificarSalud();
                }
                else{
                    cout << "Opcion invalida" << endl;
                }
            }
        }
        else if(str == "4"){
            if(civ.vacia()){
                cout << "No se puede buscar. La lista esta vacia" << endl;
            }
            else{
                cout << "Aldeano a buscar: ";
                getline(cin, str);
                a.setNombre(str);

                Aldeano* ptr = civ.buscarAldeano(a);

                if(ptr == nullptr){
                    cout << "Aldeano no encontrado" << endl;
                }else{
                    cout << "Aldeano encontrado: " << endl;
                    civ.encabezado_aldeano();
                    cout << *ptr << endl;
                }
            }
        }
        else if(str == "5"){
            if(civ.vacia()){
                cout << "No se puede modificar. La lista esta vacia" << endl;
            }
            else{
                cout << "Aldeano a modificar: ";
                getline(cin, str);
                a.setNombre(str);

                Aldeano* ptr = civ.buscarAldeano(a);

                if(ptr == nullptr){
                    cout << "Aldeano no encontrado" << endl;
                }else{
                    cout << "Aldeano encontrado: " << endl;
                    
                    while(true)
                    {
                        system("cls");
                        civ.encabezado_aldeano();
                        cout << *ptr << endl;

                        cout << "1) Modificar nombre" << endl;
                        cout << "2) Modificar edad" << endl;
                        cout << "3) Modificar genero" << endl;
                        cout << "4) Modificar salud" << endl;
                        cout << "0) Volver al menu" << endl;
                        cout << "Elige una opcion: ";
                        getline(cin, str);

                        if(str == "0"){
                            break;
                        }
                        else if(str == "1"){
                            cout << "Nuevo nombre: ";
                            getline(cin, str);
                            ptr->setNombre(str);
                            
                            cout << " * Aldeano actualizado *" <<endl;
                        }
                        else if(str == "2"){
                            size_t edad;
                            cout << "Nueva edad: ";
                            cin >> edad; cin.sync();
                            ptr->setEdad(edad);

                            cout << " * Aldeano actualizado *" <<endl;
                        }
                        else if(str == "3"){
                            cout << "Nuevo genero: ";
                            getline(cin, str);
                            ptr->setGenero(str);
                            
                            cout << " * Aldeano actualizado *" <<endl;
                        }
                        else if(str == "4"){
                            float salud;
                            cout << "Nueva salud: ";
                            cin >> salud; cin.sync();
                            ptr->setSalud(salud);

                            cout << " * Aldeano actualizado *" <<endl;
                        }
                        else{
                            cout << "Opcion invalida" << endl;
                        }
                        system("pause");
                    }
                }
            }
        }
        else if(str == "6"){
            if(civ.vacia()){
                cout << "No hay aldeanos. La lista esta vacia" << endl;
            }
            else{
                civ.mostrarAldeanos();
            }
        }
        else{
            cout << "Opcion invalida" << endl;
        }

        system("pause");
        system("cls");
    }
}
                       