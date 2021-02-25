#include "OutputingFile.h"

string create_input(string input)
{
	int n = input.length() % 7;
	
 	for(int i=n; i >= 0; i--)
	{
		int p = i * 7 + i;
		input.insert(p, "IN: ");
	}
	
	return input;
}

string create_output(string output, string content, int state)
{
	content.insert(7, ":");
	content.push_back(state);
	int n = output.length() % 11;
	return output;
}

void save_output_to_file(string filestream, string str)
{
	ofstream fs;
	fs.open(filestream);
	if (fs)
	{
		fs << str << flush;
	}
	fs.close();
}