#include "NaveEnemigo.h"
#include <iostream>

NaveEnemigo::NaveEnemigo(string nombre, int vida, int ataque):
Nave(nombre,vida,ataque){};

void NaveEnemigo::disparar(Nave* objetivo){
    cout << nombre << " dispara a " << objetivo->getNombre() << endl;

    objetivo->recibirDanio(ataque);
}