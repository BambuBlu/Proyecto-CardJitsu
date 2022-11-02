#include "funciones.h"
#include "rlutil.h"
using namespace std;

int Modalidad(int opcion){
    int modo=0;
    rlutil::cls();
    cout << "1- Jugador VS CPU" << endl;
    cout << "2- CPU VS CPU";
    cout << endl << "OPCION: ";
    cin >> modo;
    return modo;

}
void Opcion2(int opcion, string nombrejugador){
    rlutil::setBackgroundColor(rlutil::color::BROWN);
    rlutil::cls();
    rlutil::locate(2,2);
    cout << "Partidas:" << endl;
    rlutil::locate(2,3);
    cout << "Nombre de usuario: " << nombrejugador;
    rlutil::anykey();
}
void Opcion3(int opcion){
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::LIGHTMAGENTA);
    rlutil::locate(39,8);
    cout << "--------------Creditos-------------- " << endl;
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(25,12);
    cout << "Nicolas Rodriguez" << endl;
    rlutil::locate(50,12);
    cout << "Alejandro Daniel Morales" << endl;
    rlutil::locate(80,12);
    cout << "Tobias Moscatelli" << endl;
    rlutil::setColor(rlutil::color::LIGHTCYAN);
    cout << endl << "------------------------------------------------------------------------------------------------------------------------";
    rlutil::anykey();
}
void Opcion4(int opcion){
}
void Opcion0(int opcion){
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(52,10);
    cout << "Hasta luego...." << endl;
    rlutil::locate(49,13);
    cout << "Gracias por juegar  :)" << endl;
}
void JugadorVSCPU (char nombrejugador[]){
    rlutil::cls();
    cout << nombrejugador << "  VS CPU";
    rlutil::anykey();


}
