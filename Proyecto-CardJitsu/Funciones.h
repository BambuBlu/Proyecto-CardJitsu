#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<ctime>

using namespace std;

void Mode();
void PlayerVsCpu();
void CpuVsCpu();
void SetDeck(bool mazo[], int mano_jugador1[], int mano_jugador2[]);
void LoadDeck(string elemento[], string color[], int numero[]);
int TakeCardFromDeck(bool mazo[],int mano[]);
void TakeCard(int mano[], int card_id);
void ShowHand(string elemento[], string color[], int numero[], int mano[]);
int SortHand(string elemento[], int numero[], int mano[]);
bool IsCardHigher(int carta_a, int carta_b, string elemento[], int numero[]);
bool StartRoundMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[]);
bool PlayRoundMenu(string elemento[], string color[], int numero[], bool mazo[], int mano_jugador[]);

void BestScore(string nombrejugador);
void Credits();
void Rules();
void ExitGame();



#endif // FUNCIONES_H_INCLUDED
