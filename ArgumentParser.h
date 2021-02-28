#pragma once

#include <map>
#include <iostream>
#include <string>

using namespace std;

map<int, string> argParser(int argc, char **argv);

void assignArguments(string& layoutFile, string& valuesFile, string& outputFile, map<int, string> parser);

void exceptions(map<int, string> parser);