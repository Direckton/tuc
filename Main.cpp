/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
#include <iostream>
#include <string>
#include "ArgumentParser.h"
#include "FunctionHandler.h"

using namespace std;
int main(int argc, char **argv)
{
	map<int, string> parser = argParser(argc, argv);

	string layoutFile;
	string valuesFile;
	string outputFile;

	assignArguments(layoutFile, valuesFile, outputFile, parser);
	
	cout << "Starting..." << endl;
	try
	{
		run_program(layoutFile, valuesFile, outputFile);
	}
	catch (const string errorMessage)
	{
		cerr << "ERROR MESSAGE: " << errorMessage << endl;
		return -1;
	}
	return 0;
} 