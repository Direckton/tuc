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

string reverse_string(string str)
{
	int character_count = str.length();

	for (int i = 0; i < character_count / 2; i++)
		swap(str[i], str[character_count - i - 1]);
	return str;
}

void assign_elements(string content,int gateNumber, list<Schematics> &temp)
{

	list<Schematics>::iterator it = temp.begin();
	int switching_value = 0;
	string piece;
	int out_knot = 0;
	int in_knot1 = 0;
	int in_knot2 = 0;
	string role;
	
	while (!content.empty())
	{
		if (content.back() == '\n')
		{
			switching_value = 0;
			temp.emplace_front(addElementToList(role, in_knot1, false, in_knot2, false, out_knot, false));
			content.pop_back();
			gateNumber--;
			if (gateNumber == 0)
				return;

		}
		while(content.back() !=' ' and content.back() != '\n')
		{
			piece.push_back(content.back());
			content.pop_back();
		}

		piece = reverse_string(piece);
	
		switch (switching_value)
		{
		case 0:
			out_knot = stoi(piece);
			piece.clear();
			break;
		case 1:
			in_knot2 = stoi(piece);
			piece.clear();
			break;
		case 2:
			in_knot1 = stoi(piece);
			piece.clear();
			break;
		case 3:
			role = piece;
			piece.clear();
			switching_value = 0;
			break;
		}

		if (content.back() == ' ')
		{
			content.pop_back();
			switching_value++;
		}
		
	}
}

void choose_input(int in_knot1, int in_knot2, bool in_state1, bool in_state2, list<Schematics>& temp)
{

	auto it = temp.begin();
	int break_value = 0;
	while (it != temp.end())
	{
		if (in_knot1 == it->input_knot1)
		{
			it->input_val1 = in_state1;
			break_value++;
		}
		if (in_knot2 == it->input_knot2)
		{
			it->input_val2 = in_state2;
			break_value++;
		}
		if (in_knot1 != it->input_knot1 or in_knot2 != it->input_knot2)
			it++;
		if (break_value == 2)
			return;
	}
}

void assign_values(list<Schematics> temp)
{/*create secondary list which includes all the states and pass it on logic operator which
	find the elements from that string in list  */
	auto it = temp.begin();
	string str = read_file_content("values.txt");
	int iteration = 0;
	int switching_value = 0;
	string line;
	int in_knot1 = 0;
	int in_knot2 = 0;
	bool in_state1=true;
	bool in_state2=true;

	while (!str.empty())
	{
		if(str.back()=='\n')
		{
			iteration++;
			line.clear();
			str.pop_back();
			switching_value = 0;
			choose_input(in_knot1, in_knot2, in_state1, in_state2, temp);
			
		}

		while(str.back()!=' ' and str.back() != ':' and str.back() != '\n')
		{
			line.push_back(str.back());
			str.pop_back();
			if (str.empty())
				break;
		}
		reverse_string(line);

		switch(switching_value)
		{
		case 0:
		in_state2 = stoi(line);
		switching_value++;
		str.pop_back();
		line.clear();
		break;
		case 1:
		in_knot2 = stoi(line);
		switching_value++;
		str.pop_back();
		line.clear();
		break;
		case 2:
		in_state1 = stoi(line);
		switching_value++;
		str.pop_back();
		line.clear();
		break;
		case 3:
		in_knot1 = stoi(line);
		switching_value++;
		line.clear();
		break;
		}	
	}
}
