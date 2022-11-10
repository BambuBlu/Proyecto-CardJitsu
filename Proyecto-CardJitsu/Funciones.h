#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include<map>

using namespace std;


void Modo();
void JugadorVsCpu();
void CpuVsCpu();
void ColocarMazo(bool mazo[], int mano_jugador1[], int mano_jugador2[], bool cartas_desafio[]);
void ColocarCartasDesafio(bool cartas_desafio[], int desafios_elegidos[]);
void SeleccionarDesafio(bool cartas_desafio[], int desafios_elegidos[], int id);
void DesafioAleatorio(bool cartas_desafio[], int desafios_elegidos[], int id);
bool SeleccionarDesafioSiEsPosible(int id_desafio, int desafios_elegidos[], int id, bool cartas_desafio[]);
void CartasJugadasJugadorCpu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int mano_cpu[]);
int JugarCartaJugador(string elemento[], string color[], int numero[], int mano[], int id, int cantidad_cartas);
int JugarCartaCpu(string elemento[], string color[], int numero[], bool mazo[], int mano[], int id);
int ObtenerSeleccionCartaCpu(std::array<int,60> mano_ordenada, string elemento[], string color[], int numero[], int id, int carta_seleccionada);
void EliminarCartasMano( int cartas_reservadas[], std::array<int,60> mano_ordenada, int mano_jugable[], int id);
int SeleccionarCartaAleatoria(int mano[], int carta_seleccionada);
bool CartasDeCombinacionElementos(string elemento[], string color[], std::array<int,60> mano_ordenada, bool combinacion_ganadora,int cartas_reservadas[]);
void AgregarAPila(int pila[], int card_id);
void InicializarArray(int array_vacio[]);
void CargarMazo(string elemento[], string color[], int numero[]);
void CargarDesafio(string descripciones_cartas_desafio[]);
int AgarrarCartaDelMazo(bool mazo[],int mano[]);
void AgarrarCarta(int mano[], int card_id);
int MostrarMano(string elemento[], string color[], int numero[], int mano[], bool seleccion, int cantidad_cartas);
void MostrarCartaDesafio(int desafios_elegidos[], string descripciones_cartas_desafio[], int id);
std::array<int,60> OrdenarMano(string elemento[], int numero[], int mano[]);
bool LaCartaEsMayor(int carta_a, int carta_b, string elemento[], int numero[]);
bool EmpezarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cantidad_cartas);
bool JugarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int mano_cpu[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cantidad_cartas);

void MejorPuntaje(string nombrejugador);
void Creditos();
void Reglas();
void SalirDelJuego();



#endif // FUNCIONES_H_INCLUDED
