#ifndef NAVE_H
#define NAVE_H

#include <string>
using namespace std;

class Nave
{
protected:
    string nombre;
    int vida;
    int ataque;

public:
    Nave(string nom, int vid, int atq);
    virtual ~Nave();

    virtual void disparar(
        Nave *objetivo) = 0;

    void recibirDanio(int danio);

    bool estaViva() const;

    void verEstado() const;

    string getNombre() const;

    int getVida() const;

    int getAtaque() const;
};

#endif // NAVE_H