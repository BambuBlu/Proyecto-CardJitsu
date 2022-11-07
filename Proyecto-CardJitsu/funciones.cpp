#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>
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
    string elemento[60]; string color[60]; string descripciones_cartas_desafio[10];
    int numero[60]; int mano_jugador[60]; int mano_cpu[60]; bool cartas_desafio[10]; int desafios_elegidos[2];
    bool mazo[60]; bool ganador = true; bool agarrar_carta = true;


    SetDeck(mazo, mano_jugador, mano_cpu, cartas_desafio);
    SetChallengeCard(cartas_desafio, desafios_elegidos);
    LoadDeck(elemento, color, numero);
    LoadChallenge(descripciones_cartas_desafio);

    for(int i = 0; i < 3; i++)
    {
        int card_id = TakeCardFromDeck(mazo, mano_jugador);
    }

    for(int i = 0; i < 3; i++)
    {
        int card_id = TakeCardFromDeck(mazo, mano_cpu);
    }

    while((ganador = true))
    {
        int mode=0;
        rlutil::cls();
        cout<<"1- Ver carta de desafio"<<endl;
        cout<<"2- Ver cartas de elementos"<<endl;
        if(agarrar_carta)
        {
            agarrar_carta = StartRoundMenu(elemento, color, numero, mazo, mano_jugador, desafios_elegidos, descripciones_cartas_desafio);
        }
        else
        {
            agarrar_carta = PlayRoundMenu(elemento, color, numero, mazo, mano_jugador, desafios_elegidos, descripciones_cartas_desafio);
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


void LoadChallenge(string descripciones_cartas_desafio[10])
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


void SetDeck(bool mazo[60], int mano_jugador1[60], int mano_jugador2[60], bool cartas_desafio[10])
{
    for(int i = 0; i < 60; i++)
    {
        mazo[i]=true;
        mano_jugador1[i] = -1;
        mano_jugador2[i] = -1;
    }

    for(int i = 0; i<10; i++)
    {
        cartas_desafio[i] = true;
    }
}


void SetChallengeCard(bool cartas_desafio[10], int desafios_elegidos[2])
{
    SelectChallenge(cartas_desafio, desafios_elegidos, 0);

    RandomChallenge(cartas_desafio, desafios_elegidos, 1);

    cout<<"carta_desafio: [";
    for(int i=0; i<10; i++)
    {
        cout<<cartas_desafio[i]<<",";
    }
    cout<<"]"<<endl;
    rlutil::anykey();
}


void SelectChallenge(bool cartas_desafio[10], int desafios_elegidos[2], int id)
{
    int id_desafio;
    while(true)
    {
        cout<<"-Elige una carta desafio-"<<endl<<endl;
        cout<<"1 - Ganar una carta de Nieve."<<endl;
        cout<<"2 - Ganar una carta de Fuego."<<endl;
        cout<<"3 - Ganar una carta de Agua."<<endl;
        cout<<"4 - Ganar dos cartas rojas."<<endl;
        cout<<"5 - Ganar dos cartas amarillas."<<endl;
        cout<<"6 - Ganar dos cartas verdes."<<endl;
        cout<<"7 - Ganar dos cartas azules."<<endl;
        cout<<"8 - Ganar una carta con el mismo elemento que el adversario."<<endl;
        cout<<"9 - Ganar dos cartas con el mismo numero."<<endl;
        cout<<"10 - Ganar dos rondas de manera consecutiva."<<endl<<endl;
        cin>>id_desafio;
        id_desafio -= 1;

        if(SelectChallengeIfPossible(id_desafio, desafios_elegidos, id, cartas_desafio))
        {
            break;
        }
        else
        {
            cout<<"El desafio seleccionado ya esta tomado, elija otro"<<endl;
        }
    }
}


void RandomChallenge(bool cartas_desafio[10], int desafios_elegidos[2], int id)
{
    srand(time(0));
    int id_desafio = rand()%10;
    cout<<id_desafio<<endl;

    while(!SelectChallengeIfPossible(id_desafio, desafios_elegidos, id, cartas_desafio))
    {
        id_desafio = rand()%10;
    }
}


bool SelectChallengeIfPossible(int id_desafio, int desafios_elegidos[2], int id, bool cartas_desafio[10])
{
    bool not_taken = id_desafio >= 0 && id_desafio < 10 && cartas_desafio[id_desafio];
    if(not_taken)
        {
            desafios_elegidos[id] = id_desafio;
            cartas_desafio[id_desafio] = false;
        }
    return not_taken;
}


int TakeCardFromDeck(bool mazo[60],int mano[60])
{
    int card_id;
    srand(time(0));
    do
    {
        card_id = rand()%60;
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
    std::array<int,60> mano_ordenada = {SortHand(elemento, numero, mano)};

    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {
            if(elemento[mano_ordenada[i]] == "NIEVE")
            {
                cout<<"NIEVE: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";
            }

        }
    }
    cout<<endl;
    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {
            if(elemento[mano_ordenada[i]] == "FUEGO")
            {
                cout<<"FUEGO: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";
            }

        }
    }
    cout<<endl;
    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {
            if(elemento[mano_ordenada[i]] == "AGUA")
            {
                cout<<"AGUA: #"<<numero[mano_ordenada[i]]<<" "<<color[mano_ordenada[i]]<<" || ";
            }

        }
    }
    rlutil::anykey();
}


void ShowChallengeCard(int desafios_elegidos[2], string descripciones_cartas_desafio[10], int id)
{
    cout<<"La carta de desafio es: "<<descripciones_cartas_desafio[desafios_elegidos[id]];
    rlutil::anykey();
}

std::array<int,60> SortHand(string elemento[60], int numero[60], int mano[60])
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
            if(IsCardHigher(mano_ordenada[i], mano_ordenada[i-1], elemento, numero))
            {
                valor_temporal = mano_ordenada[i];
                mano_ordenada[i] = mano_ordenada[i-1];
                mano_ordenada[i-1] = valor_temporal;
            }
        }
    }
    return mano_ordenada;
}


bool IsCardHigher(int carta_a, int carta_b, string elemento[60], int numero[60])
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

bool StartRoundMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int desafios_elegidos[2], string descripciones_cartas_desafio[10])
{
    int mode;
    bool agarrar_carta;
    cout<<"3- Robar carta elemento de la pila"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>mode;
    switch(mode)
    {
        case 1:
            ShowChallengeCard(desafios_elegidos, descripciones_cartas_desafio, 0);
            break;
        case 2:
            ShowHand(elemento, color, numero, mano_jugador);
            agarrar_carta = true;
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


bool PlayRoundMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int desafios_elegidos[2], string descripciones_cartas_desafio[10])
{
    int mode;
    bool agarrar_carta;
    cout<<"3- Jugar una carta"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>mode;
    switch(mode)
    {
        case 1:
            ShowChallengeCard(desafios_elegidos, descripciones_cartas_desafio, 0);
            agarrar_carta = false;
            break;
        case 2:
            ShowHand(elemento, color, numero, mano_jugador);
            agarrar_carta = false;
            break;
        case 3:
            agarrar_carta = true;
            break;
        default:
            cout<<"Ingrese una opcion correcta";
            agarrar_carta = false;
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

