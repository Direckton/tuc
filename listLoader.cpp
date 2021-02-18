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
	int out_knot;
	int in_knot1;
	int in_knot2;
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

void assign_values()
{
	string str = read_file_content("values.txt");

	while (!str.empty())
	{
		
	}
}
