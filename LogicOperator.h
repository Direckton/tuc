#include <list>
#include <string>
#include "listLoader.h"

#pragma once

using namespace std;


void calculate_outputs(list<Schematics>& temp, int in_knot1, int in_knot2);

bool gate(bool state1, bool state2, string gate);

bool find_value(list<Schematics> temp, int input_knot);