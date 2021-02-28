/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag��wkowy funkcji ArgumentParser.cpp
#pragma once

#include <map>
#include <iostream>
#include <string>

using namespace std;

/**Funkcja zapisuje do mapy argument pobrane z konsoli
 @param argc liczba argument�w
 @param argv wska�nik na tablic� argument�w
 @return mapa wczytanych argument�w
 */
map<int, string> argParser(int argc, char **argv);

/**Funkcja przypisuje odpowiednie nazwy plik�w w zale�no�ci od argumentu
 @param layoutFile plik zawieraj�cy konfiguracj� uk�adu 
 @param valuesFile plik zawieraj�cy konfiguracj� stan�w wej�� uk�adu
 @param layoutFile plik do kt�rego zostanie zapisane rozwi�zanie
 @param parser mapa argument�w pobranych z konsoli
 */
void assignArguments(string& layoutFile, string& valuesFile, string& outputFile, map<int, string> parser);

/**Funkcja obs�uguj�cy b��dne dane podane w konsoli
 @param parser mapa argument�w pobranych z konsoli
 */
void exceptions(map<int, string> parser);

/**Funkcja wy�wietlaj�ca pomoc
 @param errorMessage informacja, dlaczego funkcja zosta�a wywo�ana
 */
void help_message(string errorMessage);

/**Funkcja sprawdzaj�ca czy warunek wy�wietlenia pomocy zosta� spe�niony
 @param parser mapa argument�w pobranych z konsoli
 @param argc liczba argument�w
 */
void help(map<int, string> parser, int argc);
