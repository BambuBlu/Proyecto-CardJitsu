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


void Modo()
{
    int modo=0;
    rlutil::cls();
    rlutil::setColor(rlutil::color::BLACK);
    Nombrejuego();
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::setColor(rlutil::color::WHITE);
    rlutil::locate(50,10);
    cout<<"1- Jugadora VS CPU"<<endl;
    rlutil::locate(50,12);
    cout<<"2- CPU VS CPU"<<endl;
    rlutil::locate(42,14);
    cout<<"Que modalidad desea jugar?--> ";
    cin>>modo;
    rlutil::cls();
    switch(modo)
    {
        case 1:
            JugadorVsCpu();
            break;
        case 2:
            CpuVsCpu();
            break;
        default:
            cout<<"Ingrese la modalidad correcta";
            rlutil::anykey();
    }
}


void JugadorVsCpu()
{
    rlutil::cls();

    string elemento[60]; string color[60]; string descripciones_cartas_desafio[10];
    int numero[60]; int mano_jugador[60]; int mano_cpu[60]; bool cartas_desafio[10]; int desafios_elegidos[2]; int cantidad_cartas = 0;
    bool mazo[60]; bool ganador = true; bool agarrar_carta = true;


    ColocarMazo(mazo, mano_jugador, mano_cpu, cartas_desafio);
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

    /* Puede poner parte grafica aca */
    cout<<"--Tus cartas en mano son--"<<endl<<endl;
    cantidad_cartas = MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
    cout<<endl<<endl;
    MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);

    while((ganador = true))
    {
        /* Puede poner parte grafica aca */
        /* Ojo que esta unido tambien a las rondas a empezar */
        rlutil::cls();
        cout<<"1- Ver carta de desafio"<<endl;
        cout<<"2- Ver cartas de elementos"<<endl;
        if(agarrar_carta)
        {
            agarrar_carta = EmpezarRondaMenu(elemento, color, numero, mazo, mano_jugador, desafios_elegidos, descripciones_cartas_desafio, cantidad_cartas);
        }
        else
        {
            agarrar_carta = JugarRondaMenu(elemento, color, numero, mazo, mano_jugador, mano_cpu, desafios_elegidos, descripciones_cartas_desafio, cantidad_cartas);
        }
    }
}


