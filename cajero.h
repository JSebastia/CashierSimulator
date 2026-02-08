#ifndef CAJERO_H
#define CAJERO_H

#include <usuario.h>
#include <administrador.h>
#include <vector>
#include <optional>
#include <iostream>
using namespace std;

class Cajero {
    private:
        string modelo;
        vector<Administrador> datosAdministrador;
        vector<Usuario> datosUsuarios;
    public:
        Cajero(string);
        optional<Usuario> verificarUsuario(string, string);
        optional<Administrador> verificarAdministrador(string , string);

        void agregarNuevoUsuario(Usuario);
        void eliminarUnUsurio(Usuario);

        void actualizarSaldo(Usuario);
        void actualizarClave(Usuario);
};
#endif // CAJERO_H
