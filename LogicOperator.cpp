/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
#include "LogicOperator.h"

bool gate(bool state1, bool state2, string gate)
{
	if (gate == "AND")
	{
		return state1 and state2;
	}
	else if (gate == "NAND")
	{
		return !(state1 and state2);
	}
	else if (gate == "OR")
	{
		return state1 or state2;
	}
	else if (gate == "NOR")
	{
		return !(state1 or state2);
	}
	else if (gate == "XOR")
	{
		return state1 xor state2;
	}
	else if (gate == "XNOR")
	{
		return !(state1 xor state2);
	}
	else if (gate == "NEG")
	{
		return !state1;
	}
	else
	{
		string errorMessage = { "An error has occurred! Program has encounter wrong gate name. Please make sure gates are correctly labeled." };
		throw  errorMessage;
	}
}
bool find_value( list<Schematics> temp, int inputKnot)
{
	if (temp.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the list of elements is not empty." };
		throw  errorMessage;
	}
	auto it = temp.begin();
	while (it->output_knot != inputKnot)
	{
		it++;
		if (it==temp.end())
		{
			string errorMessage = { "An error has occurred! Program was to find correct value for state to assign to." };
			throw  errorMessage;
		}
	}
	return it->output_val;
}

void calculate_outputs(list<Schematics> &temp, int inputKnot1, int inputKnot2)
{
	if (temp.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the list of elements is not empty." };
		throw  errorMessage;
	}
	auto it=temp.begin();
	auto itSupporting = temp.begin();
	
	while (it != temp.end())
	{
		if (inputKnot1 == it->input_knot1 and inputKnot2 == it->input_knot2)
		{
			it->output_val = gate(it->input_val1, it->input_val2, it->role);
			it++;
			
		}
		else
		{
			if(inputKnot1 == it->input_knot1)
			{
				itSupporting = temp.begin();
				while(itSupporting->input_knot1!=inputKnot1 or itSupporting == temp.end())
				{
					itSupporting++;
				}
				it->input_val1 = itSupporting->input_val1;
			}
			else
			{
				it->input_val1 = find_value(temp, it->input_knot1);
			}
			if(inputKnot2 == it->input_knot2)
			{
				itSupporting = temp.begin();
				while (itSupporting->input_knot2 != inputKnot2 or itSupporting==temp.end())
				{
					itSupporting++;
				}
				it->input_val2 = itSupporting->input_val2;
			}
			else
			{
				it->input_val2 = find_value(temp, it->input_knot2);
			}
			it->output_val = gate(it->input_val1, it->input_val2, it->role);
			it++;
		}
		
	}
}