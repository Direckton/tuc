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
	int gateNumber = gate_counter("layout.txt");
	string content = read_file_content("layout.txt");
	string values = read_file_content("values.txt");
	string output;
	output.assign(values);

	output = create_input(output);
	
	list<Schematics> temp;
	list<Schematics>::iterator it= temp.begin();
	assign_elements(content, gateNumber,temp);
	
	string output_values;
	while (!values.empty())
	{
		it = temp.begin();
		assign_values(temp, values);
		it = temp.begin();
		calculate_outputs(temp, it->input_knot1, it->input_knot2);
		if (find_value(temp, extract_output_int(content)) == true)
			output_values.push_back('1');
		else
			output_values.push_back('0');
	}

	create_output(output, content, output_values);
	save_output_to_file("output.txt",output);
	return 0;
} 