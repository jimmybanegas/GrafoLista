#ifndef GRAFO_H
#define GRAFO_H
#include "nodo.h"
#include "arista.h"
#include <iostream>
using namespace  std;

class Grafo
{
public:
    Nodo *p;

    void menu();
    void insertar_nodo();
    void agrega_arista(Nodo *aux, Nodo *aux2, Arista *nuevo);
    void insertar_arista();
    void vaciar_aristas(Nodo *aux);
    void eliminar_nodo();
    void eliminar_arista();
    void mostrar_grafo();
    void mostrar_aristas();

    Grafo();
};

#endif // GRAFO_H
