/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag³ówkowy funkcji fileOpener.cpp

#ifndef LOGICOPERATOR_H
#define LOGICOPERATOR_H

#include <list>
#include <string>
#include "listLoader.h"

using namespace std;

/**Funkcja wykonuj¹ca obliczenia logiczne
 @param state1 pierwszy stan wejœciowy
 @param state2 drugi stan wejœciowy
 @param nazwa bramki logicznej
 @return wartoœæ logiczna na wyjœciu bramki
*/
bool gate(bool state1, bool state2, string gate);

/**Funkcja szukaj¹ca konkretnej wartoœci na wêŸle wyjœciowym bramki
@param temp lista bramek logicznych
@param inputKnot wêze³ szukanej wartoœci
@return stan na zadanym wêŸle
*/
bool find_value(list<Schematics> temp, int inputKnot);
/**Funkcja przypisuj¹ca wartœci wyjœciowe bramk¹
 @param temp lista bramek
 @param inputKnot1 pierwszy wêze³ wejœciowy z wiadomym stanem
 @param inputKnot2 drugi wêze³ wejœciowy z wiadomym stanem
 */
void calculate_outputs(list<Schematics>& temp, int inputKnot1, int inputKnot2);

#endif