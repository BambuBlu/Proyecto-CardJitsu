#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include<map>
#include<time.h>
#include "funciones.h"
#include "rlutil.h"

using namespace std;



int main()
{
    int opcion=0, cont_jugadores=1;
    string nombre_jugador[10]={};
    int Puntos_Jugador[10]={};
    int decision;

    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    Nombrejuego();
    Cargando();
    Recuadro();
    rlutil::showcursor();
    rlutil::locate (44,14);
    cout << "Nombre del jugador: ";
    cin>>nombre_jugador[cont_jugadores-1];
    rlutil::hidecursor();

    while(true)
    {
        rlutil::setBackgroundColor (rlutil::color::GREY);
        rlutil::setColor (rlutil::color::BLACK);
        rlutil::cls();
        Nombrejuego();
        rlutil::locate (45, 10);
        cout << "#" << nombre_jugador [cont_jugadores-1];
        rlutil::locate (45, 11);
        cout << "---------------------------" << endl;
        rlutil::locate (45, 12);
        rlutil::setColor (rlutil::color::RED);
        cout << "1- JUGAR" << endl;
        rlutil::locate (45, 13);
        rlutil::setColor (rlutil::color::LIGHTBLUE);
        cout << "2- ESTADISTICAS" << endl;
        rlutil::locate (45, 14);        rlutil::setColor (rlutil::color::LIGHTGREEN);
        cout << "3- CREDITOS" << endl;
        rlutil::locate (45, 15);
        rlutil::setColor (rlutil::color::WHITE);
        cout << "4- REGLAS DEL JUEGO" << endl;
        rlutil::locate (45, 16);        rlutil::setColor (rlutil::color::LIGHTCYAN);
        cout << "5- CAMBIAR JUGADOR" << endl;
        rlutil::locate (45, 17);
        rlutil::setColor (rlutil::color::BLACK);
        cout << "---------------------------" << endl;
        rlutil::locate (45, 18);        rlutil::setColor (rlutil::color::MAGENTA);        cout << "0- SALIR" << endl;
        rlutil::locate (45, 19);
        rlutil::setColor (rlutil::color::BLACK);
        cout << "OPCION: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
            case 1:
                rlutil::setBackgroundColor(rlutil::color::WHITE);
                Modo(Puntos_Jugador,cont_jugadores, nombre_jugador);
            break;
            case 2:
                MejorPuntaje(Puntos_Jugador, nombre_jugador, cont_jugadores);
                rlutil::setBackgroundColor (rlutil::color::GREY);
            break;
            case 3:
                Creditos();
                break;
            case 4:
                Reglas();
                break;
            case 5:
                cont_jugadores++;
                CambiarJugador(nombre_jugador, cont_jugadores);
                break;
            case 0:
                decision = Seguroquieressalir();

                if (decision)
                {
                    SalirDelJuego();
                    return 0;
                }
                else
                {
                    break;
                }

            default:
                break;
        }
    }
 system("pause>nul");
 return 0;
}
