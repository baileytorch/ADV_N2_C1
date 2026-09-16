#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

// Variables globales
int vida = 100;
bool vivo = true;
int danio = 0;

void avanzar(){
    cout << "Poo avanza..." << endl;
}

void saltar(){
    cout << "Poo salta..." << endl;
}

void recibirDanio(int danio){
    // vida = vida - danio;
    // Forma abreviada de realizar una operación aritmética de suma o resta
    vida -= danio;

    if (vida < 0) {
        vida = 0;
        vivo = false;
    }

    cout << "Poo recibió " << danio << " de daño." << endl;
    cout << "Su vida restante es " << vida << "." << endl;
}

void verEstado(){
    string alerta = "";
    if (0 < vida < 30) alerta = "Vida demasiado baja!";

    cout << "Estado de Poo" << endl;
    cout << "Vida restante: " << vida << endl;
    cout << "Está Vivo? " << (vivo == true ? "Si": "No") << endl;
    cout << alerta << endl;
    alerta = "";
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int opcion = 0;

    while (opcion != 5 && vivo)
    {
        cout << "\nSeleccione su opción" << endl;
        cout << "[1] Avanzar." << endl;
        cout << "[2] Saltar." << endl;
        cout << "[3] Recibir Daño." << endl;
        cout << "[4] Revisar Estado Poo." << endl;
        cout << "[5] Salir." << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                avanzar();
                break;
            case 2:
                saltar();
                break;
            case 3:
                cout << "Ingrese el daño a recibir: " << endl;
                cin >> danio;
                recibirDanio(danio);
                break;
            case 4:
                verEstado();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                exit(0);
                break;
            default:
                cout << "Opción ingresada NO corresponde...\nIntente nuevamente..." << endl;
        }
    }
    

    return 0;
}