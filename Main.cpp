/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
#include <iostream>
#include <string>
#include <list>
#include "FileOpener.h"
#include "ListLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"
#include "ArgumentParser.h"

using namespace std;


int main(int argc, char **argv)
{
	map<int, string> parser = argParser(argc, argv);

	string layoutFile;
	string valuesFile;
	string outputFile;

	assignArguments(layoutFile, valuesFile, outputFile, parser);
	
	cout << "Starting..." << endl;
	
	int gateNumber = gate_counter(layoutFile);
	string content = read_file_content(layoutFile);
	string values = read_file_content(valuesFile);
	string output;
	output.assign(values);

	cout << "File content read correctly" << endl;
	
	output = create_input(output);
	
	list<Schematics> temp;
	auto it= temp.begin();
	assign_elements(content, gateNumber,temp);

	cout << "List created" << endl;
	
	string outputValues;
	while (!values.empty())
	{
		it = temp.begin();
		assign_values(temp, values);
		it = temp.begin();
		calculate_outputs(temp, it->input_knot1, it->input_knot2);
		if (find_value(temp, extract_output_int(content)) == true)
			outputValues.push_back('1');
		else
			outputValues.push_back('0');
	}

	cout << "Values calculated" << endl;
	
	create_output(output, content, outputValues);
	save_output_to_file(outputFile,output);

	cout << "Output file generated" << endl;
	return 0;
} 