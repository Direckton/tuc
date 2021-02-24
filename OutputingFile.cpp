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

string create_output(string output)
{
	int n = output.length() % 11;

	for (int i = n; i >= 0; i--)
	{
		int p = i * 7 + i;
		output.insert(p, "IN: ");
	}

	return output;
}

void save_output_to_file(string filestream)
{
	ofstream fs;
	fs.open(filestream);
	if (fs)
	{
		fs << "output is 123" << flush;
	}
	fs.close();
}