#include "LogicOperator.h"

bool gate(bool state1, bool state2, string gate)
{
	if (gate=="AND")
		return state1 and state2;
	if (gate=="NAND")
		return !(state1 and state2);
	if (gate=="OR")
		return state1 or state2;
	if (gate == "NOR")
		return !(state1 or state2);
	if (gate == "XOR")
		return state1 xor state2;
	if (gate == "XNOR")
		return !(state1 xor state2);
	if (gate == "NEG")
		return !state1;
}
bool find_in_val( list<Schematics> temp, int input_knot)
{
	auto it = temp.begin();
	it++;
	return it->output_val;
	
}

void calculate_outputs(list<Schematics> &temp, int in_knot1, int in_knot2)
{
	auto it=temp.begin();

	{
		while (it != temp.end())
		{
			if (in_knot1 == it->input_knot1 and in_knot2 == it->input_knot2)
			{
				it->output_val = gate(it->input_val1, it->input_val2, it->role);
				it++;
			}
			else
			{
				find_in_val(temp, it->input_knot1);
				it->output_val = gate(it->input_val1, it->input_val2, it->role);
				it++;
			}
			
		}
	}
	
	
}