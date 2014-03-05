#ifndef ARISTA_H
#define ARISTA_H
#include "nodo.h"
#include <iostream>
using namespace  std;

class Nodo;
class Arista
{
public:

    Nodo *destino;//puntero al nodo de llegada
    Arista *sgte;
    Arista();
};

#endif // ARISTA_H
