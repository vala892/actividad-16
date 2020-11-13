#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include "laboratorio.h"
#include <vector>

class computadora
{
    vector<Personaje> personajes;

public:
    Videojuego();
    void agregarPersonaje(const Personaje &p);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Personaje &p, size_t pos);
    size_t size();
    void inicializar(const Personaje &p, size_t n);
    void eliminar(size_t pos);
    void ordenar(); 
    void ordenarTipo();
    void ordenarFuerza();
    void ordenarSalud();
    Personaje* buscar(const Personaje &p);

    friend computadora& operator<<(computadora &v, const Personaje &p)
    {
        v.agregarPersonaje(p);

        return v;
    }
};

#endif

