/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag³ówkowy funkcji fileOpener.cpp

#ifndef FILEOPENER_H
#define FILEOPENER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace  std;

/**Funkcja otwiera plik oraz wczytuje jego zawartoœæ do stringu
 @param fileName nazwa pliku, który bêdzie odczytywany
 @return zawartoœæ pliku
 */
string read_file_content(string fileName);

/**Funkcja liczy ilosæ bramek logicznych w uk³adzie
 @param fileName nazwa pliku, z którego bêdzie odczytana iloœæ bramek
 @return iloœæ bramek
 */
int gate_counter(string fileName);

#endif