#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include<map>
#include<time.h>
#include "funciones.h"
#include "rlutil.h"



using namespace std;


void Modo(int Puntos_Jugador[10],int cont_jugadores, string nombre_jugador[10])
{
    int modo=0;
    rlutil::cls();
    rlutil::setColor(rlutil::color::BLACK);
    Nombrejuego();
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(50,10);
    cout<<"1- Jugador VS CPU"<<endl;
    rlutil::locate(50,12);
    cout<<"2- CPU VS CPU"<<endl;
    rlutil::locate(42,14);
    cout<<"Que modalidad desea jugar?--> ";
    cin>>modo;
    rlutil::cls();
    switch(modo)
    {
        case 1:
            JugadorVsCpu(Puntos_Jugador,cont_jugadores, nombre_jugador);
            break;
        case 2:
            CpuVsCpu();
            break;
        default:
            cout<<"Ingrese la modalidad correcta";
            rlutil::anykey();
    }
}


void JugadorVsCpu(int Puntos_Jugador[10],int cont_jugadores, string nombre_jugador[10])
{
    rlutil::cls();

    string elemento[60]; string color[60]; string descripciones_cartas_desafio[10];
    int numero[60]; int mano_jugador[60]; int mano_cpu[60]; int desafios_elegidos[2]; int cantidad_cartas = 0; int ronda = 1; int cont_desafios[2]; int hitos_partida[10];
    bool mazo[60]; bool navegacion[2]; bool cartas_desafio[10]; bool cartas_desafio_ganadas[2];


    ColocarMazo(mazo, mano_jugador, mano_cpu, cartas_desafio, cont_desafios, navegacion, hitos_partida, cartas_desafio_ganadas);
    ColocarCartasDesafio(cartas_desafio, desafios_elegidos);
    CargarMazo(elemento, color, numero);
    CargarDesafio(descripciones_cartas_desafio);

    for(int i = 0; i < 3; i++)
    {
        AgarrarCartaDelMazo(mazo, mano_jugador);
    }

    for(int i = 0; i < 3; i++)
    {
        AgarrarCartaDelMazo(mazo, mano_cpu);
    }

    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    cout<<"--Tus cartas en mano son--"<<endl<<endl;
    cantidad_cartas = MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
    cout<<endl<<endl;
    MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);

    while(navegacion[0])
    {

        rlutil::cls();
        rlutil::setColor(rlutil::color::WHITE);
        rlutil::setBackgroundColor(rlutil::color::BLACK);
        rlutil::locate (40,6);
        cout<<"Card-Jitsu++"<<endl;
        rlutil::locate (40,7);
        cout<<"-----------------------------------------"<<endl;
        rlutil::locate (40,8);
        cout<<nombre_jugador[cont_jugadores-1]<<" Vs CPU"<<"                    "<<"Ronda #"<<ronda<<endl;
        rlutil::locate (40,9);
        cout<<"1- Ver carta de desafio"<<endl;
        rlutil::locate (40,10);
        cout<<"2- Ver cartas de elementos"<<endl;
        switch(navegacion[1])
        {
            case 1:
                EmpezarRondaMenu(elemento, color, numero, mazo, mano_jugador, desafios_elegidos, descripciones_cartas_desafio, cantidad_cartas, ronda, navegacion);
                break;
            case 0:
                JugarRondaMenu(Puntos_Jugador, elemento,  color, cont_jugadores, numero, mazo, mano_jugador, mano_cpu, desafios_elegidos, descripciones_cartas_desafio, cont_desafios, cantidad_cartas, navegacion, hitos_partida, nombre_jugador,cartas_desafio_ganadas);
                ronda ++;
                break;
        }
    }
}


void CpuVsCpu()
{
    string elemento[60]; string color[60]; string descripciones_cartas_desafio[10];
    int numero[60]; int mano_cpu1[60]; int mano_cpu2[60]; int desafios_elegidos[2]; int cantidad_cartas = 0; int ronda = 1; int cont_desafios[2]; int hitos_partida[10];
    bool mazo[60]; bool navegacion[2]; bool cartas_desafio[10]; bool cartas_desafio_ganadas[2];

    ColocarMazo(mazo, mano_cpu1, mano_cpu2, cartas_desafio, cont_desafios, navegacion, hitos_partida, cartas_desafio_ganadas);
    CargarMazo(elemento, color, numero);
    CargarDesafio(descripciones_cartas_desafio);

    DesafioAleatorio(cartas_desafio, desafios_elegidos, 0);
    rlutil::setBackgroundColor(rlutil::color::BLACK);

    DesafioAleatorio(cartas_desafio, desafios_elegidos, 1);
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    for(int i = 0; i < 3; i++)
    {
        AgarrarCartaDelMazo(mazo, mano_cpu1);
    }

    for(int i = 0; i < 3; i++)
    {
        AgarrarCartaDelMazo(mazo, mano_cpu2);
    }


    while(navegacion[0])
    {

        rlutil::cls();
        rlutil::setColor(rlutil::color::WHITE);
        rlutil::setBackgroundColor(rlutil::color::BLACK);
        rlutil::locate (40,6);
        cout<<"Card-Jitsu++"<<endl;
        rlutil::locate (40,7);
        cout<<"-----------------------------------------"<<endl;
        rlutil::locate (40,8);
        cout<<"Cpu1 Vs Cpu2"<<"                    "<<"Ronda #"<<ronda<<endl<<endl;
        rlutil::setColor(rlutil::color::WHITE);
        cout<<"--Cartas en mano Cpu1--"<<endl<<endl;
        cantidad_cartas = MostrarMano(elemento, color, numero, mano_cpu1, false, cantidad_cartas);
        cout<<endl<<endl;
        MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);
        cout<<endl<<endl;
        rlutil::setColor(rlutil::color::WHITE);
        cout<<"--Cartas en mano Cpu2--"<<endl<<endl;
        cantidad_cartas = MostrarMano(elemento, color, numero, mano_cpu2, false, cantidad_cartas);
        cout<<endl<<endl;
        MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 1);
        cout<<endl<<endl;

        rlutil::cls();

        JugarRondasCpus(elemento, color, numero, mazo, mano_cpu1, mano_cpu2, desafios_elegidos, cont_desafios, navegacion, hitos_partida,cartas_desafio_ganadas);
        ronda ++;

    }

}

void CargarMazo(string elemento[60], string color[60], int numero[60])
{
    int indice=1;
    for (int x = 0; x < 60; x++)
    {

        numero[x]=indice;
        indice++;
        if(indice==6)
        {
            indice=1;
        }

        if(x >= 0 && x < 20)
        {
            elemento[x]="FUEGO";
        }

        if(x >= 20 && x < 40)
        {
            elemento[x]="AGUA";
        }

        if(x >= 40 && x < 60)
        {
            elemento[x]="NIEVE";
        }

        if((x >= 0 && x < 5) || (x >= 20 && x < 25) || (x >= 40 && x < 45))
        {
            color[x]="VERDE";
        }

        if((x >= 5 && x < 10) || (x >= 25 && x < 30) || (x >= 45 && x < 50))
        {
            color[x]="AZUL";
        }

        if((x >= 10 && x < 15) || (x >= 30 && x < 35) || (x >= 50 && x < 55))
        {
            color[x]="ROJO";
        }

        if((x >= 15 && x < 20) || (x >= 35 && x < 40) || (x >= 55 && x < 60))
        {
            color[x]="AMARILLO";

        }
    }

}


