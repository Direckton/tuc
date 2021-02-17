

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include "fileOpener.h"
#include "listLoader.h"

using namespace std;

int main()
{
	int gateNumber = gate_counter("layout.txt");
	string content = read_file_content("layout.txt");
	string values = read_file_content("values.txt");


	list<Schematics> temp;
	list<Schematics>::iterator it;
	*it = assign_elements(content, gateNumber);

	
	
	return 0;
}