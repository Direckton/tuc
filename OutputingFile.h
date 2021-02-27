/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
//Plik nag³ówkowy funkcji OutputingFile.cpp

#ifndef OUTPUTINGFILE_H
#define OUTPUTINGFILE_H

#include <fstream>
#include <string>

using namespace std;

/**
 Funkcja nadaje nag³ówek "IN: " dla ka¿dej pary wejœæ
 @param input przekazuje kopiê pliku zawieraj¹cego wejœcia
 @return zwraca string z wejœciami i nag³ówkami*/
string create_input(string input);

/**
 Funkcja nadaje nag³ówek "OUT: " wraz z wêz³em wyjœciowym, po czym przypisuje stan wyjœcia
 @param output nag³ówek "OUT: " wraz z wêz³em pobranym z pliku wejœciowego
 @param content string zawieraj¹cy wejœcia i ich wartoœci
 @param outputValues stany wyjœciowe dla konkretnej pary wejœæ*/
void create_output(string &output, string content, string outputValues);

/**
 Funkcja zapisuj¹ca sformatowany string do pliku
 @param fileStream string zawieraj¹cy nazwê pliku wyjœciowego
 @param str sformatowany string zawieraj¹cy informacje o wejœciach i wyjœciach*/
void save_output_to_file(string fileStream, string str);

#endif