void CargarDesafio(string descripciones_cartas_desafio[10])
{
    descripciones_cartas_desafio[0] = "Ganar una carta de Nieve.";
    descripciones_cartas_desafio[1] = "Ganar una carta de Fuego.";
    descripciones_cartas_desafio[2] = "Ganar una carta de Agua.";
    descripciones_cartas_desafio[3] = "Ganar dos cartas rojas.";
    descripciones_cartas_desafio[4] = "Ganar dos cartas amarillas.";
    descripciones_cartas_desafio[5] = "Ganar dos cartas verdes.";
    descripciones_cartas_desafio[6] = "Ganar dos cartas azules.";
    descripciones_cartas_desafio[7] = "Ganar una carta con el mismo elemento que el adversario.";
    descripciones_cartas_desafio[8] = "Ganar dos cartas con el mismo numero.";
    descripciones_cartas_desafio[9] = "Ganar dos rondas de manera consecutiva.";
}


void ColocarMazo(bool mazo[60], int mano_jugador1[60], int mano_jugador2[60], bool cartas_desafio[10], int cont_desafios[2], bool navegacion[2], int hitos_partida[10], bool cartas_desafio_ganadas[2])
{
    for(int i = 0; i < 60; i++)
    {
        mazo[i]=true;
        mano_jugador1[i] = -1;
        mano_jugador2[i] = -1;
    }

    for(int i = 0; i < 10; i++)
    {
        cartas_desafio[i] = true;
        hitos_partida[i] = 0;
    }

    for(int i = 0; i < 2; i++)
    {
        cont_desafios[i] = 0;
        navegacion[i] = true;
        cartas_desafio_ganadas[i] = false;
    }
}


void ColocarCartasDesafio(bool cartas_desafio[10], int desafios_elegidos[2])
{
    int seleccion;

    while(true)
    {
        rlutil::setBackgroundColor(rlutil::color::WHITE);
        rlutil::setColor(rlutil::color::BLACK);
        rlutil::locate(35,8);
        cout<<"Desea un desafio aleatorio o desea seleccionar uno?"<<endl;
        rlutil::locate(50,10);
        cout<<"1 - Aleatorio";
        rlutil::locate(50,11);
        cout<<"2 - Elegir desafio"<<endl;
        rlutil::locate(44,13);
        cout<<"Que modalidad desea jugar?--> ";
        cin>>seleccion;

        if(seleccion <= 2 && seleccion >= 1)
        {
            break;
        }
        else
        {
            cout<<"Ingrese una opcion correcta"<<endl;
        }

    }

    if(seleccion == 1)
    {
        DesafioAleatorio(cartas_desafio, desafios_elegidos, 0);
        rlutil::setBackgroundColor(rlutil::color::DARKGREY);
    }
    else if(seleccion == 2)
    {
        SeleccionarDesafio(cartas_desafio, desafios_elegidos, 0);
        rlutil::setBackgroundColor(rlutil::color::BLACK);
    }

    DesafioAleatorio(cartas_desafio, desafios_elegidos, 1);
        rlutil::setBackgroundColor(rlutil::color::BLACK);
}


void SeleccionarDesafio(bool cartas_desafio[10], int desafios_elegidos[2], int id)
{
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    int id_desafio;
    char mensaje1[]= "A continuacion", mensaje2[] = "Elige una carta desafio";
    while(true)
    {
        rlutil::cls();
        rlutil::setColor (rlutil::color::WHITE);
        rlutil::locate (50,3);
        for (int x=0; x<14;x++){
            cout << mensaje1 [x];
            Sleep(20);
        }
        rlutil::locate (47,4);
        for (int x=0; x<23;x++){
            cout << mensaje2 [x];
            Sleep(20);

        }
            Sleep(20);        rlutil::locate (1,7);
        rlutil::setColor (rlutil::color::CYAN);
        cout<<"1 - Ganar una carta de Nieve."<<endl;
            Sleep(20);        rlutil::locate (1,8);
        rlutil::setColor (rlutil::color::LIGHTRED);
        cout<<"2 - Ganar una carta de Fuego."<<endl;
            Sleep(20);
        rlutil::locate (1,9);
        rlutil::setColor (rlutil::color::BLUE);
        cout<<"3 - Ganar una carta de Agua."<<endl;
            Sleep(20);        rlutil::locate (1,10);
        rlutil::setColor (rlutil::color::LIGHTRED);
        cout<<"4 - Ganar dos cartas rojas."<<endl;
            Sleep(20);
        rlutil::locate (1,11);        rlutil::setColor (rlutil::color::YELLOW);
        cout<<"5 - Ganar dos cartas amarillas."<<endl;
            Sleep(20);        rlutil::locate (1,12);
        rlutil::setColor (rlutil::color::GREEN);
        cout<<"6 - Ganar dos cartas verdes."<<endl;
            Sleep(20);
        rlutil::locate (1,13);
        rlutil::setColor (rlutil::color::BLUE);
        cout<<"7 - Ganar dos cartas azules."<<endl;
            Sleep(20);
        rlutil::locate (1,14);
        rlutil::setColor (rlutil::color::MAGENTA);
        cout<<"8 - Ganar una carta con el mismo elemento que el adversario."<<endl;
            Sleep(20);
        rlutil::locate (1,15);
        rlutil::setColor (rlutil::color::DARKGREY);
        cout<<"9 - Ganar dos cartas con el mismo numero."<<endl;
            Sleep(20);
        rlutil::locate (1,16);
        rlutil::setColor (rlutil::color::LIGHTRED);
        cout<<"10 - Ganar dos rondas de manera consecutiva."<<endl<<endl;
            Sleep(20);
        rlutil::locate (1,18);
        rlutil::setColor (rlutil::color::WHITE);
        cout<<"Desafio N ----> ";
        cin>>id_desafio;
        id_desafio -= 1;

        if(SeleccionarDesafioSiEsPosible(id_desafio, desafios_elegidos, id, cartas_desafio))
        {
            break;
        }
        else
        {
            rlutil::setColor(rlutil::color::LIGHTRED);
            cout<<"No se puede tomar la carta de desafio seleccionada"<<endl;
            rlutil::locate(35,22);
            rlutil::setColor(rlutil::color::WHITE);
            cout<<"<PRESIONA CUALQUIER TECLA PARA INTEALO DE NUEVO>"<<endl;
            rlutil::anykey();

        }
    }
}


void DesafioAleatorio(bool cartas_desafio[10], int desafios_elegidos[2], int id)
{
    srand(time(0));
    int id_desafio = rand()%10;

    while(!SeleccionarDesafioSiEsPosible(id_desafio, desafios_elegidos, id, cartas_desafio))
    {
        id_desafio = rand()%10;
    }
}


bool SeleccionarDesafioSiEsPosible(int id_desafio, int desafios_elegidos[2], int id, bool cartas_desafio[10])
{
    bool no_tomado = id_desafio >= 0 && id_desafio < 10 && cartas_desafio[id_desafio];
    if(no_tomado)
    {
        desafios_elegidos[id] = id_desafio;
        cartas_desafio[id_desafio] = false;
    }
    return no_tomado;
}


void CartasJugadasJugadorCpu(int Puntos_Jugador[], string elemento[60], string color[60],int cont_jugadores, int numero[60], bool mazo[60], int mano_jugador[60], int mano_cpu[60],
                             int cantidad_cartas, int desafios_elegidos[2], int cont_desafios[2], bool navegacion[2], int hitos_partida[10], string nombre_jugador[10], bool cartas_desafio_ganadas[2])

