#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego():

jugador("Phoenix", 100, 15)

{
    for (int i = 0; i < 10; i++)
    {
        enemigos.emplace_back(to_string(i), 50, 5);
    }

    enemigos.emplace_back("Estrella de la Muerte", 300, 10);
}

void Juego::iniciar(){
    cout << "Space Defenders ADV-N2-C1 2026" << endl;

    cout << "Comienza la batalla!" << endl;

    for (auto& enemigo : enemigos)
    {
        cout << "Aparece " << enemigo.getNombre() << endl;

        while (jugador.estaViva() && enemigo.getVida() > 0)
        {
            jugador.disparar(&enemigo);
            enemigo.verEstado();

            if(enemigo.estaViva()){
                enemigo.disparar(&jugador);
                jugador.verEstado();
            }
        }
        
        if (!jugador.estaViva())
        {
            cout << "Game Over!" << endl;
            return;
        }
        
        if (!enemigo.estaViva())
        {
            cout << "Enemigo " << enemigo.getNombre() << " destruido..." << endl;
        }        
    }
    
    cout << jugador.getNombre() << " se ha alzado con la vitoria!" << endl;
    cout << "Eres el combatiente supremo de SpaceDefenders!" << endl;
}
