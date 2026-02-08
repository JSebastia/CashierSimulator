#include <cajero.h>

Cajero::Cajero(string modelo){
    this->modelo = modelo;
    //Inicializar datos administradores
    Administrador administrador1 = Administrador("Carlos", "1234f");
    Administrador administrador2 = Administrador("Maria", "3456g");

    datosAdministrador.push_back(administrador1);
    datosAdministrador.push_back(administrador2);
    //Inicializar datos Usuarios
    Usuario usuario1 = Usuario("Juan", "1234", 100000);
    Usuario usuario2 = Usuario("Juana", "1294", 1000000);
    Usuario usuario3 = Usuario("Sebastian", "4654", 500000);

    datosUsuarios.push_back(usuario1);
    datosUsuarios.push_back(usuario2);
    datosUsuarios.push_back(usuario3);
}

optional<Administrador> Cajero::verificarAdministrador(string nombre, string contrasenia) {

    for (int i = 0; i < datosAdministrador.size(); i++) {
        Administrador admin = datosAdministrador[i];
        if (admin.getNombre() == nombre) {
            if (admin.getContrasenia() == contrasenia) {
                cout << "Ingreso exitozo!!" << endl;
                return admin;
            } else {
                cout << "X ----> La contrasenia esta incorrecta." << endl;
                return nullopt;//Indica que el optional esta vacio.
            }
        }
    }
    cout << "X ----> El Administrador esta incorrecto o no existe en la base de datos..." << endl;
    return nullopt;
}

//Se usa optional, ya que puede existir o no existir el usuario.
optional<Usuario> Cajero::verificarUsuario(string nombre, string clave) {

    for (auto datos : datosUsuarios) {
        if (datos.getNombre() == nombre) {
            if (datos.getClave() == clave) {
                cout << "Ingreso exitozo!!" << endl;
                cout << "Bienvenido(a) " << nombre << endl;
                return datos;
            } else {
                cout << "X ----> La contrasenia esta incorrecta." << endl;
                return nullopt; //Indica que el optional esta vacio.
            }
        }
    }
    cout << "X ----> El Usuario esta incorrecto o no existe en la base de datos..." << endl;
    return nullopt; //Indica que el optional esta vacio.
}

void Cajero::agregarNuevoUsuario(Usuario newUsuario) {
    datosUsuarios.push_back(newUsuario);
}

void Cajero::eliminarUnUsurio(Usuario usuario) {

    for(auto i = datosUsuarios.begin(); i != datosUsuarios.end(); i++) {
        if (i->getNombre() == usuario.getNombre()) {
            datosUsuarios.erase(i);
            break;
        }
    }

    cout << "El Usuario con nombre " << usuario.getNombre() << " fue eliminado exitozamente..." << endl;

    /*for (auto i = 0; i < datosUsuarios.size(); i++) {
        if (datosUsuarios[i].getNombre() == usuario.getNombre()) {
            datosUsuarios.erase(i);
            break;
        }
    }*/
}

void Cajero::actualizarSaldo(Usuario usuario) {

    for(int i = 0; i < datosUsuarios.size(); i++) {
        if (datosUsuarios.at(i).getNombre() == usuario.getNombre()) {
            datosUsuarios.at(i).setSaldo(usuario.getSaldo());
            break;
        }
    }
}

void Cajero::actualizarClave(Usuario usuario) {
    for(int i = 0; i < datosUsuarios.size(); i++) {
        if (datosUsuarios.at(i).getNombre() == usuario.getNombre()) {
            datosUsuarios.at(i).setClave(usuario.getClave());
            cout << "- CAJERO -" << datosUsuarios.at(i).getNombre() << " tiene nuevaClave de: " << datosUsuarios.at(i).getClave() << endl;
            break;
        }
    }
}