{
    std::array<int,2> carta_seleccionada;

    carta_seleccionada[0] = JugarCartaJugador(elemento, color, numero, mano_jugador, 0, cantidad_cartas);
    carta_seleccionada[1] = JugarCartaCpu(elemento, color, numero, mazo, mano_cpu, 1);


    int resultado = ElGanadorEs(carta_seleccionada, mano_jugador, mano_cpu, elemento, color, numero, desafios_elegidos);
    int cartas_reservadas[3];

    bool combinacion_ganadora = false;

    //empate
    if (resultado == 0)
    {
        cout<<">>Empate, las cartas vuelven al mazo de cartas"<<endl<<endl;
        DevolverPorEmpate(carta_seleccionada,mano_jugador, mano_cpu);
        rlutil::anykey();
    }
    //gana player
    else if(resultado == 1)
    {
        if(elemento[carta_seleccionada[0]] == elemento[carta_seleccionada[1]])
        {
            hitos_partida[4] += 5;
        }
        hitos_partida[3] += 1;
        ColorearCarta(carta_seleccionada[0],  color);
        cout<<">>"<<elemento[carta_seleccionada[0]]<<": #"<<numero[carta_seleccionada[0]]<<" "<<color[carta_seleccionada[0]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" le gana a ";
        ColorearCarta(carta_seleccionada[1],  color);
        cout<<elemento[carta_seleccionada[1]]<<": #"<<numero[carta_seleccionada[1]]<<" "<<color[carta_seleccionada[1]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" ,Ganaste la ronda"<<endl<<endl;
        rlutil::anykey();

        RobarCartaGanada(carta_seleccionada[0], mano_jugador);
        RobarCartaGanada(carta_seleccionada[1], mano_jugador);

        cartas_desafio_ganadas[0] = cartas_desafio_ganadas[0] || VerificarCartaDesafio(desafios_elegidos[0], elemento, color, numero, carta_seleccionada, cont_desafios, 1, resultado);

    }
    //gana CPU
    else if(resultado == -1)
    {
        if(elemento[carta_seleccionada[0]] == elemento[carta_seleccionada[1]])
        {
            hitos_partida[9] += 5;
        }
        hitos_partida[8] += 1;
        ColorearCarta(carta_seleccionada[1],  color);
        cout<<">>"<<elemento[carta_seleccionada[1]]<<": #"<<numero[carta_seleccionada[1]]<<" "<<color[carta_seleccionada[1]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" le gana a ";
        ColorearCarta(carta_seleccionada[0],  color);
        cout<<elemento[carta_seleccionada[0]]<<": #"<<numero[carta_seleccionada[0]]<<" "<<color[carta_seleccionada[0]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" ,Perdiste la ronda"<<endl<<endl;
        rlutil::anykey();

        RobarCartaGanada(carta_seleccionada[0],mano_cpu);
        RobarCartaGanada(carta_seleccionada[1],mano_cpu);

        cartas_desafio_ganadas[1] = cartas_desafio_ganadas[1] || VerificarCartaDesafio(desafios_elegidos[1], elemento, color, numero, carta_seleccionada, cont_desafios, 0, resultado);
    }


    std::array<int,60> mano_ordenada_jugador = {OrdenarMano(elemento, numero, mano_jugador)};
    bool gano_player = cartas_desafio_ganadas[0] && CartasDeCombinacionElementos(elemento, color, mano_ordenada_jugador, combinacion_ganadora, cartas_reservadas);

    std::array<int,60> mano_ordenada_cpu = {OrdenarMano(elemento, numero, mano_cpu)};
    bool gano_cpu = cartas_desafio_ganadas[1] && CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu, combinacion_ganadora, cartas_reservadas);


    if(gano_player)
    {
        hitos_partida[0] += 3;
        if(cartas_desafio_ganadas[1])
        {
            hitos_partida[2] -= 1;
        }

        if(CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu, combinacion_ganadora, cartas_reservadas))
        {
            hitos_partida[1] -= 1;
        }

        rlutil::cls();

        HitoFinal(Puntos_Jugador, hitos_partida, nombre_jugador, 0, cont_jugadores);

        navegacion[0] = false;
    }
    else if(gano_cpu)
    {
        hitos_partida[5] += 3;
        if(cartas_desafio_ganadas[0])
        {
            hitos_partida[7] -= 1;
        }

        if(CartasDeCombinacionElementos(elemento, color, mano_ordenada_jugador, combinacion_ganadora, cartas_reservadas))
        {
            hitos_partida[6] -= 1;
        }

        rlutil::cls();

        HitoFinal(Puntos_Jugador, hitos_partida, nombre_jugador, 1, cont_jugadores);

        navegacion[0] = false;
    }
}


int ElGanadorEs(std::array<int,2>  carta_seleccionada,int mano_jugador[60],int mano_cpu[60],string elemento[60], string color[60], int numero[60], int desafios_elegidos[2])
{
    rlutil::anykey();
    rlutil::cls();

    MostrarCartasEnfrentadas(carta_seleccionada, elemento, color, numero);

    int elemento_mayor = ElementoEsMayor(elemento[carta_seleccionada[0]], elemento[carta_seleccionada[1]]);
    if(elemento_mayor == 0)
    {
        bool no_igual = numero[carta_seleccionada[0]] != numero[carta_seleccionada[1]];
        return (-1 + 2 * (int)(numero[carta_seleccionada[0]] > numero[carta_seleccionada[1]])) * (int) no_igual;
    }
    else
    {
        return elemento_mayor;
    }
}


int ElementoEsMayor(string elementoA, string elementoB)
{
    if(elementoA == elementoB){
        return 0;
    }
    else if(elementoA == "FUEGO")
    {
        return -1 + 2 * ((int) (elementoB == "NIEVE"));
    }
    else if(elementoA == "NIEVE")
    {
        return -1 + 2 * ((int) (elementoB == "AGUA"));
    }
    else if(elementoA == "AGUA")
    {
        return -1 + 2 * ((int) (elementoB == "FUEGO"));
    }
}


bool VerificarCartaDesafio( int desafios_elegidos, string elemento[60], string color[60], int numero[60],std::array<int,2> carta_seleccionada, int cont_desafios[2], int id, bool resultado)
{
    switch(desafios_elegidos)
    {
        case 0:
            return GanarCartaElemento(elemento, carta_seleccionada[id], "NIEVE");
        case 1:
            return GanarCartaElemento(elemento, carta_seleccionada[id], "FUEGO");
        case 2:
            return GanarCartaElemento(elemento, carta_seleccionada[id], "AGUA");
        case 3:
            return GanarCartaColor(color, carta_seleccionada[id], "ROJO", cont_desafios[id]);
        case 4:
            return GanarCartaColor(color, carta_seleccionada[id], "AMARILLO", cont_desafios[id]);
        case 5:
            return GanarCartaColor(color, carta_seleccionada[id], "VERDE", cont_desafios[id]);
        case 6:
            return GanarCartaColor(color, carta_seleccionada[id], "AZUL", cont_desafios[id]);
        case 7:
            return GanarCartaMismoElemento(color, carta_seleccionada[0], carta_seleccionada[1]);
        case 8:
            return GanarCartaMismoNumero(numero, carta_seleccionada[0], carta_seleccionada[1], cont_desafios[id]);
        case 9:
            return GanarRondasConsecutivas(cont_desafios[id], resultado);
    }
}


bool GanarCartaElemento(string elemento[60], int carta_seleccionada, string tipo_elemento)
{
    return elemento[carta_seleccionada] == tipo_elemento;
}


bool GanarCartaColor(string color[60], int carta_seleccionada, string tipo_color, int color_desafio)
{
    color_desafio += (int) (color[carta_seleccionada] == tipo_color);

    return color_desafio >= 2;
}


bool GanarCartaMismoElemento(string elemento[60], int carta_seleccionada0, int carta_seleccionada1)
{
    return elemento[carta_seleccionada0] == elemento[carta_seleccionada1];
}


bool GanarCartaMismoNumero(int numero[60], int carta_seleccionada0, int carta_seleccionada1, int numero_desafio)
{
    numero_desafio += (int) (numero[carta_seleccionada0] == numero[carta_seleccionada1]);

    return numero_desafio >= 2;
}


bool GanarRondasConsecutivas(int ronda_desafio, bool resultado)
{
    ronda_desafio = (ronda_desafio + 1) * ((int) resultado);

    return ronda_desafio >= 2;
}


void ColorearCarta(int carta_seleccionada,  string color[60])
    {
     if (color[carta_seleccionada] == "ROJO")
    {
        rlutil::setColor(rlutil::color::RED);
    }
    else if (color[carta_seleccionada] == "VERDE")
    {
        rlutil::setColor(rlutil::color::GREEN);
    }
    else if (color[carta_seleccionada] == "AMARILLO")
    {
        rlutil::setColor(rlutil::color::YELLOW);
    }
    else if(color[carta_seleccionada]  == "AZUL")
    {
        rlutil::setColor(rlutil::color::BLUE);
    }

    }


void MostrarCartasEnfrentadas(std::array<int,2>  carta_seleccionada, string elemento[60], string color[60], int numero[60])
{
   ColorearCarta(carta_seleccionada[0],  color);

    cout<<"Esta en juego # "<<numero[carta_seleccionada[0]]<<" "<<elemento[carta_seleccionada[0]]<<" "<<color[carta_seleccionada[0]]<<"||"<<endl;
    cout<<"+--------+            "<<endl;
    cout<<"|"<<numero[carta_seleccionada[0]]<<"       |"<<endl;
    cout<<"|        |            "<<endl;
    cout<<"|   ";
    LogoCarta(elemento[carta_seleccionada[0]],color[carta_seleccionada[0]]);
    cout<<"    |            "<<endl;
    cout<<"|        |            "<<endl;
    cout<<"|        |            "<<endl;
    cout<<"|       "<<numero[carta_seleccionada[0]]<<"|"<<endl;
    cout<<"+--------+"<<endl<<endl;

    ColorearCarta(carta_seleccionada[1],  color);

    cout<<"Esta en juego # "<<numero[carta_seleccionada[1]]<<" "<<elemento[carta_seleccionada[1]]<<" "<<color[carta_seleccionada[1]]<<"||"<<endl;
    cout<<"+--------+            "<<endl;
    cout<<"|"<<numero[carta_seleccionada[1]]<<"       |"<<endl;
    cout<<"|        |            "<<endl;
    cout<<"|   ";
    LogoCarta(elemento[carta_seleccionada[1]],color[carta_seleccionada[1]]);
    cout<<"    |            "<<endl;
    cout<<"|        |            "<<endl;
    cout<<"|       "<<numero[carta_seleccionada[1]]<<"|"<<endl;
    cout<<"+--------+"<<endl<<endl;
    rlutil::setColor(rlutil::color::WHITE);
}


void LogoCarta(string elemento,string color)
{
    char logo;

    if (elemento == "FUEGO")
    {
        logo='F';
    }
    else if (elemento == "NIEVE")
    {
        logo='N';
    }
    else
    {
        logo='A';
    }
    cout<<logo;

}


int JugarCartaJugador(string elemento[60], string color[60], int numero[60], int mano[60], int id, int cantidad_cartas)
{
    rlutil::cls();
    int carta; int eleccion;

    std::array<int,60> mano_ordenada = {OrdenarMano(elemento, numero, mano)};

    cout<<"--Elija una carta a jugar--"<<endl<<endl;

    cantidad_cartas = MostrarMano(elemento, color, numero, mano, true, cantidad_cartas);

    while(true)
    {
            cout<<endl<<endl<<"carta: ";
            cin>>carta;
            if(carta > 0 && carta <= cantidad_cartas)
            {
                break;
            }
            else
            {
                cout<<"Esa carta no se encuentra en el maso, pruebe de nuevo"<<endl<<endl;
            }
    }
    carta -= 1;

    eleccion = mano_ordenada[carta];

    RetirarCartaPerdida(eleccion, mano);

    return eleccion;
}


int JugarCartaCpu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano[60], int id)
{

    AgarrarCartaDelMazo(mazo, mano);

    std::array<int,60> mano_ordenada = {OrdenarMano(elemento, numero, mano)};

    int carta_seleccionada;

    carta_seleccionada = ObtenerSeleccionCartaCpu(mano_ordenada, elemento, color, numero, id, carta_seleccionada);

    RetirarCartaPerdida(carta_seleccionada, mano);

    return carta_seleccionada;
}


int ObtenerSeleccionCartaCpu(const std::array<int,60> mano_ordenada, string elemento[60], string color[60], int numero[60], int id, int carta_seleccionada)
{
    bool combinacion_ganadora = false;

    int cartas_reservadas[3]; int mano_jugable[60];

    for(int i = 0; i < 60; i++)
    {
        mano_jugable[i] = mano_ordenada[i];
    }

    combinacion_ganadora = CartasDeCombinacionElementos(elemento, color, mano_ordenada, combinacion_ganadora, cartas_reservadas);

    if(combinacion_ganadora)
    {
        for(int i = 0; i < 3; i++)
        {
            EliminarCartasMano(cartas_reservadas, mano_ordenada, mano_jugable, i);
        }

        for(int i = 0; i < 60; i++)
        {
            if(mano_jugable[i] != -1)
            {
                carta_seleccionada = mano_jugable[i];
                break;
            }
        }
    }
    else
    {
        carta_seleccionada = SeleccionarCartaAleatoria(mano_jugable, carta_seleccionada);
    }

    return carta_seleccionada;
}

void RetirarCartaPerdida(int carta_seleccionada,int mano[60])
{
     for(int i = 0; i < 60; i++)
    {
        if(mano[i] == carta_seleccionada)
        {
            mano[i] = -1;
            break;
        }
    }
}
void RobarCartaGanada(int carta_seleccionada,int mano[60])
{
     for(int i = 0; i < 60; i++)
    {
        if(mano[i] == -1)
        {
            mano[i] = carta_seleccionada;
            break;
        }
    }
}


void DevolverPorEmpate(std::array<int,2>  carta_seleccionada,int mano_jugador[60],int mano_cpu[60])
{
   for(int i = 0; i < 60; i++)
    {
        if(mano_jugador[i] == carta_seleccionada[0])
        {
            mano_jugador[i] = -1;
            break;
        }
        if(mano_cpu[i] == carta_seleccionada[1])
        {
            mano_cpu[i] = -1;
            break;
        }
    }
}

void EliminarCartasMano( int cartas_reservadas[3], std::array<int,60> mano_ordenada, int mano_jugable[60], int id)
{
    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] == cartas_reservadas[id])
        {
            mano_jugable[i] = -1;
            break;
        }
    }
}


