/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag��wkowy funkcji fileOpener.cpp

#ifndef FILEOPENER_H
#define FILEOPENER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace  std;

/**Funkcja otwiera plik oraz wczytuje jego zawarto�� do stringu
 @param fileName nazwa pliku, kt�ry b�dzie odczytywany
 @return zawarto�� pliku
 */
string read_file_content(string fileName);

/**Funkcja liczy ilos� bramek logicznych w uk�adzie
 @param fileName nazwa pliku, z kt�rego b�dzie odczytana ilo�� bramek
 @return ilo�� bramek
 */
int gate_counter(string fileName);

#endif