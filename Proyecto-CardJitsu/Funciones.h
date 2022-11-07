#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>
#include<array>

using namespace std;

void Mode();
void PlayerVsCpu();
void CpuVsCpu();
void SetDeck(bool mazo[], int mano_jugador1[], int mano_jugador2[], bool cartas_desafio[]);
void SetChallengeCard(bool cartas_desafio[], int desafios_elegidos[]);
void SelectChallenge(bool cartas_desafio[], int desafios_elegidos[], int id);
void RandomChallenge(bool cartas_desafio[], int desafios_elegidos[], int id);
bool SelectChallengeIfPossible(int id_desafio, int desafios_elegidos[], int id, bool cartas_desafio[]);
void LoadDeck(string elemento[], string color[], int numero[]);
void LoadChallenge(string descripciones_cartas_desafio[]);
int TakeCardFromDeck(bool mazo[],int mano[]);
void TakeCard(int mano[], int card_id);
void ShowHand(string elemento[], string color[], int numero[], int mano[]);
void ShowChallengeCard(int desafios_elegidos[], string descripciones_cartas_desafio[], int id);
std::array<int,60> SortHand(string elemento[], int numero[], int mano[]);
bool IsCardHigher(int carta_a, int carta_b, string elemento[], int numero[]);
bool StartRoundMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[]);
bool PlayRoundMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[], int desafios_elegidos[], string descripciones_cartas_desafio[]);

void BestScore(string nombrejugador);
void Credits();
void Rules();
void ExitGame();



#endif // FUNCIONES_H_INCLUDED