int SeleccionarCartaAleatoria(int mano[60], int carta_seleccionada)
{
    srand(time(0));

    for(int i = 0; i < 60; i++)
    {

        carta_seleccionada = rand()%60;
        if((carta_seleccionada != -1) && (carta_seleccionada = mano[i]))
        {
            break;
        }
    }

    return carta_seleccionada;
}


bool CartasDeCombinacionElementos(string elemento[60], string color[60], std::array<int,60> mano_ordenada, bool combinacion_ganadora,int cartas_reservadas[3])
{
    int nieve_ordenado[20]; int fuego_ordenado[20]; int agua_ordenado[20];

    InicializarArray(nieve_ordenado);
    InicializarArray(fuego_ordenado);
    InicializarArray(agua_ordenado);

    for(int i = 0; i < 60; i++)
    {
        int card_id = mano_ordenada[i];

        if(card_id == -1)
        {
            break;
        }
        else if(elemento[card_id] == "NIEVE")
        {
            AgregarAPila(nieve_ordenado, card_id);
        }
        else if(elemento[card_id] == "FUEGO")
        {
            AgregarAPila(fuego_ordenado, card_id);
        }
        else if(elemento[card_id] == "AGUA")
        {
            AgregarAPila(agua_ordenado, card_id);
        }
    }

    for(int nieve = 0; nieve < 20; nieve++)
    {
        if(nieve_ordenado[nieve] == -1)
        {
            break;
        }
        else
        {
            for(int fuego = 0; fuego < 20; fuego++)
            {
                if(fuego_ordenado[fuego] == -1)
                {
                    break;
                }
                else
                {
                    for(int agua = 0; agua < 20; agua++)
                    {
                        if(agua_ordenado[agua] == -1)
                        {
                            break;
                        }
                        else
                        {
                            if(color[nieve_ordenado[nieve]] != color[fuego_ordenado[fuego]])
                            {
                                if(color[fuego_ordenado[fuego]] != color[agua_ordenado[agua]])
                                {
                                    if(color[agua_ordenado[agua]] != color[nieve_ordenado[nieve]])
                                    {
                                        combinacion_ganadora = true;
                                        cartas_reservadas[0] = nieve_ordenado[nieve];
                                        cartas_reservadas[1] = fuego_ordenado[fuego];
                                        cartas_reservadas[2] = agua_ordenado[agua];
                                        break;

                                    }
                                }

                            }
                        }

                    }
                }
            }
        }
    }

    if(combinacion_ganadora != true)
    {
        if(nieve_ordenado[0] != -1 && nieve_ordenado[1] != -1 && nieve_ordenado[2] != -1)
        {
            combinacion_ganadora = true;
            for(int i = 0; i < 3; i++)
            {
                cartas_reservadas[i] = nieve_ordenado[i];
            }
        }
        else if(fuego_ordenado[0] != -1 && fuego_ordenado[1] != -1 && fuego_ordenado[2] != -1)
        {
            combinacion_ganadora = true;
            for(int i = 0; i < 3; i++)
            {
                cartas_reservadas[i] = fuego_ordenado[i];
            }
        }
        else if(agua_ordenado[0] != -1 && agua_ordenado[1] != -1 && agua_ordenado[2] != -1)
        {
            combinacion_ganadora = true;
            for(int i = 0; i < 3; i++)
            {
                cartas_reservadas[i] = agua_ordenado[i];
            }
        }
    }

    return combinacion_ganadora;
}

