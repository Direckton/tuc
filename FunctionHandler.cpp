#include "FunctionHandler.h"

void run_program(const string& layoutFile, const string& valuesFile, const string& outputFile)
{
	int gateNumber = NULL;
	gateNumber = gate_counter(layoutFile);
	string content = read_file_content(layoutFile);
	string values = read_file_content(valuesFile);

	string output;
	output.assign(values);

	cout << "File content read correctly" << endl;

	output = create_input(output);

	list<Schematics> temp;
	auto it = temp.begin();
	assign_elements(content, gateNumber, temp);

	cout << "List created" << endl;

	string outputValues;
	while (!values.empty())
	{
		it = temp.begin();
		assign_values(temp, values);
		it = temp.begin();
		calculate_outputs(temp, it->input_knot1, it->input_knot2);
		char trueState = '1', falseState = '0';
		if (find_value(temp, extract_output_int(content)) == true)
			outputValues.push_back(trueState);
		else
			outputValues.push_back(falseState);
	}

	cout << "Values calculated" << endl;

	create_output(output, content, outputValues);
	save_output_to_file(outputFile, output);

	cout << "Output file generated" << endl;
}