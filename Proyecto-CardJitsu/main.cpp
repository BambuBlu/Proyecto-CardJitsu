#include "funciones.h"
#include "rlutil.h"
using namespace std;

int main(){
    int opcion;
    int modo1;
    char nombrejugador[100];
    rlutil::setBackgroundColor(rlutil::color::CYAN);
    rlutil::cls();
    rlutil::locate (40,13);
    cout << "Nombre del jugador: ";
    cin.getline(nombrejugador,35,'\n');
    rlutil::setBackgroundColor (rlutil::color::GREY);
    rlutil::hidecursor();
    do{
    rlutil::setColor (rlutil::color::BLACK);
    rlutil::cls();
    rlutil::locate (54, 10);
    cout << "CARD-JITSU++" << endl;
    rlutil::locate (45, 11);
    cout << "---------------------------" << endl;
    rlutil::locate (45, 12);
    rlutil::setColor (rlutil::color::RED);
    cout << "1- JUGAR" << endl;
    rlutil::locate (45, 13);
    rlutil::setColor (rlutil::color::LIGHTBLUE);
    cout << "2- ESTADISTICAS" << endl;
    rlutil::locate (45, 14);    rlutil::setColor (rlutil::color::LIGHTGREEN);
    cout << "3- CREDITOS" << endl;
    rlutil::locate (45, 15);    rlutil::setColor (rlutil::color::WHITE);
    cout << "4- REGLAS DEL JUEGO" << endl;
    rlutil::locate (45, 16);
    rlutil::setColor (rlutil::color::BLACK);
    cout << "---------------------------" << endl;
    rlutil::locate (45, 17);    rlutil::setColor (rlutil::color::MAGENTA);    cout << "0- SALIR" << endl;
    rlutil::locate (45, 18);
    rlutil::setColor (rlutil::color::BLACK);
    cout << "OPCION: ";
    cin >> opcion;
    cout << endl;
    switch (opcion){
    case 1:
    opcion = 1;
    modo1 = Modalidad(opcion);
        switch (modo1){
            case 1:
        JugadorVSCPU (nombrejugador);
        break;
            case 2:
        break;
            default:
            cout << endl << "------------------NO CONTAMOS CON ESA MODALIDAD DE JUEGO-------------------";
            rlutil::anykey();
        break;
        }
        case 2:
        opcion = 2;
        rlutil::setBackgroundColor (rlutil::color::GREY);
        break;
    case 3:
        opcion = 3;
        Opcion3(opcion);
        rlutil::setBackgroundColor (rlutil::color::GREY);
        break;
    case 4:
        opcion = 4;
        break;
    case 0:
        opcion = 0;
        Opcion0(opcion);
        break;
    default:
        break;
    }
    }while (opcion != 0);





 system("pause>nul");
 return 0;
}
