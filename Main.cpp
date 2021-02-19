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
	

	list<Schematics> temp;
	list<Schematics>::iterator it;
	assign_elements(content, gateNumber,temp);
	assign_values(temp);

	return 0;
}