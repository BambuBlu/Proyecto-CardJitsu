#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include "funciones.h"
#include "rlutil.h"

using namespace std;


int main()
{
    int opcion=0;
    string nombre_jugador;
    rlutil::setBackgroundColor(rlutil::color::CYAN);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    Nombrejuego();
    Recuadro();
    rlutil::locate (35,14);
    cout << "Nombre del jugador: ";
    cin>>nombre_jugador;
    rlutil::setBackgroundColor (rlutil::color::GREY);
    rlutil::hidecursor();

    while(true)
    {
        rlutil::setColor (rlutil::color::BLACK);
        rlutil::cls();
        Nombrejuego();
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
        rlutil::locate (45, 15);        rlutil::setColor (rlutil::color::WHITE);
        cout << "4- REGLAS DEL JUEGO" << endl;
        rlutil::locate (45, 16);
        rlutil::setColor (rlutil::color::BLACK);
        cout << "---------------------------" << endl;
        rlutil::locate (45, 17);        rlutil::setColor (rlutil::color::MAGENTA);        cout << "0- SALIR" << endl;
        rlutil::locate (45, 18);
        rlutil::setColor (rlutil::color::BLACK);
        cout << "OPCION: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
            case 1:
                Modo();
            break;
            case 2:
                MejorPuntaje(nombre_jugador);
                rlutil::setBackgroundColor (rlutil::color::GREY);
            break;
            case 3:
                Creditos();
                break;
            case 4:
                Reglas();
                break;
            case 0:
                /* Lo explico en la funcion pero ojo que hay que preguntarle si quiere salir al jugador ( S/N ) */
                SalirDelJuego();
                return 0;
                break;
            default:
                break;
        }
    }
 system("pause>nul");
 return 0;
}
