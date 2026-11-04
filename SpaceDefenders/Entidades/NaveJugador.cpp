#include "NaveJugador.h"
#include <iostream>

NaveJugador::NaveJugador(string nombre, int vida, int ataque):
Nave(nombre,vida,ataque){
    escudo = 10;
};

void NaveJugador::disparar(Nave* objetivo){
    cout << nombre << " dispara a " << objetivo->getNombre() << endl;

    objetivo->recibirDanio(ataque);
}

void NaveJugador::reparar(){
    vida += 20;

    if(vida >= 100){
        vida = 100;
    }
}