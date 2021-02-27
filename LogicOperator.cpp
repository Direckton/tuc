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
	if (gate == "NAND")
	{
		return !(state1 and state2);
	}
	if (gate == "OR")
	{
		return state1 or state2;
	}
	if (gate == "NOR")
	{
		return !(state1 or state2);
	}
	if (gate == "XOR")
	{
		return state1 xor state2;
	}
	if (gate == "XNOR")
	{
		return !(state1 xor state2);
	}
	if (gate == "NEG")
	{
		return !state1;
	}
}
bool find_value( list<Schematics> temp, int inputKnot)
{
	auto it = temp.begin();
	while (it->output_knot != inputKnot)
	{
		it++;
	}
	return it->output_val;
}

void calculate_outputs(list<Schematics> &temp, int inputKnot1, int inputKnot2)
{
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
				while(itSupporting->input_knot1!=inputKnot1)
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
				while (itSupporting->input_knot2 != inputKnot2)
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