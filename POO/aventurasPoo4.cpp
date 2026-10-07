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
        string arma;
        string armadura;
    public:
        Guerrero(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador, string armaGuerrero, string armaduraGuerrero):
            Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
            arma(armaGuerrero), armadura(armaduraGuerrero){}

        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

class Arquero : public Personaje
{
    private:
        string arma;
        string armadura;
    public:
        Arquero(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador, string armaArquero, string armaduraArquero):
            Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
            arma(armaArquero), armadura(armaduraArquero){}

        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

class Mago : public Personaje
{
    private:
        string arma;
        string armadura;
    public:
        Mago(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador, string armaMago, string armaduraMago):
            Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
            arma(armaMago), armadura(armaduraMago){}
            
        void atacar(){
            cout << "Ataca con " << arma << endl;
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // Datos Personaje
    int opcion = 0;
    int tipoPersonaje = 0;
    string nombrePersonaje = "";
    int vidaPersonaje = 0;
    bool personajeVivo = true;
    int danioPersonaje = 0;
    Personaje* jugador = nullptr;

    // Datos Equipamiento
    string nombreEquipamiento = "Pergamino de Fuerza";
    string descripcionEquipamiento = "Aumenta la fuerza del personaje en 10";
    int calidadEquipamiento = 10;
    int cantidadUso = 1;
    int vidaEquipamiento = 0;

    // Datos Tipo Guerrero
    string armaSeleccionada;
    string armaduraSeleccionada;

    cout << "Indique el nombre de su personaje: " << endl;
    getline(cin, nombrePersonaje);
    cout << "Indique la vida incial de " << nombrePersonaje << ":" << endl;
    cin >> vidaPersonaje;

    cout << "Qué tipo de personaje será " << nombrePersonaje << "?" << endl;
    cout << "\nSeleccione su opción" << endl;
        cout << "[1] Guerrero." << endl;
        cout << "[2] Arquero." << endl;
        cout << "[3] Mago." << endl;
    cin >> tipoPersonaje;

    switch (tipoPersonaje)
    {
        case 1:
            armaSeleccionada = "Alabarda Témpano de Azufre";
            armaduraSeleccionada = "Armadura de Malla";
            jugador = new Guerrero(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,armaSeleccionada,armaduraSeleccionada);
            cout << nombrePersonaje << " ahora es un Guerrero" << endl;
            cout << "Se protege con su " << armaduraSeleccionada << " y ataca con su " << armaSeleccionada << endl;
            break;

        case 2:
            armaSeleccionada = "Hell's Poison Crossbow";
            armaduraSeleccionada = "Ghillie Suit";
            jugador = new Arquero(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,armaSeleccionada,armaduraSeleccionada);
            cout << nombrePersonaje << " ahora es un Guerrero" << endl;
            cout << "Se protege con su " << armaduraSeleccionada << " y ataca con su " << armaSeleccionada << endl;
            break;

        case 3:
            armaSeleccionada = "Necronomicón";
            armaduraSeleccionada = "Hechizo de Protección";
            jugador = new Mago(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,armaSeleccionada,armaduraSeleccionada);
            cout << nombrePersonaje << " ahora es un Guerrero" << endl;
            cout << "Se protege con su " << armaduraSeleccionada << " y ataca con su " << armaSeleccionada << endl;
            break;
    }
    
    // Personaje jugador(nombrePersonaje, vidaPersonaje, personajeVivo, danioPersonaje);
    Equipamiento pergamino(nombreEquipamiento,descripcionEquipamiento,calidadEquipamiento,cantidadUso,vidaEquipamiento);

    while (opcion != 6 && personajeVivo)
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
                jugador->avanzar(nombrePersonaje);
                break;
            case 2:
                jugador->saltar(nombrePersonaje);
                break;
            case 3:
                cout << "Ingrese el daño a recibir: " << endl;
                cin >> danioPersonaje;
                jugador->recibirDanio(nombrePersonaje,danioPersonaje);
                break;
            case 4:
                jugador->verEstado(nombrePersonaje);
                break;
            case 5:
                cout << "Encontramos un pergamino de fuerza..." << endl;
                jugador->obtenerEquipamiento(pergamino);
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