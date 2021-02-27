/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
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

void create_output(string& output, string content, string outputValues)
{
	int j=0;
	content.push_back(':');
	content.insert(0, " ");
	int i=output.length();
	while(i!=0)
	{
		if(i==output.length())
		{
			content.push_back(outputValues.back());
			outputValues.pop_back();
			output.insert(i, content);
			j++;
		}
		if (output[i]=='\n')
		{
			content.pop_back();
			content.push_back(outputValues.back());
			outputValues.pop_back();
			output.insert(i, content);
			j++;
		}
		i--;
	}
}

void save_output_to_file(string fileStream, string str)
{
	ofstream fs;
	fs.open(fileStream);
	if (fs)
	{
		fs << str  << flush;
	}
	fs.close();
}