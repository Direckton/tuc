/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
#include "FileOpener.h"

using namespace std;

string read_file_content(string fileName)
{
	string line;
	char content;
	
	fstream fileStream;
	fileStream.open(fileName);
	if(fileStream)
	{
		while (!fileStream.eof())
		{
			fileStream.get(content);
			line.push_back(content);
		}
		
	}
	else
	{
		string errorMessage = { "An error has occurred! Please make sure the file:  exist." };
		errorMessage.insert(50, fileName);
		throw  errorMessage;
	}
	fileStream.close();
	line.pop_back();	//gets rid of doubled element form while loop
	
	if (line.empty())
	{
		string errorMessage = { "An error has occurred! Please make sure the file:  is not empty." };
		errorMessage.insert(50, fileName);
		throw  errorMessage;
	}

	return line;
}

int gate_counter(string fileName)
{
	string count;
	count = read_file_content(fileName);
	int i = -1;
	while (!count.empty())
	{
		char enter = count.back();
		if (enter == '\n')	//detect new line
		{
			i++;
		}
		count.pop_back();
	}
	return i;
}