void AgregarAPila(int pila[20], int card_id)
{
    for(int i = 0; i < 20; i++)
    {
        if(pila[i] == -1)
        {
            pila[i] = card_id;
            break;
        }
    }
}


void InicializarArray(int array_vacio[20])
{
    for(int i = 0; i < 20; i++)
    {
        array_vacio[i] = -1;
    }
}


int AgarrarCartaDelMazo(bool mazo[60],int mano[60])
{
    int card_id;
    srand(time(0));
    do
    {
        card_id = rand()%60;
    } while(!mazo[card_id]);

    mazo[card_id] = false;
    AgarrarCarta(mano, card_id);
    return(card_id);

}


void AgarrarCarta(int mano[60], int card_id)
{
    for(int i = 0; i < 60; i++)
    {
        if(mano[i] == -1)
        {
            mano[i] = card_id;
            break;
        }
    }
}


int MostrarMano(string elemento[60], string color[60], int numero[60], int mano[60], bool seleccion, int cantidad_cartas)
{
    int carta_numero = 0;
    cantidad_cartas = 0;
    bool fuego = false; bool nieve = false;
    std::array<int,60> mano_ordenada = {OrdenarMano(elemento, numero, mano)};

    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {

            if(elemento[mano_ordenada[i]] == "NIEVE")
            {
                ColorearCarta(mano_ordenada[i],  color);
                carta_numero++;
                nieve = true;

                if(seleccion)
                {

                    cout<<"("<<carta_numero<<") ";

                    cout<<"NIEVE: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";

                    cantidad_cartas++;


                }
                else
                {

                    cout<<"NIEVE: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";

                }
            }

        }
    }
    if(nieve == true)
    {
        cout<<endl<<endl;
    }
    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {

            if(elemento[mano_ordenada[i]] == "FUEGO")
            {
                ColorearCarta(mano_ordenada[i],  color);
                carta_numero++;
                fuego = true;

                if(seleccion)
                {

                    cout<<"("<<carta_numero<<") ";
                    cout<<"FUEGO: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";

                    cantidad_cartas++;

                }
                else
                {

                    cout<<"FUEGO: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";


                }
            }

        }
    }
    if(fuego == true)
    {
        cout<<endl<<endl;
    }
    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)

        {
            if(elemento[mano_ordenada[i]] == "AGUA")
            {
                ColorearCarta(mano_ordenada[i],  color);
                carta_numero++;

                if(seleccion)
                {
                    cout<<"("<<carta_numero<<") ";
                    cout<<"AGUA: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";

                    cantidad_cartas++;
                }
                else
                {

                    cout<<"AGUA: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";

                }

            }

        }
    }

    if(!seleccion)
    {
        rlutil::anykey();
    }
    rlutil::setColor (rlutil::color::WHITE);
    return cantidad_cartas;
}


void MostrarCartaDesafio(int desafios_elegidos[2], string descripciones_cartas_desafio[10], int id)
{
    rlutil::setColor(rlutil::color::DARKGREY);
    cout<<"La carta de desafio es: "<<descripciones_cartas_desafio[desafios_elegidos[id]];
    rlutil::anykey();
}

std::array<int,60> OrdenarMano(string elemento[60], int numero[60], int mano[60])
{
    std::array<int,60> mano_ordenada;
    for(int i = 0; i < 60; i++)
    {
        mano_ordenada[i] = mano[i];
    }

    int valor_temporal;

    for(int n = 0; n < 60; n++)
    {
        for(int i = 1; i < 60; i++)
        {
            if(LaCartaEsMayor(mano_ordenada[i], mano_ordenada[i-1], elemento, numero))
            {
                valor_temporal = mano_ordenada[i];
                mano_ordenada[i] = mano_ordenada[i-1];
                mano_ordenada[i-1] = valor_temporal;
            }
        }
    }
    return mano_ordenada;
}


bool LaCartaEsMayor(int carta_a, int carta_b, string elemento[60], int numero[60])
{

    if(carta_a == -1 || carta_b == -1)
    {
        return(carta_a != -1);
    }
    else
    {
        string elemento_a = elemento[carta_a];
        string elemento_b = elemento[carta_b];
        if(elemento_a == elemento_b)
        {
            return(numero[carta_a] < numero[carta_b]);
        }
        else
        {
            return((elemento_a == "NIEVE") || (elemento_b != "NIEVE" && elemento_a == "FUEGO"));
        }
    }

}


void EmpezarRondaMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int desafios_elegidos[2], string descripciones_cartas_desafio[10], int cantidad_cartas, int ronda, bool navegacion[2])
{
    int modo;
    rlutil::locate(40,11);
    cout<<"3- Robar carta elemento de la pila";
    rlutil::locate(40,12);
    cout<<"Que desea hacer?--> ";
    cin>>modo;
    switch(modo)
    {
        case 1:
            rlutil::cls();

            MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);
            navegacion[1] = true;
            break;
        case 2:
            rlutil::cls();

            MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
            navegacion[1] = true;
            break;
        case 3:
            {
                rlutil::cls();

                int card_id = AgarrarCartaDelMazo(mazo, mano_jugador);
                cout<<"--La carta levantada es--"<<endl<<endl;
                ColorearCarta(card_id,  color);
                cout<<elemento[card_id]<<": #"<<numero[card_id]<<" "<<color[card_id];
                rlutil::setColor(rlutil::color::WHITE);
                rlutil::anykey();
                navegacion[1] = false;
                break;
            }
        default:
            cout<<"Ingrese una opcion correcta";
            navegacion[1] = true;
            rlutil::anykey();
    }
}


