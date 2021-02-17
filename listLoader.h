#include <string>
#include <iostream>
#include <list>

#pragma once

using namespace std;

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


Schematics addElementToList(string role, int input_knot1, bool input_val1, int input_knot2, bool input_val2, int output_knot, bool output_val);

Schematics assign_elements(string content, int gateNumber);