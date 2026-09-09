#include <iostream>
#include <windows.h>
using namespace std;

string abrirCofre(bool tieneLlave)
{
    string respuesta = "";
    if (tieneLlave == true)
    {
        respuesta = "Cofre Abierto!";
    }
    else
    {
        respuesta = "Vaya a buscar la llave!";
    }

    return respuesta;
}

string entrarArea(int nivel, bool tieneLlave)
{
    string respuesta = "";
    if (nivel >= 7 && tieneLlave == true)
    {
        respuesta = "Ingresando al área!";
    }
    else
    {
        respuesta = "No puede ingresar aun...";
    }

    return respuesta;
}

string mostrarFichaTecnica(string nombre, int vida, int edad, int nivel, float rating, bool llave)
{
    string respuesta = "";
    cout << "" << endl;
    cout << "Ficha Técnica Inicial" << endl;
    cout << "=============" << endl;
    cout << "Nombre Personaje: " << nombre << endl;
    cout << "Vida Personaje: " << vida << endl;
    cout << "Edad Personaje: " << edad << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Rating: " << rating << endl;
    cout << "Abrir Cofre: " << abrirCofre(llave) << endl;
    cout << "Area Nivel 7\nBloqueada con llave" << endl;
    cout << "Ingresa? " << entrarArea(nivel, llave) << endl;
    return respuesta;
}

int main()
{
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
    float ratingDelfin = 49.5;
    bool llaveDelfin = false;
    int nivelDelfin = 1;

    // Definición del Enemigo
    string nombreTigresa = "Tigresa del Oriente";
    int vidaTigresa = 500;
    int edadTigresa = 80;
    bool esAlcaldeTigresa = false;
    float ratingTigresa = 55.0;
    bool llaveTigresa = false;
    int nivelTigresa = 1;

    // Con esta línea muestro un mensaje mediante el terminal
    cout << "Buen día queridos estudiantes" << endl;

    mostrarFichaTecnica(nombreDelfin, vidaDelfin, edadDelfin, nivelDelfin, ratingDelfin, llaveDelfin);
    mostrarFichaTecnica(nombreTigresa, vidaTigresa, edadTigresa, nivelTigresa, ratingTigresa, llaveTigresa);

    cout << "\n"
         << endl;

    // Un ciclo WHILE se ejecuta mientras se cumpla una condición
    // while (vidaDelfin > 0 && vidaTigresa > 0)
    // {
    //     if (ratingTigresa > vidaDelfin){
    //         vidaDelfin = 0;
    //     }else{
    //         vidaDelfin = vidaDelfin - ratingTigresa;
    //     }

    //     if(ratingDelfin > vidaTigresa){
    //         vidaTigresa = 0;
    //     }else{
    //         vidaTigresa = vidaTigresa - ratingDelfin;
    //     }

    //     cout << "Vida Delfin: " << vidaDelfin << endl;
    //     cout << "Vida Tigresa: " << vidaTigresa << endl;
    // }

    // Un ciclo FOR se ejecuta una determinada cantidad de veces
    for (int i = 0; i < 5; i++)
    {
        vidaDelfin = vidaDelfin - ratingTigresa;
        vidaTigresa = vidaTigresa - ratingDelfin;
        cout << "Vida Delfin: " << vidaDelfin << endl;
        cout << "Vida Tigresa: " << vidaTigresa << endl;
    }

    if (vidaDelfin > vidaTigresa)
    {
        nivelDelfin = 10;
        llaveDelfin = true;
    }
    else
    {
        nivelTigresa = 10;
        llaveTigresa = true;
    }

    mostrarFichaTecnica(nombreDelfin, vidaDelfin, edadDelfin, nivelDelfin, ratingDelfin, llaveDelfin);
    mostrarFichaTecnica(nombreTigresa, vidaTigresa, edadTigresa, nivelTigresa, ratingTigresa, llaveTigresa);
    return 0;
}