void JugarRondaMenu(int Puntos_Jugador [10], string elemento[60], string color[60], int cont_jugadores, int numero[60], bool mazo[60], int mano_jugador[60], int mano_cpu[60], int desafios_elegidos[2],
                    string descripciones_cartas_desafio[10], int cont_desafios[2], int cantidad_cartas, bool navegacion[2], int hitos_partida[10], string nombre_jugador[10], bool cartas_desafio_ganadas[2])
{
    int modo;
    rlutil::locate(40,11);
    cout<<"3- Jugar una carta";
    rlutil::locate(40,12);
    cout<<"Que desea hacer?--> ";
    cin>>modo;
    switch(modo)
    {
        case 1:
            rlutil::cls();

            MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);
            navegacion[1] = false;
            break;
        case 2:
            rlutil::cls();

            MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
            navegacion[1] = false;
            break;
        case 3:
            CartasJugadasJugadorCpu(Puntos_Jugador, elemento, color, cont_jugadores, numero, mazo, mano_jugador, mano_cpu, cantidad_cartas, desafios_elegidos, cont_desafios, navegacion, hitos_partida, nombre_jugador, cartas_desafio_ganadas);
            navegacion[1] = true;
            break;
        default:
            cout<<"Ingrese una opcion correcta";
            navegacion[1] = false;
            rlutil::anykey();
    }
}


void JugarRondasCpus(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_cpu1[60], int mano_cpu2[60],
                     int desafios_elegidos[2], int cont_desafios[2], bool navegacion[2], int hitos_partida[10], bool cartas_desafio_ganadas[2])

{
    std::array<int,2> carta_seleccionada;

    carta_seleccionada[0] = JugarCartasAutomatico(elemento, color, numero, mazo, mano_cpu1, 0);

    carta_seleccionada[1] = JugarCartasAutomatico(elemento, color, numero, mazo, mano_cpu2, 1);


    int resultado = ElGanadorEs( carta_seleccionada, mano_cpu1, mano_cpu2, elemento, color, numero, desafios_elegidos);
    int cartas_reservadas[3];

    bool combinacion_ganadora = false;

    //empate
    if (resultado == 0)
    {
        cout<<">>Empate, las cartas vuelven al mazo de cartas"<<endl<<endl;
        DevolverPorEmpate(carta_seleccionada, mano_cpu1, mano_cpu2);
        rlutil::anykey();
    }
    //gana player
    else if(resultado == 1)
    {
        if(elemento[carta_seleccionada[0]] == elemento[carta_seleccionada[1]])
        {
            hitos_partida[4] += 5;
        }
        hitos_partida[3] += 1;
        ColorearCarta(carta_seleccionada[0],  color);
        cout<<">>"<<elemento[carta_seleccionada[0]]<<": #"<<numero[carta_seleccionada[0]]<<" "<<color[carta_seleccionada[0]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" le gana a ";
        ColorearCarta(carta_seleccionada[1],  color);
        cout<<elemento[carta_seleccionada[1]]<<": #"<<numero[carta_seleccionada[1]]<<" "<<color[carta_seleccionada[1]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" ,Ganaste la ronda"<<endl<<endl;
        rlutil::anykey();

        RobarCartaGanada(carta_seleccionada[0], mano_cpu1);
        RobarCartaGanada(carta_seleccionada[1], mano_cpu1);

        cartas_desafio_ganadas[0] = cartas_desafio_ganadas[0] || VerificarCartaDesafio(desafios_elegidos[0], elemento, color, numero, carta_seleccionada, cont_desafios, 1, resultado);

    }
    //gana CPU
    else if(resultado == -1)
    {
        if(elemento[carta_seleccionada[0]] == elemento[carta_seleccionada[1]])
        {
            hitos_partida[9] += 5;
        }
        hitos_partida[8] += 1;
        ColorearCarta(carta_seleccionada[1],  color);
        cout<<">>"<<elemento[carta_seleccionada[1]]<<": #"<<numero[carta_seleccionada[1]]<<" "<<color[carta_seleccionada[1]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" le gana a ";
        ColorearCarta(carta_seleccionada[0],  color);
        cout<<elemento[carta_seleccionada[0]]<<": #"<<numero[carta_seleccionada[0]]<<" "<<color[carta_seleccionada[0]];
        rlutil::setColor(rlutil::color::WHITE);
        cout<<" ,Perdiste la ronda"<<endl<<endl;
        rlutil::anykey();

        RobarCartaGanada(carta_seleccionada[0],mano_cpu2);
        RobarCartaGanada(carta_seleccionada[1],mano_cpu2);

        cartas_desafio_ganadas[1] = cartas_desafio_ganadas[1] || VerificarCartaDesafio(desafios_elegidos[1], elemento, color, numero, carta_seleccionada, cont_desafios, 0, resultado);
    }


    std::array<int,60> mano_ordenada_cpu1 = {OrdenarMano(elemento, numero, mano_cpu1)};
    bool gano_cpu1 = cartas_desafio_ganadas[0] && CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu1, combinacion_ganadora, cartas_reservadas);

    std::array<int,60> mano_ordenada_cpu2 = {OrdenarMano(elemento, numero, mano_cpu2)};
    bool gano_cpu2 = cartas_desafio_ganadas[1] && CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu2, combinacion_ganadora, cartas_reservadas);


    if(gano_cpu1)
    {
        hitos_partida[0] += 3;
        if(cartas_desafio_ganadas[1])
        {
            hitos_partida[2] -= 1;
        }

        if(CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu2, combinacion_ganadora, cartas_reservadas))
        {
            hitos_partida[1] -= 1;
        }

        rlutil::cls();

        HitoFinalCpus(hitos_partida, 0);

        navegacion[0] = false;
    }
    else if(gano_cpu2)
    {
        hitos_partida[5] += 3;
        if(cartas_desafio_ganadas[0])
        {
            hitos_partida[7] -= 1;
        }

        if(CartasDeCombinacionElementos(elemento, color, mano_ordenada_cpu1, combinacion_ganadora, cartas_reservadas))
        {
            hitos_partida[6] -= 1;
        }

        rlutil::cls();

        HitoFinalCpus(hitos_partida, 1);

        navegacion[0] = false;
    }
}


int JugarCartasAutomatico(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano[60], int id)
{

    int card_id = AgarrarCartaDelMazo(mazo, mano);

    switch(id)
    {
        case 0:
            rlutil::setColor(rlutil::color::WHITE);
            cout<<"--La carta levantada por Cpu1 es--"<<endl<<endl;
            ColorearCarta(card_id,  color);
            cout<<elemento[card_id]<<": #"<<numero[card_id]<<" "<<color[card_id]<<endl<<endl;
            rlutil::anykey();
            break;
        case 1:
            rlutil::setColor(rlutil::color::WHITE);
            cout<<"--La carta levantada por Cpu2 es--"<<endl<<endl;
            ColorearCarta(card_id,  color);
            cout<<elemento[card_id]<<": #"<<numero[card_id]<<" "<<color[card_id]<<endl<<endl;
            rlutil::anykey();
            break;
    }

    std::array<int,60> mano_ordenada = {OrdenarMano(elemento, numero, mano)};

    int carta_seleccionada;

    carta_seleccionada = ObtenerSeleccionCartaCpu(mano_ordenada, elemento, color, numero, id, carta_seleccionada);

    RetirarCartaPerdida(carta_seleccionada, mano);

    return carta_seleccionada;
}


