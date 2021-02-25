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

void create_output(string &output, string content, bool state)
{
	int numState;
	if (state == true)
		numState = 1;
	else
		numState = 0;
	content.push_back(':');
	content.push_back(numState);
	int p = output.length() % 11;
	output.insert(11 * 4 + p, content);

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