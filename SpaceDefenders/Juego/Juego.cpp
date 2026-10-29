#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego():

jugador("Phoenix")

{
    for (int i = 0; i < 10; i++)
    {
        NaveEnemigo enemigo(to_string(i), 50, 5);
        enemigos.push_back(enemigo);
    }

    NaveEnemigo jefeFinal("Estrella de la Muerte", 300, 10);
    enemigos.push_back(jefeFinal);    
}

void Juego::iniciar(){
    cout << "Sapce Defenders 2026" << endl;

    cout << "Comienza la batalla!" << endl;

    for (auto enemigo : enemigos)
    {
        cout << "Aparece " << enemigo.getNombre() << endl;

        while (jugador.estaViva() && enemigo.getVida() > 0)
        {
            // jugador.disparar();
        }
        
    }
    
}