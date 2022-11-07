#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include <time.h>

using namespace std;

void Modo();
void JugadorVsCpu();
void CpuVsCpu();
void ColocarMazo(bool mazo[], int mano_jugador1[], int mano_jugador2[], bool cartas_desafio[]);
void ColocarCartasDesafio(bool cartas_desafio[], int desafios_elegidos[]);
void SeleccionarDesafio(bool cartas_desafio[], int desafios_elegidos[], int id);
void DesafioAleatorio(bool cartas_desafio[], int desafios_elegidos[], int id);
bool SeleccionarDesafioSiEsPosible(int id_desafio, int desafios_elegidos[], int id, bool cartas_desafio[]);
void CargarMazo(string elemento[], string color[], int numero[]);
void CargarDesafio(string descripciones_cartas_desafio[]);
int AgarrarCartaDelMazo(bool mazo[],int mano[]);
void AgarrarCarta(int mano[], int card_id);
void MostrarMano(string elemento[], string color[], int numero[], int mano[]);
void MostrarCartaDesafio(int desafios_elegidos[], string descripciones_cartas_desafio[], int id);
std::array<int,60> OrdenarMano(string elemento[], int numero[], int mano[]);
bool LaCartaEsMayor(int carta_a, int carta_b, string elemento[], int numero[]);
bool EmpezarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[]);
bool JugarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[]);

void MejorPuntaje(string nombrejugador);
void Creditos();
void Reglas();
void SalirDelJuego();

/// Diseño

void Recuadro();
void Nombrejuego();



#endif // FUNCIONES_H_INCLUDED
