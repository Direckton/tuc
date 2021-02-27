/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag��wkowy funkcji listLoader.cpp

#ifndef LISTLOADER_H
#define LISTLOADER_H

#include <string>
#include <list>
#include "fileOpener.h"

using namespace std;

/**
 Struktora opisuj�ca bramk� logiczn�
 */
struct Schematics
{
	string role;
	int input_knot1;
	bool input_val1;
	int input_knot2;
	bool input_val2;
	int output_knot;
	bool output_val;
	Schematics(string role, int input_knot1, bool input_val1, int input_knot2, bool input_val2, int output_knot, bool output_val)
	{
		this->role = role;
		this->input_knot1 = input_knot1;
		this->input_val1 = input_val1;
		this->input_knot2 = input_knot2;
		this->input_val2 = input_val2;
		this->output_knot = output_knot;
		this->output_val = output_val;
	}
};

/** Funkcja dodaj�ca elemnt do listy
 @param role nazwa bramki logicznej
 @param input_knot1 pierwszy w�ze� bramki logicznej
 @param input_val1 stan pierszego w�z�a bramki logicznej
 @param input_knot2 drugi w�ze� bramki logicznej
 @param input_val2 stan drugiego w�z�a bramki logicznej
 @param output_knot1 w�ze� wyj�ciowy bramki logicznej
 @param input_val1 stan w�z�a wyj�ciowego bramki logicznej
 @return wska�nik na iterator listy
 */
Schematics add_element_to_list(string role, int input_knot1, bool input_val1, int input_knot2, bool input_val2, int output_knot, bool output_val);

/** Funkcja odwracaj�ca string
 @param str string wej�ciowt
 @return odwr�cony string
*/
string reverse_string(string str);

/** Funkcja odczytuj�ca parametry bramek ze stringu
 @param content string wej�ciowy zawieraj�cy informacje o bramkach
 @param gateNumber liczba wszystkich bramek w uk�adzie
 @param temp lista do kt�rej zostan� wczytane bramki wraz z warto�ciami im odpowiedaj�cymi
 */
void assign_elements(string &content, int gateNumber, list<Schematics> &temp);

/** Funkcja wybieraj�ca kt�rej bramce przypisa� stan wej�ciowy
 @param role nazwa bramki logicznej
 @param input_knot1 pierwszy w�ze� bramki logicznej
 @param input_val1 stan pierszego w�z�a bramki logicznej
 @param input_knot2 drugi w�ze� bramki logicznej
 @param input_val2 stan drugiego w�z�a bramki logicznej
 @param temp lista bramek logicznych
 */
void choose_input(int inputKnot1, int inputKnot2, bool inputState1, bool inputState2, list<Schematics>& temp);

/** Funkcja wczytuj�ca stany wej�ciowe wybranych bramek
@param temp lista bramek logicznych
@param str string zawieraj�cy stany wej�ciowe 
*/
void assign_values(list<Schematics> &temp, string &str);

/** Funkcja pobieraj�ca w�ze� wyj�ciowy uk�adu
 @param content plik wej�ciowy zawiearaj�cy informacj� o w�le wyj�ciowym
 @return integer w�z�a wyj�ciowego
*/
int extract_output_int(string content);

#endif