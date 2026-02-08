#include <cajero.h>
#include <iostream>
using namespace std;

void menuPrincipal();
void menuAdministrador(string);
void menuUsuario(string);

int main() {

    int opcion = -1;
    string nombre, clave;
    Cajero cajero = Cajero("015");

    while (opcion != 0) {
        menuPrincipal();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                while(nombre != "0") {
                    cout << "Ingrese el nombre del administrador (0 - Salir); ";
                    cin >> nombre;
                    cout << "Ingrese la clave del administrador: ";
                    cin >> clave;

                    optional<Administrador> existeAdministrador = cajero.verificarAdministrador(nombre, clave);

                    if(existeAdministrador.has_value()) {
                        int opcionA;

                        Administrador administrador = existeAdministrador.value();
                        menuAdministrador(administrador.getNombre());

                        cout << "Ingrese: ";
                        cin >> opcionA;

                        switch (opcionA) {
                            case 1: {
                                Usuario newUsuario = administrador.agregarUsuario();
                                cajero.agregarNuevoUsuario(newUsuario);
                                break;
                            }
                            case 2: {
                                cout << "Ingrese el nombre del Usuario: ";
                                cin >> nombre;
                                cout << "Ingrese la Clave del Usuario: ";
                                cin >> clave;

                                optional<Usuario> usuario = cajero.verificarUsuario(nombre, clave);

                                if (usuario.has_value()) {
                                    cajero.eliminarUnUsurio(usuario.value());
                                }
                            }
                            default:
                                cout << "La opcion " << opcionA << " NO existe en el Menu";
                                break;
                        }

                    } else {
                        continue;
                    }
                }
                break;
            case 2:
                while (nombre != "0"){
                    cout << "Ingrese el nombre del Usuario: ";
                    cin >> nombre;
                    cout << "Ingrese la clave del Usuario: ";
                    cin >> clave;

                    optional<Usuario> usuarioOptional = cajero.verificarUsuario(nombre, clave);

                    if (usuarioOptional.has_value()) {
                        int opcionUsuario;
                        Usuario usuario = usuarioOptional.value();

                        menuUsuario(usuario.getNombre());
                        cout << "Ingrese una opcion: ";
                        cin >> opcionUsuario;
                        int cantidadDinero;
                        switch (opcionUsuario) {
                            case 1:

                                cout << "Ingrese la Cantidad que decea retirar: ";
                                cin >> cantidadDinero;

                                usuario.retirarSaldo(cantidadDinero);
                                cajero.actualizarSaldo(usuario);

                                break;
                            case 2:
                                cout << "Ingrese la Cantidad de dinero que decea consignar: ";
                                cin >> cantidadDinero;

                                usuario.consignarSaldo(cantidadDinero);
                                cajero.actualizarSaldo(usuario);
                            case 3:{
                                string claveActual;
                                cout << "Ingrese la Clave actual: ";
                                cin >> claveActual;

                                usuario.cambiarClave(claveActual);
                                cajero.actualizarClave(usuario);
                            }
                            default:
                                cout << "La opcion " << opcionUsuario << " NO se encuentra en el menu..." << endl;
                                break;
                        }
                    }
                }

                break;
            default:
                break;
        }
    }
    return 0;
}

void menuPrincipal () {
    cout << "***************************************" << endl;
    cout << "*          ----> CAJERO <----         *" << endl;
    cout << "***************************************" << endl;
    cout << "*     1. Entrar como administrador    *" << endl;
    cout << "*     2. Entrar como Usuario          *" << endl;
    cout << "*     0. Salir                        *" << endl;
    cout << "***************************************" << endl;
}

void menuAdministrador (string nombreAdministrador) {
    cout << "***************************************" << endl;
    cout << "* Bienvenido(a)* " << nombreAdministrador << " *" <<  endl;
    cout << "***************************************" << endl;
    cout << "*     1. Agregar un usuario nuevo     *" << endl;
    cout << "*     2. Eliminar un usuario          *" << endl;
    cout << "*     0. Salir                        *" << endl;
    cout << "***************************************" << endl;
}

void menuUsuario (string nombreUsuario) {
    cout << "***************************************" << endl;
   cout << "* Bienvenido(a)        " << nombreUsuario <<"*" <<  endl;
    cout << "***************************************" << endl;
    cout << "*     1. Retirar dinero               *" << endl;
    cout << "*     2. Consignar dinero             *" << endl;
    cout << "*     3. Cambiar clave                *" << endl;
    cout << "*     0. Salir                        *" << endl;
    cout << "***************************************" << endl;
}
