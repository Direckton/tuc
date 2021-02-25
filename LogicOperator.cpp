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
bool find_value( list<Schematics> temp, int input_knot)
{
	auto it = temp.begin();
	while (it->output_knot != input_knot)
		it++;
	return it->output_val;
	
}

void calculate_outputs(list<Schematics> &temp, int in_knot1, int in_knot2)
{
	auto it=temp.begin();
	auto it_supp = temp.begin();
	
	while (it != temp.end())
	{
		if (in_knot1 == it->input_knot1 and in_knot2 == it->input_knot2)
		{
			it->output_val = gate(it->input_val1, it->input_val2, it->role);
			it++;
		}
		else
		{
			if(in_knot1 == it->input_knot1)
			{
				it_supp = temp.begin();
				while(it_supp->input_knot1!=in_knot1)
				{
					it_supp++;
				}
				it->input_val1 = it_supp->input_val1;
			}
			else
				it->input_val1=find_value(temp, it->input_knot1);
			if(in_knot2 == it->input_knot2)
			{
				it_supp = temp.begin();
				while (it_supp->input_knot2 != in_knot2)
				{
					it_supp++;
				}
				it->input_val2 = it_supp->input_val2;
			}
			else
				it->input_val2 = find_value(temp, it->input_knot2);
			it->output_val = gate(it->input_val1, it->input_val2, it->role);
			it++;
		}
		
	}

	
	
}