#include "ArgumentParser.h"

void help_message(string errorMessage)
{
	if (!errorMessage.empty())
	{
		cout << "Error message: " << errorMessage << endl;
		cout << endl;
	}
	cout << "Basically_tuc is a program used to solve circuits based on 2 input logic gates." << endl;
	cout << endl;
	cout << "To correctly run this program, please use arguments listed below:" << endl;
	cout << "-u [program layout file]" << endl;
	cout << "-i [program starting inputs file]" << endl;
	cout << "-o [program output file]" << endl;
}

void help(map<int,string> parser, int argc)
{
	if (argc==1)
		help_message("No arguments specified");
	for(int i=1;i<=argc;i++)
	{
		if(parser[i]=="-h")
		{
			help_message("");
		}
	}
}

void exceptions(map<int,string> parser)
{
	for(int i=1; i<=parser.size();i+=2)
	{
		if (parser[i] == "-u")
		{
			if (parser[i+1].empty() or parser[i + 1] == "-i" or parser[i + 1] == "-o")
			{
				help_message("Argument '-u' cannot be empty");
				break;
			}
		}
		else if (parser[i] == "-i")
		{
			if (parser[i + 1].empty() or parser[i+1] == "-u" or parser[i + 1] == "-o")
			{
				help_message("Argument '-i' cannot be empty");
				break;
			}
		}
		else if (parser[i] == "-o" or parser[i + 1] == "-i" or parser[i + 1] == "-u")
		{
			if (parser[i + 1].empty())
			{
				help_message("Argument '-o' cannot be empty");
				break;
			}
		}
		else if (parser[i] == "-h")
		{
			break;
		}
		else
		{
			help_message("Wrong argument specified");
			break;
		}
	}
}

map<int,string> argParser(int argc, char **argv)
{
	map<int, string> parser;
	for (int i = 1; i < argc; i++)
	{
		parser[i] = argv[i];
	}
	help(parser, argc);
	exceptions(parser);
	
	return parser;
}

void assignArguments(string &layoutFile, string &valuesFile, string &outputFile, map<int, string> parser)
{
	for (int i=1; i < parser.size(); i++)
	{
		if (parser[i]=="-u")
		{
			layoutFile = parser[i + 1];
		}
		if (parser[i] == "-i")
		{
			valuesFile = parser[i + 1];
		}
		if (parser[i] == "-o")
		{
			outputFile = parser[i + 1];
		}
	}
}