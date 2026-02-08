#include <administrador.h>

Administrador::Administrador(string nombre, string contrasenia) {
    this->nombre = nombre;
    this->contrasenia = contrasenia;
}

Usuario Administrador::agregarUsuario() {
    string nombre, clave;
    long int saldo;

    cout << "Ingrese el NOMBRE del nuevo Usuario: ";
    cin >> nombre;
    cout << "Ingrese la CLAVE del nuevo Usuario: ";
    cin >> clave;
    cout << "Ingrese el SALDO del nuevo Usuario: ";
    cin >> saldo;

    Usuario nuevoUsuario = Usuario(nombre, clave, saldo);
    cout << "El nuevo Usuario " << nuevoUsuario.getNombre() << " ha sido creado exitozamente." << endl;
    return nuevoUsuario;
}

/*vector<Usuario> Administrador::eliminarUsuario(string nombre, vector<Usuario> datosUsuarios) {
    vector<Usuario> datosUsuariosEditado;

    for(auto datos : datosUsuarios) {
        if (datos.getNombre() != nombre) {
            datosUsuariosEditado.push_back(datos);
        } else {
            cout << "Usuario eliminado exitozamente!..." << endl;
        }
    }
    for(auto i = datosUsuarios.begin(); i != datosUsuarios.end();) {
        if (i->getNombre() == nombre) {
            datosUsuarios.erase(i); ---------------------- CODIGO OPTIMIZADO PARA UN FUTURO. -------------------
            cout << "Usuario eliminado exitozamente!..." << endl;
            break;
        }
    }
    return datosUsuariosEditado;
}*/

string Administrador::getNombre() const
{
    return nombre;
}

void Administrador::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string Administrador::getContrasenia() const
{
    return contrasenia;
}

void Administrador::setContrasenia(const string &newContrasenia)
{
    contrasenia = newContrasenia;
}
