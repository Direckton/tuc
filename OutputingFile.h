#pragma once

#include <fstream>
#include  <string>

using namespace std;

string create_input(string input);

void create_output(string &output, string content, string output_values);

void save_output_to_file(string filestream, string str);