#pragma once

#include <fstream>
#include  <string>

using namespace std;

string create_input(string input);

void create_output(string &output, string content, bool state);

void save_output_to_file(string filestream, string str);