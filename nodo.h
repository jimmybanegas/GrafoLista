#ifndef NODO_H
#define NODO_H
#include "arista.h"
#include <iostream>
using namespace  std;

class Arista;
class Nodo
{
public:
    char nombre;//nombre del vertice o nodo
    Nodo *sgte;
    Arista *ady;//puntero hacia la primera arista del nodo
    Nodo();
};

#endif // NODO_H
