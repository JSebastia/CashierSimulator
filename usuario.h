#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;

class Usuario {
    private:
        string nombre;
        string clave;
        long int saldo;
    public:
        Usuario();
        Usuario(string, string, long int);
        bool retirarSaldo(int);
        void consignarSaldo(int);
        void cambiarClave(string);

        string getClave() const;
        void setClave(string newClave);
        string getNombre() const;
        void setNombre(const string &newNombre);
        long getSaldo() const;
        void setSaldo(long newSaldo);
};
#endif // USUARIO_H
