#include <iostream>
#include <string>
#include <list>
#include "argparse.hpp"
#include "fileOpener.h"
#include "listLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"

using namespace std;


int main(int argc, const char **argv)
{
	
	argparse::ArgumentParser program("Basically_tuc is a program used to solve circuits based on 2 input logic gates.");

	program.add_argument("-u")
		.required()
		.help("Please enter gate layout file name");

	program.add_argument("-i")
		.required()
		.help("Please enter input values file name");

	program.add_argument("-o")
		.required()
		.help("Please enter output file name");

	try {
		program.parse_args(argc, argv);   
	}
	catch (const std::runtime_error& err) {
		std::cout << err.what() << std::endl;
		std::cout << program;
		exit(0);
	}

	auto layout_file = program.get<string>("-u");
	auto values_file = program.get<string>("-i");
	auto output_file = program.get<string>("-o"); 
	
	cout << "Starting..." << endl;
	
	int gateNumber = gate_counter(layout_file);
	string content = read_file_content(layout_file);
	string values = read_file_content(values_file);
	string output;
	output.assign(values);

	cout << "File content read correctly" << endl;
	
	output = create_input(output);
	
	list<Schematics> temp;
	list<Schematics>::iterator it= temp.begin();
	assign_elements(content, gateNumber,temp);

	cout << "List created" << endl;
	
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

	cout << "Values calculated" << endl;
	
	create_output(output, content, output_values);
	save_output_to_file(output_file,output);

	cout << "Output file generated" << endl;
	return 0;
} 