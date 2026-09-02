#include <iostream>
#include <windows.h>
using namespace std;

string abrirCofre(bool tieneLlave){
    string respuesta = "";
    if (tieneLlave == true)
    {
        respuesta = "Cofre Abierto!";
    }else{
        respuesta = "Vaya a buscar la llave!";
    }
    
    return respuesta;
}

int main(){
    // Esto es un comentario de 1 línea
    /*
    Esto es un comentario de múltiples líneas
    */

    // Configurar la salida de la consola a UTF-8, nuestro set de caracteres
    SetConsoleOutputCP(CP_UTF8);

    // Definición de nuestro Personaje
    string nombreDelfin = "Delfin Quispe";
    int vidaDelfin = 500;
    int edadDelfin = 48;
    bool esAlcaldeDelfin = false;
    float ratingDelfin = 2.36;
    bool tieneLlave = false;

    // Definición del Enemigo
    string nombreTigresa = "Tigresa del Oriente";
    int vidaTigresa = 500;
    int edadTigresa = 80;
    bool esAlcaldeTigresa = false;
    float ratingTigresa = 4.0;

    // Con esta línea muestro un mensaje mediante el terminal
    cout << "Buen día queridos estudiantes" << endl;

    cout << "Ficha Técnica Inicial" << endl;
    cout << "=============" << endl;
    cout << "Nombre Personaje: " << nombreDelfin << endl;
    cout << "Vida Personaje: " << vidaDelfin << endl;
    cout << "Edad Personaje: " << edadDelfin << endl;
    cout << "Es alcalde: " << esAlcaldeDelfin << endl;
    cout << "Rating: " << ratingDelfin << endl;
    cout << "Abrir Cofre: " << abrirCofre(tieneLlave) << endl;

    cout << "\n" <<endl;
    int vidaFinal = 0;
    vidaFinal = vidaDelfin - ratingTigresa;
    vidaDelfin = vidaFinal;
    tieneLlave = true;

    cout << "Ficha Técnica Final" << endl;
    cout << "=============" << endl;
    cout << "Nombre Personaje: " << nombreDelfin << endl;
    cout << "Vida Personaje: " << vidaDelfin << endl;
    cout << "Edad Personaje: " << edadDelfin << endl;
    cout << "Es alcalde: " << esAlcaldeDelfin << endl;
    cout << "Rating: " << ratingDelfin << endl;
    cout << "Abrir Cofre: " << abrirCofre(tieneLlave) << endl;
    return 0;
}