/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
#include "ListLoader.h"


Schematics add_element_to_list(string role, int in_knot1,bool in_val1,int in_knot2,bool in_val2,int out_knot,bool out_val)
{
	list<Schematics> gateList;
	auto it = gateList.begin();
	gateList.emplace_back(Schematics(role,in_knot1,in_val1,in_knot2,in_val2,out_knot,out_val));
	it = gateList.begin();
	return *it;
}

string reverse_string(string str)
{
	int characterCount = str.length();
	if(str.empty())
	{
		string errorMessage = { "An error has occurred! Program has encounter an empty string." };
		throw  errorMessage;
	}

	for (int i = 0; i < characterCount / 2; i++)
	{
		swap(str[i], str[characterCount - i - 1]);
	}
	return str;
}

void assign_elements(string &content,int gateNumber, list<Schematics> &temp)
{
	auto it = temp.begin();
	int switchingValue = 0, outKnot = 0, inputKnot1 = 0, inputKnot2 = 0;
	string role, piece;
	if (content.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the file elements string is not empty." };
		throw  errorMessage;
	}
	if (gateNumber==NULL)
	{
		string errorMessage = { "An error has occurred! Program did not detect any gates. Please make sure the file contains correct layout." };
		throw  errorMessage;
	}
	
	while (!content.empty())
	{
		if (content.back() == '\n')
		{
			switchingValue = 0;
			temp.emplace_front(add_element_to_list(role, inputKnot1, false, inputKnot2, false, outKnot, false));
			content.pop_back();
			gateNumber--;
			if (gateNumber == 0)
			{
				break;
			}
		}
		while(content.back() !=' ' and content.back() != '\n')
		{
			piece.push_back(content.back());
			content.pop_back();
		}

		piece = reverse_string(piece);
	
		switch (switchingValue)
		{
			case 0:
			{
				outKnot = stoi(piece);
				piece.clear();
				break;
			}
			case 1:
			{
				inputKnot2 = stoi(piece);
				piece.clear();
				break;
			}
			case 2:
			{
				inputKnot1 = stoi(piece);
				piece.clear();
				break;
			}
			case 3:
			{
				role = piece;
				piece.clear();
				switchingValue = 0;
				break;
			}
			default:
			{
				string errorMessage = { "An error has occurred! Gate has too many inputs! Please make sure gates are 2 input only." };
				throw  errorMessage;
			}
		}

		if (content.back() == ' ')
		{
			content.pop_back();
			switchingValue++;
		}
		
	}
	piece.clear();
	while(content.back()!='\n')
	{
		piece.push_back(content.back());
		content.pop_back();
	}
	content=reverse_string(piece);
	if(temp.empty())
	{
		string errorMessage = { "An error has occurred! Loading gates layout has failed" };
		throw  errorMessage;
	}
}

void choose_input(int inputKnot1, int inputKnot2, bool inputState1, bool inputState2, list<Schematics>& temp)
{
	auto it = temp.begin();
	int break_value = 0;
	while (it != temp.end())
	{
		if (inputKnot1 == it->input_knot1)
		{
			it->input_val1 = inputState1;
			break_value++;
		}
		if (inputKnot2 == it->input_knot2)
		{
			it->input_val2 = inputState2;
			break_value++;
		}
		if (inputKnot1 != it->input_knot1 or inputKnot2 != it->input_knot2)
		{
			it++;
		}
		if (break_value == 2)
		{
			return;
		}
	}
	if(it == temp.end() and break_value!=2)
	{
		string errorMessage = { "An error has occurred! Program was not able to load correct states to circuit node" };
		throw  errorMessage;
	}
}

void assign_values(list<Schematics> &temp, string &str)
{
	if (str.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the file elements string is not empty." };
		throw  errorMessage;
	}
	if (temp.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the list of elements is not empty." };
		throw  errorMessage;
	}
	auto it = temp.begin();
	int switching_value = 0, in_knot1 = 0, in_knot2 = 0;
	bool inputState1=true, inputState2 = true;
	string line;
	
	while (!str.empty())
	{
		if(str.back()=='\n')
		{
			line.clear();
			str.pop_back();
			switching_value = 0;
			choose_input(in_knot1, in_knot2, inputState1, inputState2, temp);
			break;
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
			{
				inputState2 = stoi(line);
				switching_value++;
				str.pop_back();
				line.clear();
				break;
			}
			case 1:
			{
				in_knot2 = stoi(line);
				switching_value++;
				str.pop_back();
				line.clear();
				break;
			}
			case 2:
			{
				inputState1 = stoi(line);
				switching_value++;
				str.pop_back();
				line.clear();
				break;
			}
			case 3:
			{
				in_knot1 = stoi(line);
				switching_value++;
				line.clear();
				break;
			}
			default:
			{
				string errorMessage = { "An error has occurred! Program was not able to load correct states to circuit node" };
				throw  errorMessage;
			}
		}
		
	}
	if (str.empty())
	{
		choose_input(in_knot1, in_knot2, inputState1, inputState2, temp);
	}
}

int extract_output_int(string content)
{
	if(content.empty())
	{
		string errorMessage = { "An error has occurred! Program was not able assign output node." };
		throw  errorMessage;
	}
	
	string temp;
	while(content.back()!=' ')
	{
		temp.push_back(content.back());
		content.pop_back();
	}
	reverse_string(temp);
	return stoi(temp);
}