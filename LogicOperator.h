/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag��wkowy funkcji fileOpener.cpp

#ifndef LOGICOPERATOR_H
#define LOGICOPERATOR_H

#include <list>
#include <string>
#include "listLoader.h"

using namespace std;

/**Funkcja wykonuj�ca obliczenia logiczne
 @param state1 pierwszy stan wej�ciowy
 @param state2 drugi stan wej�ciowy
 @param nazwa bramki logicznej
 @return warto�� logiczna na wyj�ciu bramki
*/
bool gate(bool state1, bool state2, string gate);

/**Funkcja szukaj�ca konkretnej warto�ci na w�le wyj�ciowym bramki
@param temp lista bramek logicznych
@param input_knot w�ze� szukanej warto�ci
@return stan na zadanym w�le
*/
bool find_value(list<Schematics> temp, int input_knot);
/**Funkcja przypisuj�ca wart�ci wyj�ciowe bramk�
 @param temp lista bramek
 @param in_knot1 pierwszy w�ze� wej�ciowy z wiadomym stanem
 @param in_knot2 drugi w�ze� wej�ciowy z wiadomym stanem
 */
void calculate_outputs(list<Schematics>& temp, int in_knot1, int in_knot2);

#endif