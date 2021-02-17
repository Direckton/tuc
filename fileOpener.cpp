#include "fileOpener.h"
#include "listLoader.h"

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
	fileStream.close();
	line.pop_back();	//gets rid of dubed element form while loop

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
			i++;
		count.pop_back();
	}
	return i;
}

