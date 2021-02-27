/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag³ówkowy funkcji listLoader.cpp

#ifndef LISTLOADER_H
#define LISTLOADER_H

#include <string>
#include <list>
#include "fileOpener.h"

using namespace std;

/**
 Struktora opisuj¹ca bramkê logiczn¹
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

/** Funkcja dodaj¹ca elemnt do listy
 @param role nazwa bramki logicznej
 @param input_knot1 pierwszy wêze³ bramki logicznej
 @param input_val1 stan pierszego wêz³a bramki logicznej
 @param input_knot2 drugi wêze³ bramki logicznej
 @param input_val2 stan drugiego wêz³a bramki logicznej
 @param output_knot1 wêze³ wyjœciowy bramki logicznej
 @param input_val1 stan wêz³a wyjœciowego bramki logicznej
 @return wskaŸnik na iterator listy
 */
Schematics add_element_to_list(string role, int input_knot1, bool input_val1, int input_knot2, bool input_val2, int output_knot, bool output_val);

/** Funkcja odwracaj¹ca string
 @param str string wejœciowt
 @return odwrócony string
*/
string reverse_string(string str);

/** Funkcja odczytuj¹ca parametry bramek ze stringu
 @param content string wejœciowy zawieraj¹cy informacje o bramkach
 @param gateNumber liczba wszystkich bramek w uk³adzie
 @param temp lista do której zostan¹ wczytane bramki wraz z wartoœciami im odpowiedaj¹cymi
 */
void assign_elements(string &content, int gateNumber, list<Schematics> &temp);

/** Funkcja wybieraj¹ca której bramce przypisaæ stan wejœciowy
 @param role nazwa bramki logicznej
 @param input_knot1 pierwszy wêze³ bramki logicznej
 @param input_val1 stan pierszego wêz³a bramki logicznej
 @param input_knot2 drugi wêze³ bramki logicznej
 @param input_val2 stan drugiego wêz³a bramki logicznej
 @param temp lista bramek logicznych
 */
void choose_input(int inputKnot1, int inputKnot2, bool inputState1, bool inputState2, list<Schematics>& temp);

/** Funkcja wczytuj¹ca stany wejœciowe wybranych bramek
@param temp lista bramek logicznych
@param str string zawieraj¹cy stany wejœciowe 
*/
void assign_values(list<Schematics> &temp, string &str);

/** Funkcja pobieraj¹ca wêze³ wyjœciowy uk³adu
 @param content plik wejœciowy zawiearaj¹cy informacjê o wêŸle wyjœciowym
 @return integer wêz³a wyjœciowego
*/
int extract_output_int(string content);

#endif