void CpuVsCpu()
{

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


void ColocarMazo(bool mazo[60], int mano_jugador1[60], int mano_jugador2[60], bool cartas_desafio[10])
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


void ColocarCartasDesafio(bool cartas_desafio[10], int desafios_elegidos[2])
{
    SeleccionarDesafio(cartas_desafio, desafios_elegidos, 0);

    DesafioAleatorio(cartas_desafio, desafios_elegidos, 1);
}


void SeleccionarDesafio(bool cartas_desafio[10], int desafios_elegidos[2], int id)
{
    int id_desafio;
    while(true)
    {
        /* Puede poner parte grafica aca */
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
        cout<<"Desafio N -> ";
        cin>>id_desafio;
        id_desafio -= 1;

        if(SeleccionarDesafioSiEsPosible(id_desafio, desafios_elegidos, id, cartas_desafio))
        {
            break;
        }
        else
        {
            /* Puede poner parte grafica aca */
            cout<<"No se puede tomar la carta de desafio seleccionada"<<endl;
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

void CartasJugadasJugadorCpu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int mano_cpu[60], int cantidad_cartas)
{
    std::array<int,2> carta_seleccionada;

    carta_seleccionada[0] = JugarCartaJugador(elemento, color, numero, mano_jugador, 0, cantidad_cartas);

    cout<<"El valor de carta_seleccionada[0] es: "<<carta_seleccionada[0]<<endl;
    rlutil::anykey();

    carta_seleccionada[1] = JugarCartaCpu(elemento, color, numero, mazo, mano_cpu, 1);

    cout<<"El valor de carta_seleccionada[1] es: "<<carta_seleccionada[1]<<endl;
    rlutil::anykey();
    ElGanadorEs(carta_seleccionada,elemento, color,numero );
}
void ElGanadorEs(int carta_seleccionada[2],string elemento[60], string color[60], int numero[60] ){
  //FUEGO VS NIEVE/FUEGO VS FUEGO---------------------------------------------------------------------------------------------------------------------------//
    if(elemento[carta_seleccionada[0]]==("FUEGO")&&elemento[carta_seleccionada[1]]==("NIEVE")){
    cout<<">>FUEGO le gana a NIEVE,Ganaste la ronda"<<endl<<endl;
    }
    else{elemento[carta_seleccionada[0]]==("FUEGO")&&elemento[carta_seleccionada[1]]==("FUEGO"){
        if (numero[carta_seleccionada[0]]>numero[carta_seleccionada[1]]){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda"<<endl<<endl;
        }
    }
    }
    if (elemento[carta_seleccionada[0]]==("NIEVE")&&elemento[carta_seleccionada[1]]==("FUEGO")){
    cout<<">>FUEGO le gana a NIEVE,Perdiste la ronda "<<endl<<endl;
    }
//NIEVE VS AGUA/NIEVE VS NIEVE---------------------------------------------------------------------------------------------------------------------------//
    if(elemento[carta_seleccionada[0]]==("NIEVE")&&elemento[carta_seleccionada[1]]==("AGUA")){
    cout<<">>NIEVE le gana a AGUA,Ganaste la ronda"<<endl<<endl;
    }
    else{ if (elemento[carta_seleccionada[0]]==("NIEVE")&&elemento[carta_seleccionada[1]]==("NIEVE")){
        if (numero[carta_seleccionada[0]]>numero[carta_seleccionada[1]]){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda "<<endl<<endl;
        }
    }
    }
       if(elemento[carta_seleccionada[0]]==("AGUA")&&elemento[carta_seleccionada[1]]==("NIEVE")){
    cout<<">>NIEVE le gana a AGUA,Perdiste la ronda "<<endl<<endl;
       }
//AGUA VS FUEGO/AGUA VS AGUA------------------------------------------------------------------------------------------------------------------------//
    if(elemento[carta_seleccionada[0]]==("AGUA")&&elemento[carta_seleccionada[1]]==("FUEGO")){
    cout<<">>NIEVE le gana a AGUA,Ganaste la ronda"<<endl<<endl;
    }
    else{ if (elemento[carta_seleccionada[0]]==("AGUA")&&elemento[carta_seleccionada[1]]==("AGUA")){
        if (numero[carta_seleccionada[0]]>numero[carta_seleccionada[1]]){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda "<<endl<<endl;
        }
    }
    }
       if(Celemento[carta_seleccionada[0]]==("FUEGO")&&elemento[carta_seleccionada[1]]==("AGUA")){
    cout<<">>NIEVE le gana a AGUA,Perdiste la ronda "<<endl<<endl;
       }

}


int JugarCartaJugador(string elemento[60], string color[60], int numero[60], int mano[60], int id, int cantidad_cartas)
{
    int carta; int eleccion;

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

    eleccion = mano[carta];

    return eleccion;
}


int JugarCartaCpu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano[60], int id)
{

    AgarrarCartaDelMazo(mazo, mano);

    std::array<int,60> mano_ordenada = {OrdenarMano(elemento, numero, mano)};

    cout<<"Cartas en mano de CPU: "<<endl<<endl;
    int cantidad_cartas = 0;
    cantidad_cartas = MostrarMano(elemento, color, numero, mano, true, cantidad_cartas);
    cout<<endl;

    int carta_seleccionada;

    carta_seleccionada = ObtenerSeleccionCartaCpu(mano_ordenada, elemento, color, numero, id, carta_seleccionada);

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

    if(combinacion_ganadora == true)
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
                            if( color[nieve_ordenado[nieve]] != color[fuego_ordenado[fuego]])
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

    /* Puede poner parte grafica aca */

    for(int i = 0; i < 60; i++)
    {
        if(mano_ordenada[i] != -1)
        {
            if(elemento[mano_ordenada[i]] == "NIEVE")
            {
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

    return cantidad_cartas;
}


void MostrarCartaDesafio(int desafios_elegidos[2], string descripciones_cartas_desafio[10], int id)
{
    /* Puede poner parte grafica aca */
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


bool EmpezarRondaMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int desafios_elegidos[2], string descripciones_cartas_desafio[10], int cantidad_cartas)
{
    /* Puede poner parte grafica aca */
    int modo;
    bool agarrar_carta;
    cout<<"3- Robar carta elemento de la pila"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>modo;
    switch(modo)
    {
        case 1:
            rlutil::cls();

            MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);
            agarrar_carta = true;
            break;
        case 2:
            rlutil::cls();

            MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
            agarrar_carta = true;
            break;
        case 3:
            {
                rlutil::cls();

                int card_id = AgarrarCartaDelMazo(mazo, mano_jugador);
                cout<<"--La carta levantada es--"<<endl<<endl;
                cout<<elemento[card_id]<<": #"<<numero[card_id]<<" "<<color[card_id];
                rlutil::anykey();
                agarrar_carta = false;
                break;
            }
        default:
            cout<<"Ingrese una opcion correcta";
            agarrar_carta = true;
            rlutil::anykey();
    }
    return (agarrar_carta);
}


bool JugarRondaMenu(string elemento[60], string color[60], int numero[60], bool mazo[60], int mano_jugador[60], int mano_cpu[60], int desafios_elegidos[2], string descripciones_cartas_desafio[10], int cantidad_cartas)
{
    /* Puede poner parte grafica aca */
    int modo;
    bool agarrar_carta;
    cout<<"3- Jugar una carta"<<endl;
    cout<<endl<<"Que desea hacer?--> ";
    cin>>modo;
    switch(modo)
    {
        case 1:
            rlutil::cls();

            MostrarCartaDesafio(desafios_elegidos, descripciones_cartas_desafio, 0);
            agarrar_carta = false;
            break;
        case 2:
            rlutil::cls();

            MostrarMano(elemento, color, numero, mano_jugador, false, cantidad_cartas);
            agarrar_carta = false;
            break;
        case 3:
            CartasJugadasJugadorCpu(elemento, color, numero, mazo, mano_jugador, mano_cpu, cantidad_cartas);
            agarrar_carta = true;
            break;
        default:
            cout<<"Ingrese una opcion correcta";
            agarrar_carta = false;
            rlutil::anykey();
    }
    return (agarrar_carta);
}


void MejorPuntaje(string nombrejugador)
{
    /* Puede poner parte grafica aca */
    /* Ojo que aun no va a devolver nada aca, diria de dejarlo para mas
       adelante cuando este terminado la forma de juego */
    rlutil::setBackgroundColor(rlutil::color::BROWN);
    rlutil::cls();
    rlutil::locate(2,2);
    cout << "Partidas:" << endl;
    rlutil::locate(2,3);
    cout << "Nombre de usuario: " << nombrejugador;
    rlutil::anykey();
}


void Reglas()
{
    /* Puede poner parte grafica aca */
    /* Directamente hay que explicarlas de forma resumida */

}


void Creditos()
{
    /* Puede poner parte grafica aca */
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
bool Seguroquieressalir(){
    bool desicion;
    rlutil::setBackgroundColor(rlutil::color::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::color::WHITE);
    Recuadro();
    rlutil::locate(44,13);
    cout << "¿Seguro quieres salir del juego? ";
    rlutil::locate(44,14);
    cout << "Si sales, se perdera tu progreso ";
    rlutil::locate(48,15);
    cout << "Te dejo que lo pienses";
    rlutil::locate(48,17);
    cout << "1-Si             0-No";
    rlutil::setColor(rlutil::color::BLACK);
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
    cout << "Gracias por juegar  :)" << endl;
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
void Cargando(){
rlutil::locate(51,8);
    cout << "Cargando...";
    for (int x=0;x<109;x++){
        rlutil::locate (6+x,8);
        cout << "_";
        Sleep(20);
    }

}

