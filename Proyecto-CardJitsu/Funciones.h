#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<array>
#include<map>
#include<time.h>

using namespace std;


/// Jugabilidad

void Modo(int Puntos_Jugador[],int cont_jugadores, string nombre_jugador[]);
void JugadorVsCpu(int Puntos_Jugador[],int cont_jugadores, string nombre_jugador[]);
void CpuVsCpu();
void ColocarMazo(bool mazo[], int mano_jugador1[], int mano_jugador2[], bool cartas_desafio[], int cont_desafios[], bool navegacion[], int hitos_partida[]);
void ColocarCartasDesafio(bool cartas_desafio[], int desafios_elegidos[]);
void SeleccionarDesafio(bool cartas_desafio[], int desafios_elegidos[], int id);
void DesafioAleatorio(bool cartas_desafio[], int desafios_elegidos[], int id);
bool SeleccionarDesafioSiEsPosible(int id_desafio, int desafios_elegidos[], int id, bool cartas_desafio[]);
void CartasJugadasJugadorCpu(string elemento[], string color[],int cont_jugadores, int numero[], bool mazo[], int mano_jugador[], int mano_cpu[], int cantidad_cartas, int desafios_elegidos[], int cont_desafios[], bool navegacion[], int hitos_partida[]);
int ElementoEsMayor(string elementoA, string elementoB);
int JugarCartaJugador(string elemento[], string color[], int numero[], int mano[], int id, int cantidad_cartas);
int JugarCartaCpu(string elemento[], string color[], int numero[], bool mazo[], int mano[], int id);
bool VerificarCartaDesafio(int desafios_elegidos, string elemento[], string color[], int numero[], std::array<int,2> carta_seleccionada, int cont_desafios[], int id, bool resultado);
bool GanarCartaElemento(string elemento[], int carta_seleccionada, string tipo_elemento);
bool GanarCartaColor(string color[], int carta_seleccionada, string tipo_color, int color_desafio);
bool GanarCartaMismoElemento(string elemento[], int carta_seleccionada0, int carta_seleccionada1);
bool GanarCartaMismoNumero(int numero[60], int carta_seleccionada0, int carta_seleccionada1, int numero_desafio);
bool GanarRondasConsecutivas(int ronda_desafio, bool resultado);
void MostrarCartasEnfrentadas(std::array<int,2>  carta_seleccionada,string elemento[], string color[], int numero[]);
int ElGanadorEs(std::array<int,2>  carta_seleccionada,int cont_jugadores,int mano_jugador[],int mano_cpu[],string elemento[], string color[], int numero[], int desafios_elegidos[]);
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
void DibujarCartasDeMano( std::array<int,60> mano_ordenada,string elemento[], string color[], int numero[],int i);
void MostrarCartaDesafio(int desafios_elegidos[], string descripciones_cartas_desafio[], int id);
std::array<int,60> OrdenarMano(string elemento[], int numero[], int mano[]);
bool LaCartaEsMayor(int carta_a, int carta_b, string elemento[], int numero[]);
void EmpezarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cantidad_cartas, int ronda, bool navegacion[]);
void JugarRondaMenu(string elemento[], string color[], int cont_jugadores, int numero[], bool mazo[], int mano_jugador[], int mano_cpu[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cont_desafios[], int cantidad_cartas, bool navegacion[],  int hitos_partida[], string nombre_jugador[]);
void HitoFinal(int hitos_partida[], string nombre_jugador[], int jugador, int cont_jugadores);
void MostrarCartasEnfrentadas(std::array<int,2>  carta_seleccionada, string elemento[], string color[], int numero[]);
void LogoCarta(string elemento,string color);
void RetirarCartaPerdida(int carta_seleccionada,int mano[]);
void RobarCartaGanada(int carta_seleccionada,int mano[]);
void DevolverPorEmpate(std::array<int,2>  carta_seleccionada,int mano_jugador[],int mano_cpu[]);
void MejorPuntaje(string nombre_jugador[], int cont_jugadores);
void Creditos();
void Reglas();
bool Seguroquieressalir();
void SalirDelJuego();
void CambiarJugador(string nombre_jugador[], int cont_jugadores);

/// Dise�o

void Recuadro();
void Nombrejuego();
void Cargando();
void InterfazCambioDeJugador();
void LogoPartidas();



#endif // FUNCIONES_H_INCLUDED
