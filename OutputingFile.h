/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
//Plik nag��wkowy funkcji OutputingFile.cpp

#ifndef OUTPUTINGFILE_H
#define OUTPUTINGFILE_H

#include <fstream>
#include <string>

using namespace std;

/**
 Funkcja nadaje nag��wek "IN: " dla ka�dej pary wej��
 @param input przekazuje kopi� pliku zawieraj�cego wej�cia
 @return zwraca string z wej�ciami i nag��wkami*/
string create_input(string input);

/**
 Funkcja nadaje nag��wek "OUT: " wraz z w�z�em wyj�ciowym, po czym przypisuje stan wyj�cia
 @param output nag��wek "OUT: " wraz z w�z�em pobranym z pliku wej�ciowego
 @param content string zawieraj�cy wej�cia i ich warto�ci
 @param outputValues stany wyj�ciowe dla konkretnej pary wej��*/
void create_output(string &output, string content, string outputValues);

/**
 Funkcja zapisuj�ca sformatowany string do pliku
 @param fileStream string zawieraj�cy nazw� pliku wyj�ciowego
 @param str sformatowany string zawieraj�cy informacje o wej�ciach i wyj�ciach*/
void save_output_to_file(string fileStream, string str);

#endif
