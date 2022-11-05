#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std;


void Mode()
{
    int mode=0;
    rlutil::cls();
    cout<<"1- Jugadora VS CPU"<<endl;
    cout<<"2- CPU VS CPU"<<endl;
    cout<<endl<<"Que modalidad desea jugar?--> ";
    cin>>mode;
    switch(mode)
    {
        case 1:
            PlayerVsCpu();
            break;
        case 2:
            CpuVsCpu();
            break;
        default:
            cout<<"Ingrese la modalidad correcta";
            rlutil::anykey();
    }
}


void PlayerVsCpu()
{
    cout<<"Entra en PlayerVsCpu"<<endl;
    rlutil::anykey();
    string elemento[60]; string color[60];
    int numero[60]; int mano_jugador[60]; int mano_cpu[60];
    bool mazo[60]; bool ganador = true; bool agarrar_carta = true;



    SetDeck(mazo, mano_jugador, mano_cpu);


    LoadDeck(elemento, color, numero);


    for(int i = 0; i < 3; i++)
    {
        int card_id = TakeCardFromDeck(mazo, mano_jugador);
    }



    for(int i = 0; i < 3; i++)
    {
        int card_id = TakeCardFromDeck(mazo, mano_cpu);
    }

    cout<<"Esta atras del while"<<endl;
    rlutil::anykey();

    while(ganador = true)
    {
        srand(time(0));
        int mode=0;
        rlutil::cls();
        cout<<"1- Ver carta de desafio"<<endl;
        cout<<"2- Ver cartas de elementos"<<endl;
        if(agarrar_carta)
        {
            agarrar_carta = StartRoundMenu(elemento, color, numero, mazo, mano_jugador);;
        }
        else
        {
            agarrar_carta = PlayRoundMenu(elemento, color, numero, mazo, mano_jugador);
        }
    }
}


void CpuVsCpu()
{

}

void LoadDeck(string elemento[60], string color[60], int numero[60])
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
            color[x]="FUEGO";
        }

        if(x >= 20 && x < 40)
        {
            color[x]="AGUA";
        }

        if(x >= 40 && x < 60)
        {
            color[x]="NIEVE";
        }

        if(x >= 0 && x < 5 || x >= 20 && x < 25 || x >= 40 && x < 45 )
        {
            elemento[x]="VERDE";
        }

        if(x >= 5 && x < 10 || x >= 25 && x < 30 || x >= 45 && x < 50 )
        {
            elemento[x]="AZUL";
        }

        if(x >= 10 && x < 15 || x >= 30 && x < 35 || x >= 50 && x < 55 )
        {
            elemento[x]="ROJO";
        }

        if(x >= 15 && x < 20 || x >= 35 && x < 40 || x >= 55 && x < 60 )
        {
            elemento[x]="AMARILLO";

        }
    }

}


void SetDeck(bool mazo[60], int mano_jugador1[60], int mano_jugador2[60])
{
    for(int i = 0 ; i < 60 ; i++)
    {
        mazo[i]=true;
        mano_jugador1[i] = -1;
        mano_jugador2[i] = -1;
    }
}


int TakeCardFromDeck(bool mazo[60],int mano[60])
{
    int card_id;
    do
    {
        card_id=rand()%60;
    } while(!mazo[card_id]);

    mazo[card_id] = false;
    TakeCard(mano, card_id);
    return(card_id);

}


void TakeCard(int mano[60], int card_id)
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


void ShowHand(string elemento[60], string color[60], int numero[60], int mano[60])
{
        cout<<"Las cartas en mano son :"<<endl<<endl;

        for(int i = 0 ; i < 60 ; i++)
        {
            if(mano[i] != -1)
            {
                if(elemento[mano[i]]=="FUEGO")
                {
                    cout<<elemento[i]<<": #"<<numero[i]<<" / "<<color[i];
                }
            }
        }



        rlutil::anykey();
        rlutil::cls();
}


bool StartRoundMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60])
{
    int mode;
    bool agarrar_carta;
    cout<<"3- Robar carta elemento de la pila"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>mode;
    switch(mode)
    {
        case 1:
            break;
        case 2:
            ShowHand(elemento, color, numero, mano_jugador);
            break;
        case 3:
            TakeCardFromDeck(mazo, mano_jugador);
            agarrar_carta = false;
            break;
        default:
            cout<<"Ingrese una opcion correcta";
            rlutil::anykey();
    }
    return (agarrar_carta);
}


bool PlayRoundMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60])
{
    int mode;
    bool agarrar_carta;
    cout<<"3- Jugar una carta"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>mode;
    switch(mode)
    {
        case 1:
            break;
        case 2:
            ShowHand(elemento, color, numero, mano_jugador);
            break;
        case 3:
            agarrar_carta = false;
            break;
        default:
            cout<<"Ingrese una opcion correcta";
            rlutil::anykey();
    }
    return (agarrar_carta);
}


void BestScore(string nombrejugador)
{
    rlutil::setBackgroundColor(rlutil::color::BROWN);
    rlutil::cls();
    rlutil::locate(2,2);
    cout << "Partidas:" << endl;
    rlutil::locate(2,3);
    cout << "Nombre de usuario: " << nombrejugador;
    rlutil::anykey();
}


void Rules()
{

}


void Credits()
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


void ExitGame()
{
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(52,10);
    cout << "Hasta luego...." << endl;
    rlutil::locate(49,13);
    cout << "Gracias por juegar  :)" << endl;
    cout<<endl<<endl<<endl;
}

