#pragma once

#include <iostream>
#include <string>
#include <list>
#include "FileOpener.h"
#include "ListLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"
#include "ArgumentParser.h"

void run_program(const string& layoutFile, const string& valuesFile, const string& outputFile);