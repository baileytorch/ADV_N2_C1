#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Equipamiento
{
    private:
        string nombreItem;
        string descripcionItem;
        int calidadItem;
        int cantidadUsoItem;
        int vidaItem;
    public:
        Equipamiento(string nombre,string descripcion,int calidad,int cantidadUso,int vida): 
            nombreItem(nombre), descripcionItem(descripcion), calidadItem(calidad), cantidadUsoItem(cantidadUso), vidaItem(vida){}
        
        string obtenerNombreItem() { return nombreItem;}
};

class Personaje{
    private:
        string nombrePersonaje;
        int vidaPersonaje;
        bool personajeVivo;
        int danioPersonaje;
        vector<Equipamiento> items;

    public:
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

        void obtenerEquipamiento(Equipamiento item){
            if(items.size() <= 6){
                items.push_back(item);
                cout << "Item obtenido: " << item.obtenerNombreItem() << endl;
            }
        }

        // void mostrarInventario() {
        //     cout << "Inventario actual: " << endl;
        //     for (const auto& equipo : items) {
        //         cout << "- " << equipo.obtenerNombreItem() << endl;
        //     }
        // }
};

// HERENCIA, la nueva clase tipo de personaje HEREDA desde Personaje...
// ya tiene un nombre, una cantidad de vida, esta vivo, recibirá daño y tendrá equipamiento
// pero cada tipo de personaje tendrá una forma distinta de atacar
class Guerrero : public Personaje
{
    private:
        /* data */
    public:
        void atacar(){
            cout << "Ataca con espada" << endl;
        }
};

class Arquero : public Personaje
{
    private:
        /* data */
    public:
        void atacar(){
            cout << "Ataca con arco y flecha" << endl;
        }
};

class Mago : public Personaje
{
    private:
        /* data */
    public:
        void atacar(){
            cout << "Ataca con varita" << endl;
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // Datos Personaje
    int opcion = 0;
    string nombrePersonaje = "";
    int vidaPersonaje = 0;
    bool personajeVivo = true;
    int danioPersonaje = 0;

    // Datos Equipamiento
    string nombreEquipamiento = "Pergamino de Fuerza";
    string descripcionEquipamiento = "Aumenta la fuerza del personaje en 10";
    int calidadEquipamiento = 10;
    int cantidadUso = 1;
    int vidaEquipamiento = 0;

    cout << "Indique el nombre de su personaje:" << endl;
    getline(cin, nombrePersonaje);
    cout << "Indique la vida incial de " << nombrePersonaje << ":" << endl;
    cin >> vidaPersonaje;
    
    Personaje jugador(nombrePersonaje, vidaPersonaje, personajeVivo, danioPersonaje);
    Equipamiento pergamino(nombreEquipamiento,descripcionEquipamiento,calidadEquipamiento,cantidadUso,vidaEquipamiento);

    while (opcion != 5 && personajeVivo)
    {
        cout << "\nSeleccione su opción" << endl;
        cout << "[1] Avanzar." << endl;
        cout << "[2] Saltar." << endl;
        cout << "[3] Recibir Daño." << endl;
        cout << "[4] Revisar Estado " << nombrePersonaje << "." << endl;
        cout << "[5] Entregar Pergamino." << endl;
        cout << "[6] Salir." << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                jugador.avanzar(nombrePersonaje);
                break;
            case 2:
                jugador.saltar(nombrePersonaje);
                break;
            case 3:
                cout << "Ingrese el daño a recibir: " << endl;
                cin >> danioPersonaje;
                jugador.recibirDanio(nombrePersonaje,danioPersonaje);
                break;
            case 4:
                jugador.verEstado(nombrePersonaje);
                break;
            case 5:
                cout << "Encontramos un pergamino de fuerza..." << endl;
                jugador.obtenerEquipamiento(pergamino);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                exit(0);
                break;
            default:
                cout << "Opción ingresada NO corresponde...\nIntente nuevamente..." << endl;
        }
    }

    return 0;
}