void HitoFinalCpus(int hitos_partida[10], int jugador)
{
    int hitos_resultado = 0;

    switch(jugador)
    {
        case 0:
            for(int i = 0; i < 5; i++)
            {
                hitos_resultado += hitos_partida[i];
            }

            cout<<"Card-Jitsu++"<<endl<<"-----------------------------------------"<<endl<<"HITO                                 Cpu1"<<endl<<"-----------------------------------------"<<endl;
            cout<<"ganador de la partida: "<<hitos_partida[0]<<" PDV"<<endl;
            cout<<"Combinacion elementos cumplido x contrario: "<<hitos_partida[1]<<" PDV"<<endl;
            cout<<"Carta desafio cumplido x contrario: "<<hitos_partida[2]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario: "<<hitos_partida[3]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario con igual elemento: "<<hitos_partida[4]<<" PDV"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"TOTAL                                 "<<hitos_resultado<<" PDV"<<endl<<endl;
            cout<<"Ganador Cpu1 con "<<hitos_resultado<<" puntos de victoria!!"<<endl;
            rlutil::anykey();

            break;
        case 1:
            for(int i = 5; i < 10; i++)
            {
                hitos_resultado += hitos_partida[i];
            }

            cout<<"Card-Jitsu++"<<endl<<"-----------------------------------------"<<endl<<"HITO                                 Cpu2"<<endl<<"-----------------------------------------"<<endl;
            cout<<"ganador de la partida: "<<hitos_partida[5]<<" PDV"<<endl;
            cout<<"Combinacion elementos cumplido x contrario: "<<hitos_partida[6]<<" PDV"<<endl;
            cout<<"Carta desafio cumplido x contrario: "<<hitos_partida[7]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario: "<<hitos_partida[8]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario con igual elemento: "<<hitos_partida[9]<<" PDV"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"TOTAL                                 "<<hitos_resultado<<" PDV"<<endl<<endl;
            cout<<"Ganador Cpu2 con "<<hitos_resultado<<" puntos de victoria!!"<<endl;
            rlutil::anykey();

            break;
    }
}


void HitoFinal(int Puntos_Jugador[10], int hitos_partida[10], string nombre_jugador[10], int jugador, int cont_jugadores)
{
    int hitos_resultado = 0;

    switch(jugador)
    {
        case 0:
            for(int i = 0; i < 5; i++)
            {
                hitos_resultado += hitos_partida[i];
            }

            cout<<"Card-Jitsu++"<<endl<<"-----------------------------------------"<<endl<<"HITO                                 "<<nombre_jugador[cont_jugadores-1]<<endl<<"-----------------------------------------";
            cout<<"ganador de la partida: "<<hitos_partida[0]<<" PDV"<<endl;
            cout<<"Combinacion elementos cumplido x contrario: "<<hitos_partida[1]<<" PDV"<<endl;
            cout<<"Carta desafio cumplido x contrario: "<<hitos_partida[2]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario: "<<hitos_partida[3]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario con igual elemento: "<<hitos_partida[4]<<" PDV"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"TOTAL                                 "<<hitos_resultado<<" PDV"<<endl<<endl;
            cout<<"Ganador"<<nombre_jugador[cont_jugadores-1]<<" con "<<hitos_resultado<<" puntos de victoria!!"<<endl;
            rlutil::anykey();
            Puntos_Jugador[cont_jugadores-1]= hitos_resultado;

            break;
        case 1:
            for(int i = 5; i < 10; i++)
            {
                hitos_resultado += hitos_partida[i];
            }

            cout<<"Card-Jitsu++"<<endl<<"-----------------------------------------"<<endl<<"HITO                                 CPU"<<endl<<"-----------------------------------------";
            cout<<"ganador de la partida: "<<hitos_partida[5]<<" PDV"<<endl;
            cout<<"Combinacion elementos cumplido x contrario: "<<hitos_partida[6]<<" PDV"<<endl;
            cout<<"Carta desafio cumplido x contrario: "<<hitos_partida[7]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario: "<<hitos_partida[8]<<" PDV"<<endl;
            cout<<"Rondas ganadas al adversario con igual elemento: "<<hitos_partida[9]<<" PDV"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"TOTAL                                 "<<hitos_resultado<<" PDV"<<endl<<endl;
            cout<<"Ganador CPU"<<" con "<<hitos_resultado<<" puntos de victoria!!"<<endl;
            rlutil::anykey();

            break;
    }
}


void MejorPuntaje(int Puntos_Jugador[10], string nombre_jugador[10], int cont_jugadores)
{
    int y=0, celdas_jugadores = 4;
    celdas_jugadores *= cont_jugadores;
    rlutil::setBackgroundColor(rlutil::color::BLUE);
    rlutil::cls();
    LogoPartidas();
    rlutil::setColor (rlutil::color::WHITE);
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    for (int x=0; x<celdas_jugadores; x++){
        rlutil::locate (28,9+x);
        cout << "#";
    }
    rlutil::locate (1,9);
    cout << "############################";
    for (int x=0; x<cont_jugadores;x++){
        if (nombre_jugador[x]!= ""){
        rlutil::locate(1,10+y);
        cout << "NOMBRE DE USUARIO: ";
        rlutil::setColor (rlutil::color::RED);
        cout << nombre_jugador [x];
        rlutil::setColor (rlutil::color::WHITE);
        rlutil::locate(1,12+y);
        cout << "PUNTOS: " << Puntos_Jugador [x];
        rlutil::locate(1,13+y);
        cout << "############################";
        y += 4;
        }
        else{

        }
        }
        rlutil::anykey();
}


void Reglas()
{
rlutil::setBackgroundColor(rlutil::color::GREEN);
rlutil::cls();
rlutil::setColor(rlutil::color::WHITE);


Nombrejuego();
Recuadro ();
rlutil::locate (55,14);
cout<<"REGLAS";
rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (55,1);
cout<<"Card Jitsu ++ "<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<">>El objetivo general del juego es lograr una combinacion de cartas de elementos"<<endl;
cout<<"y cumplir con la carta desafio obtenida al comienzo de la partida. El primer jugador"<<endl;
cout<<"en cumplir ambos hitos gana el juego."<<endl<<endl;

rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (55,1);
cout<<"Cartas desafio"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<">> En total existen diez cartas en el mazo de desafios,cada una con un desafio distinto a cumplir."<<endl;
cout<<"dicha carta se levanta solo una vez por partida."<<endl;
cout<<"los diez desafios existentes son :"<<endl<<endl;

cout<<"1 - Ganar una carta de Nieve."<<endl;
cout<<"2 - Ganar una carta de Fuego."<<endl;
cout<<"3 - Ganar una carta de Agua."<<endl;
cout<<"4 - Ganar dos cartas rojas."<<endl;
cout<<"5 - Ganar dos cartas amarillas."<<endl;
cout<<"6 - Ganar dos cartas verdes."<<endl;
cout<<"7 - Ganar dos cartas azules."<<endl;
cout<<"8 - Ganar una carta con el mismo elemento que el adversario."<<endl;
cout<<"9 - Ganar dos cartas con el mismo numero."<<endl;
cout<<"10 - Ganar dos rondas de manera consecutiva."<<endl;

rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (55,1);
cout<<"Cartas de elementos"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);

cout<<">> Estas cartas se caracterizan por tener un elemento (fuego, nieve o agua), un color"<<endl;
cout<<"(rojo, amarillo, verde y azul) y un número (de 1 a 5). En total son 60 naipes."<<endl;
cout<<"Estas cartas son necesarias para jugar en las rondas de elementos."<<endl;

rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (55,1);
cout<<"Como se juega?"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<"-Cada uno de los dos jugadores debera tomar una carta de la pila de cartas desafios y guardarla."<<endl;
cout<<"-Cada jugador comienza la partida con tres cartas elemento."<<endl;
cout<<"-Cada jugador juega una carta de elementos de su preferencia y se determina quien gana esa ronda."<<endl;
cout<<"-Un jugador nunca puede tener menos de tres cartas en su mano."<<endl;


rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (50,1);
cout<<"Que carta le gana a que carta?"<<endl;
rlutil::locate (40,2);
cout<<"************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<">> Para determinar esto se siguen las siguientes reglas:"<<endl<<endl;
cout<<"-El fuego vence a la nieve."<<endl;
cout<<"-La nieve vence al agua."<<endl;
cout<<"-El agua vence al fuego."<<endl;
cout<<"-Si se enfrentan cartas del mismo elemento,gana la que tenga mayor numero."<<endl;

rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (42,1);
cout<<"Obtener una combinacion de elementos ganadora"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<">> Para obtener una combinacion de elementos ganadora, un jugador debe lograr alguna de las siguientes situaciones:"<<endl<<endl;
cout<<"-Tener tres cartas de distinto elemento y distinto color."<<endl;
cout<<"-Tener tres cartas del mismo elemento."<<endl;

rlutil::locate (55,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();
rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (55,1);
cout<<"Valor de los puntos"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(rlutil::color::BLACK);
cout<<">> Una vez finalizada la partida, se determinan los puntos de victoria de la misma. Los mismos se calculan";
cout<<"de la siguiente manera:"<<endl<<endl;
cout<<"+3 PDV por haber ganado la partida."<<endl;
cout<<"-1 PDV si el contrario obtuvo una combinacion de elementos ganadora."<<endl;
cout<<"-1 PDV si el contrario cumplio el objetivo de su carta desafio."<<endl;
cout<<"+1 PDV por cada ronda ganada en el juego al adversario."<<endl;
cout<<"+5 PDV por cada ronda ganada en el juego con un elemento igual al del adversario."<<endl;
rlutil::locate (40,30);
cout<<"Continuar(Enter)";
rlutil::anykey();
rlutil::cls();
rlutil::locate (40,14);
Recuadro ();
rlutil::setColor(rlutil::color::MAGENTA);
rlutil::locate (50,14);
cout<<"Ahora si,a jugar!";
rlutil::locate (52,15);
cout<<"Buena suerte!";
rlutil::anykey();

}


void Creditos()
{
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
    rlutil::setBackgroundColor (rlutil::color::GREY);
}

void InterfazCambioDeJugador(){
    for (int x=0; x<40;x++){
        rlutil::locate(39+x,5);
        cout << "=";
        Sleep(15);
    }
    for (int x=0; x<5; x++){
        rlutil::locate(78,6+x);
        cout << "|";
        Sleep(40);

    }
    for (int x=0; x<40;x++){
        rlutil::locate(78-x,11);
        cout << "=";
        Sleep(15);
    }
    for (int x=0; x<5; x++){
        rlutil::locate(39,12+x);
        cout << "|";
        Sleep(40);

    }
    for (int x=0; x<40;x++){
        rlutil::locate(39+x,17);
        cout << "=";
        Sleep(15);
    }
    for (int x=0; x<5; x++){
        rlutil::locate(39,6+x);
        cout << "|";
        Sleep(40);
    }
    for (int x=0; x<5; x++){
        rlutil::locate(78,12+x);
        cout << "|";
        Sleep(40);

    }
}

void CambiarJugador(string nombre_jugador[20], int cont_jugadores){
    string nuevo_nombre;
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::hidecursor();
    rlutil::setColor(rlutil::color::WHITE);
    InterfazCambioDeJugador();
    rlutil::locate(44,6);
    cout << "HAS ELEGIDO CAMBIAR DE JUGADOR";
    Sleep (20);
    rlutil::locate(41,8);
    cout << "Todo el progreso del jugador anterior";
    Sleep (20);    rlutil::locate(46,10);
    cout << "Se gurdara en";
    rlutil::setColor (rlutil::color::LIGHTBLUE);
    cout << " Estadisticas";
    Sleep (20);
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(45,14);
    cout << "Nombre del jugador: ";
    cin>>nuevo_nombre;
    nombre_jugador[cont_jugadores-1] = nuevo_nombre;

}



bool Seguroquieressalir(){
    bool desicion;
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    Recuadro();
    rlutil::locate(44,12);
    cout << "¿Seguro quieres salir del juego? ";
    rlutil::locate(44,13);
    cout << "Si sales, se perdera tu progreso ";
    rlutil::locate(48,14);
    cout << "Te dejo que lo pienses";
    rlutil::locate(48,16);
    cout << "1-Si             0-No";
    rlutil::setColor(rlutil::color::BLACK);
    rlutil::setBackgroundColor (rlutil::color::WHITE);
    rlutil::locate(54,17);
    cout << "Opcion: ";
    rlutil::locate(61,17);
    cin >> desicion;
    if (desicion){
        return 1;
    }
    else{
        return 0;
    }


}

void SalirDelJuego()
{
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(50,10);
    cout << "Hasta luego...." << endl;
    rlutil::locate(47,13);
    cout << "Gracias por jugar  :)" << endl;
    cout<<endl<<endl<<endl;
}

void Recuadro (){
rlutil::hidecursor();
rlutil::setColor(rlutil::color::WHITE);
 for (int x=0;x<=40;x++){
    rlutil::locate (39+x,10);
    cout << "<<";
    Sleep (20);
    }
    for (int x=0;x<=6;x++){
    rlutil::locate (39,11+x);
    cout << "||";
    Sleep (50);
    }
    for (int x=0;x<=6;x++){
    rlutil::locate (79,11+x);
    cout << "||";
    Sleep (50);
    }
    for (int x=0;x<=40;x++){
    rlutil::locate (39+x,18);
    cout << ">>";
    Sleep (20);
    }
}
void Nombrejuego(){
    rlutil::hidecursor();
    cout << "     #########      #####       ######  ########             ############    ##    ###########   #######   ##   ## " << endl;
    cout << "     ##            ##   ##      #    #  ##     ##                 ##                   ##        ##        ##   ## " << endl;
    cout << "     ##           ##     ##     ######  ##      ##                ##         ##        ##        ##        ##   ## " << endl;
    cout << "     ##          ###########    ###     ##       ##  ######   ##  ##         ##        ##        #######   ##   ## " << endl;
    cout << "     ##          ##       ##    ## #    ##      ##            ##  ##         ##        ##             ##   ##   ## " << endl;
    cout << "     ##          ##       ##    ##  #   ##     ##              ## ##         ##        ##             ##   ##   ## " << endl;
    cout << "     #########   ##       ##    ##   #  ########                ####         ##        ##        #######   ####### " << endl;

}
void LogoPartidas(){
rlutil::setColor(rlutil::color::WHITE);
rlutil::setBackgroundColor(rlutil::color::BLACK);
rlutil::locate (30,2);
cout << "######   #####   ###### ####### ##  ######     #####    ######" << endl;
rlutil::locate (30,3);
cout << "##  ##  ##   ##  ##  ##    #        ##   ##   ##   ##   #     " << endl;
rlutil::locate (30,4);
cout << "###### ######### ######    #    ##  ##    ## #########  ######" << endl;
rlutil::locate (30,5);
cout << "##     ##     ## ####      #    ##  ##   ##  ##     ##       #" << endl;
rlutil::locate (30,6);cout << "##     ##     ## ## ##     #    ##  ######   ##     ##  ######" << endl;
rlutil::setBackgroundColor(rlutil::color::BLUE);


}
void Cargando(){
rlutil::locate(51,8);
    cout << "Cargando...";
    for (int x=0;x<109;x++){
        rlutil::locate (6+x,8);
        cout << "_";
        Sleep(20);
    }

}


