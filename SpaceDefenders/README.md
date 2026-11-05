# Código/Lógica de Juego SpaceDefenders #

1. Definir estructura de archivos/carpetas:
    - Carpeta Principal SpaceDefenders, contiene todo el código del juego.
        - Subcarpeta Entidades, contiene los *OBJETOS* del juego.
            - Nave.h + Nave.cpp
            - NaveJugador.h + NaveJugador.cpp
            - NaveEnemigo.h + NaveEnemigo.cpp

        - Subcarpeta Juego, contiene la *LÓGICA* del juego.
            - Juego.h + Juego.cpp

        - Archivo main.cpp en el directorio principal, para iniciar el juego.

2. Definir Clases del Juego
    - Definir clase Nave (Nave.h + Nace.cpp), clase Padre o SuperClase:
        - Atributos: nombre, vida, ataque.
        - Métodos: disparar(Nave), recibirDanio(int danio), estaViva(), verEstado(), getNombre(), getVida y getAtaque().

    - Definir clase NaveJugador (NaveJugador.h + NaveJugador.cpp), clase Hija o SubClase de Nave (herencia):
        - Atributos: escudo.
        - Métodos: disparar(Nave) y reparar().

    - Definir clase NaveEnemigo (NaveEnemigo.h + NaveEnemigo.cpp), clase Hija o SubClase de Nave (herencia):
        - Métodos: disparar(Nave).

3. Definir Lógica del Juego
    - Definir clase Juego (Juego.h + Juego.cpp)
        - Atributos: NaveJugador + conjunto NaveEnemigo (vector).
    - Lógica del Juego:
        - Creamos un objeto NaveJugador jugador:
            ```
            jugador("Phoenix", 100, 15)
            ```
        - Ciclo *FOR* para crear los enemigos:
            ```
            for (int i = 0; i < 10; i++)
            {
                NaveEnemigo enemigo(to_string(i), 50, 5);
                enemigos.push_back(enemigo);
            }
            ```
            - Desde *i = 0* hasta *i < 10* sumándole 1 a *i++* en cada vuelta del ciclo.
                ```
                for (int i = 0; i < 10; i++)
                ```
            - Creamos un objetivo de tipo NaveEnemigo, llamado enemigo con nombre, vida y ataque. El nombre del enemigo es el valor de *i*, pero convertido en texto, una vida de 50 y un ataque de 5.
                ```
                NaveEnemigo enemigo(to_string(i), 50, 5);
                ```
            - Agregamos ese enemigo creado a la lista de enemigos (vector).
                ```
                enemigos.push_back(enemigo);
                ```
            - De esta forma tenemos un conjunto (vector) de 10 enemigos.
        - Creamos un enemigo final, agregando un nuevo objeto NaveEnemigo a la lista de enemigos.
            ```
            NaveEnemigo jefeFinal("Estrella de la Muerte", 300, 10);
            enemigos.push_back(jefeFinal);
            ```
            - Creamos un objetivo de tipo NaveEnemigo, llamado jefeFinal con nombre, vida y ataque.
                ```
                NaveEnemigo jefeFinal("Estrella de la Muerte", 300, 10);
                ```
            - Agregamos ese enemigo creado a la lista de enemigos (vector).
                ```
                enemigos.push_back(jefeFinal);
                ```

## Error de Compilación ##

Los archivos sí existen. El problema es que el proyecto está dentro de SpaceDefenders, así que compilar desde la carpeta raíz del workspace no encuentra main.cpp. Además, hay que compilar todos los archivos .cpp, no solo main.cpp.

La compilación completa funcionó desde la carpeta SpaceDefenders, incluyendo Juego.cpp y los .cpp de Entidades. El #include "Juego/Juego.h" de main.cpp está bien; ejecuta la compilación desde esa carpeta o configura Code Runner para usarla como directorio de trabajo y agregar los demás archivos fuente.