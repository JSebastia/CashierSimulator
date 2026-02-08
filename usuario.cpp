#include <usuario.h>

Usuario::Usuario(){}

Usuario::Usuario(string nombre, string clave, long int saldo) {

    this->nombre = nombre;
    this->clave = clave;
    this->saldo = saldo;
}

bool Usuario::retirarSaldo(int cantidadRetirar) {

    if (cantidadRetirar <= saldo) {
        saldo -= cantidadRetirar;
        cout << "Transaccion exitoza ---- Se retiraron " << cantidadRetirar << " COP." << endl;
        cout << "Saldo restante: " << saldo << endl;
        return true;
    } else {
        cout << "Su saldo es insuficiente. Faltan " << (cantidadRetirar - saldo) << " COP." << endl;
        return false;
    }
}

void Usuario::consignarSaldo(int saldoConsignar) {
    saldo += saldoConsignar;
    cout << "Saldo Consignado correctamente..." << endl;
    cout << "Saldo en tu cuenta: " << saldo << " COP" << endl;
}

void Usuario::cambiarClave(string claveUsuario) {
    string nuevaClave, verificarClave;

    if (claveUsuario == clave) {
        cout << "Ingrese la nueva Clave: ";
        cin >> nuevaClave;
        cout << "Ingrese nuevamente la Clave: ";
        cin >> verificarClave;

        if (verificarClave == nuevaClave) {
            clave = nuevaClave;
            cout << "Cambio de Clave, Exitozo!..." << endl;
        } else {
            cout << "Las claves no coinciden... Comience de nuevo el proceso." << endl;
        }
    }
}

string Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

long Usuario::getSaldo() const
{
    return saldo;
}

void Usuario::setSaldo(long newSaldo)
{
    saldo = newSaldo;
}

string Usuario::getClave() const
{
    return clave;
}

void Usuario::setClave(string newClave)
{
    clave = newClave;
}

