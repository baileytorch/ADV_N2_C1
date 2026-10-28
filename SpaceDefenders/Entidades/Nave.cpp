#include "Nave.h"
#include <iostream>
using namespace std;

Nave::Nave(string nom, int vid, int atq)
{
    this->nombre = nom;
    this->vida = vid;
    this->ataque = atq;
}

Nave::~Nave()
{
    // Destructor implementation (if needed)
}

void Nave::recibirDanio(int danio)
{
    this->vida -= danio;
    if (this->vida < 0)
    {
        this->vida = 0;
    }
}

bool Nave::estaViva() const
{
    if (this->vida > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // return this->vida > 0;
}

void Nave::verEstado() const
{
    cout << "Nombre: " << this->nombre << endl;
    cout << "Vida: " << this->vida << endl;
    cout << "Ataque: " << this->ataque << endl;
}

string Nave::getNombre() const
{
    return this->nombre;
}

int Nave::getVida() const
{
    return this->vida;
}

int Nave::getAtaque() const
{
    return this->ataque;
}