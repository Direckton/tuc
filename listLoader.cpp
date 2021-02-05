#include "listLoader.h"


Schematics addElementToList(string role, int in_knot1,bool in_val1,int in_knot2,bool in_val2,int out_knot,bool out_val)
{
	list<Schematics> gateList;
	list<Schematics>::iterator it = gateList.begin();
	gateList.emplace_back(Schematics(role,in_knot1,in_val1,in_knot2,in_val2,out_knot,out_val));

	
	Schematics lul = gateList.back();
	it = gateList.begin();
	return *it;
}

//string return_line()
//{
//	
//}

Schematics assign_elements(string content, int gate_number)
{
	if(!content.empty())
	{
		string temp;
		if(content!=' ')
		{
			temp 
		}
		
	}
	
	list<Schematics> temp;
	list<Schematics>::iterator it = temp.begin();
	temp.emplace_front(addElementToList(it->role, it->input_knot1, false, it->input_knot2, false, it->output_knot, false));
}


