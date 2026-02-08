#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <usuario.h>
#include <vector>
#include <iostream>
using namespace std;

class Administrador {
    private:
        string nombre;
        string contrasenia;
    public:
        Administrador(string, string);
        Usuario agregarUsuario();

        string getNombre() const;
        void setNombre(const string &newNombre);
        string getContrasenia() const;
        void setContrasenia(const string &newContrasenia);
    };
#endif // ADMINISTRADOR_H
