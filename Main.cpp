#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include "fileOpener.h"
#include "listLoader.h"
#include "LogicOperator.h"

using namespace std;


int main()
{
	int gateNumber = gate_counter("layout.txt");
	string content = read_file_content("layout.txt");
	

	list<Schematics> temp;
	list<Schematics>::iterator it= temp.begin();
	assign_elements(content, gateNumber,temp);
	assign_values(temp);
	it = temp.begin();
	calculate_outputs(temp, it->input_knot1, it->input_knot2);
	return 0;
}