#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

class Personaje{
    // Los ATRIBUTOS de la clase son privados, sólo pertenecen a la clase
    // Los ATRIBUTOS indican CÓMO ES LA CLASE
    private:
        string nombrePersonaje;
        int vidaPersonaje;
        bool personajeVivo;
        int danioPersonaje;

    // Para acceder a los atributos privados de la clase, crearemos MÉTODOS públicos
    // Los MÉTODOS indican QUE PUEDE HACER UN OBJETO DE ESA CLASE
    public:
        // EL CONSTRUCTOR creará objetos basados en la clase cuando INSTANCIAMOS (invocamos) la clase
        // Este nos permite manejar el concepto ENCAPSULACIÓN
        Personaje(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador):
            nombrePersonaje(nombreJugador), vidaPersonaje(vidaJugador), personajeVivo(estaVivo), danioPersonaje(danioJugador){}

        void avanzar(string nombrePersonaje)
        {
            cout << nombrePersonaje << " avanza..." << endl;
        }

        void saltar(string nombrePersonaje)
        {
            cout << nombrePersonaje << " salta..." << endl;
        }

        void recibirDanio(string nombrePersonaje, int danio)
        {
            vidaPersonaje -= danio;

            if (vidaPersonaje < 0)
            {
                vidaPersonaje = 0;
                personajeVivo = false;
            }

            cout << nombrePersonaje << " recibió " << danio << " de daño." << endl;
            cout << "Su vida restante es " << vidaPersonaje << "." << endl;
        }

        void verEstado(string nombrePersonaje)
        {
            string alerta = "";
            if (0 < vidaPersonaje && vidaPersonaje <= 30)
            {
                alerta = "Vida demasiado baja!";
            }
            else
            {
                alerta = "";
            }

            cout << "Estado de " << nombrePersonaje << endl;
            cout << "Vida restante: " << vidaPersonaje << endl;
            cout << "Está Vivo? " << (personajeVivo == true ? "Si" : "No") << endl;
            cout << alerta << endl;
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int opcion = 0;
    string nombre = "";
    int vida = 0;
    bool vivo = true;
    int danio = 0;

    cout << "Indique el nombre de su personaje:" << endl;
    cin >> nombre;
    cout << "Indique la vida incial de " << nombre << ":" << endl;
    cin >> vida;
    
    // INSTANCIA de la clase
    Personaje jugador(nombre, vida, vivo, danio);

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
                jugador.avanzar(nombre);
                break;
            case 2:
                jugador.saltar(nombre);
                break;
            case 3:
                cout << "Ingrese el daño a recibir: " << endl;
                cin >> danio;
                jugador.recibirDanio(nombre,danio);
                break;
            case 4:
                jugador.verEstado(nombre);
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