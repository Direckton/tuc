#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include "fileOpener.h"
#include "listLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"

using namespace std;


int main()
{
	int gateNumber = gate_counter("layout2.txt");
	string content = read_file_content("layout2.txt");
	string values = read_file_content("values.txt");
	string output;
	output.assign(values);

	output = create_input(output);

	output = create_output(output);

	list<Schematics> temp;
	list<Schematics>::iterator it= temp.begin();
	assign_elements(content, gateNumber,temp);
	content;
	save_output_to_file("output.txt");
	
	while (!values.empty())
	{
		it = temp.begin();
		assign_values(temp, values);
		it = temp.begin();
		calculate_outputs(temp, it->input_knot1, it->input_knot2);
	}
	return 0;
}