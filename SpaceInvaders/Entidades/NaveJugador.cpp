#include "NaveJugador.h"
#include <iostream>

NaveEnemigo::NaveEnemigo(string nombre):
Nave(nombre,100,15){
    escudo = 10;
};

void NaveEnemigo::disparar(Nave* objetivo){
    cout << nombre << " dispara a " << objetivo->getNombre() << endl;

    objetivo->recibirDanio(ataque);
}

void NaveEnemigo::reparar(){
    vida += 20;

    if(vida >= 100){
        vida = 100;
    }
}