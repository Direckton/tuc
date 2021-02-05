

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include "fileOpener.h"
#include "listLoader.h"

using namespace std;

int main()
{
	
	int gateNumber = gate_counter("layout.txt");
	string content = read_file_content("layout.txt");
//	assign_elements(content,gateNumber);

	string lul = "134";

	int data = stoi(lul);




	cout << data;
	return 0;
}