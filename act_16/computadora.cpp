#include "computadora.h"
#include <fstream>
#include <algorithm>

computadora::computadora()
{

}

void computadora::agregarPersonaje(const Personaje &p)
{
    personajes.push_back(p);
}

void computadora::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(10) << "sistema";
    cout << setw(8) << "memoria";
    cout << setw(6) << "ram";
    cout << endl;
    for (size_t i = 0; i < personajes.size(); i++) {
        Personaje &p = personajes[i];
        cout << p;
    }
}

void computadora::respaldar_tabla()
{
    ofstream archivo("componentes_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(10) << "Nombre";
        archivo << setw(10) << "sistema";
        archivo << setw(8) << "memoria";
        archivo << setw(6) << "ram";
        archivo << endl;
        for (size_t i = 0; i < personajes.size(); i++) {
            Personaje &p = personajes[i];
            archivo << p;
        }
    }
    archivo.close();
}
void computadora::respaldar()
{
    ofstream archivo("componentes.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < personajes.size(); i++) {
            Personaje &p = personajes[i];
            archivo << p.getNombre() << endl;
            archivo << p.getTipo() << endl;
            archivo << p.getFuerza() << endl;
            archivo << p.getSalud() << endl;
        }
    }
    archivo.close();
}

void computadora::recuperar()
{
    ifstream archivo("componentes.txt");
    if (archivo.is_open()) {
        string temp;
        float fuerza;
        int salud;
        Personaje p;

        while (true)
        {
            getline(archivo, temp); 
            if (archivo.eof()) {
                break;
            }
            p.setNombre(temp);

            getline(archivo, temp); 
            p.setTipo(temp);

            getline(archivo, temp);
            fuerza = stof(temp); 
            p.setFuerza(fuerza);

            getline(archivo, temp);
            salud = stoi(temp); 
            p.setSalud(salud);

            agregarPersonaje(p);            
        }
        
    }
    archivo.close();
}

void computadora::insertar(const Personaje &p, size_t pos)
{
    personajes.insert(personajes.begin()+pos, p);
}

size_t computadora::size()
{
    return personajes.size();
}

void computadora::inicializar(const Personaje &p, size_t n)
{
    personajes = vector<Personaje>(n, p);
}

void computadora::eliminar(size_t pos)
{
    personajes.erase(personajes.begin()+pos);
}

void computadora::ordenar()
{
    sort(personajes.begin(), personajes.end());
}
void computadora::ordenarTipo()
{
    sort(personajes.begin(), personajes.end(), 
    [](Personaje p1, Personaje p2){return p1.getTipo() < p2.getTipo();});
}
void computadora::ordenarSalud()
{
    sort(personajes.begin(), personajes.end(),
    [](Personaje p1, Personaje p2){return p1.getSalud() > p2.getSalud();});
}
void computadora::ordenarFuerza()
{
    sort(personajes.begin(), personajes.end(),
    [](Personaje p1, Personaje p2){return p1.getFuerza() < p2.getFuerza();});
}

Personaje* computadora::buscar(const Personaje &p)
{
    auto it = find(personajes.begin(), personajes.end(), p);

    if (it == personajes.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}
