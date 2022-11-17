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

void Modo(int Puntos_Jugador[],int cont_jugadores);
void JugadorVsCpu(int Puntos_Jugador[],int cont_jugadores);
void CpuVsCpu();
void ColocarMazo(bool mazo[], int mano_jugador1[], int mano_jugador2[], bool cartas_desafio[]);
void ColocarCartasDesafio(bool cartas_desafio[], int desafios_elegidos[]);
void SeleccionarDesafio(bool cartas_desafio[], int desafios_elegidos[], int id);
void DesafioAleatorio(bool cartas_desafio[], int desafios_elegidos[], int id);
bool SeleccionarDesafioSiEsPosible(int id_desafio, int desafios_elegidos[], int id, bool cartas_desafio[]);
void CartasJugadasJugadorCpu(string elemento[], string color[], int Puntos_Jugador[],int cont_jugadores, int numero[], bool mazo[], int mano_jugador[], int mano_cpu[]);
int JugarCartaJugador(string elemento[], string color[], int numero[], int mano[], int id, int cantidad_cartas);
int JugarCartaCpu(string elemento[], string color[], int numero[], bool mazo[], int mano[], int id);
bool ComparativaCartasJugadas(std::array<int,2>  carta_seleccionada, int Puntos_Jugador[],int cont_jugadores, int mano_jugador[], int mano_cpu[], string elemento[], string color[], int numero[], string elemento1, string elemento2);
void MostrarCartasEnfrentadas(std::array<int,2>  carta_seleccionada,string elemento[], string color[], int numero[]);
void ElGanadorEs(std::array<int,2>  carta_seleccionada, int Puntos_Jugador[],int cont_jugadores,int mano_jugador[],int mano_cpu[],string elemento[], string color[], int numero[] );
void SiLosElementosSonIguales(std::array<int,2>  carta_seleccionada, int Puntos_Jugador[],int mano_jugador[], int mano_cpu[],int cont_jugadores,int numero[]);
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
bool EmpezarRondaMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cantidad_cartas);
bool JugarRondaMenu(string elemento[], string color[],int Puntos_Jugador[], int cont_jugadores, int numero[], bool mazo[], int mano_jugador[], int mano_cpu[], int desafios_elegidos[], string descripciones_cartas_desafio[], int cantidad_cartas);
void MostrarCartasEnfrentadas(std::array<int,2>  carta_seleccionada, string elemento[60], string color[60], int numero[60]);
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

/// Diseño

void Recuadro();
void Nombrejuego();
void Cargando();
void InterfazCambioDeJugador();
void LogoPartidas();



#endif // FUNCIONES_H_INCLUDED
