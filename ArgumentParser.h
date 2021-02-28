/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag³ówkowy funkcji ArgumentParser.cpp
#pragma once

#include <map>
#include <iostream>
#include <string>

using namespace std;

/**Funkcja zapisuje do mapy argument pobrane z konsoli
 @param argc liczba argumentów
 @param argv wskaŸnik na tablicê argumentów
 @return mapa wczytanych argumentów
 */
map<int, string> argParser(int argc, char **argv);

/**Funkcja przypisuje odpowiednie nazwy plików w zale¿noœci od argumentu
 @param layoutFile plik zawieraj¹cy konfiguracjê uk³adu 
 @param valuesFile plik zawieraj¹cy konfiguracjê stanów wejœæ uk³adu
 @param layoutFile plik do którego zostanie zapisane rozwi¹zanie
 @param parser mapa argumentów pobranych z konsoli
 */
void assignArguments(string& layoutFile, string& valuesFile, string& outputFile, map<int, string> parser);

/**Funkcja obs³uguj¹cy b³êdne dane podane w konsoli
 @param parser mapa argumentów pobranych z konsoli
 */
void exceptions(map<int, string> parser);

/**Funkcja wyœwietlaj¹ca pomoc
 @param errorMessage informacja, dlaczego funkcja zosta³a wywo³ana
 */
void help_message(string errorMessage);

/**Funkcja sprawdzaj¹ca czy warunek wyœwietlenia pomocy zosta³ spe³niony
 @param parser mapa argumentów pobranych z konsoli
 @param argc liczba argumentów
 */
void help(map<int, string> parser, int argc);
