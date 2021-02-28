/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag³ówkowy funkcji FunctionHandler.cpp
#pragma once

#include <iostream>
#include <string>
#include <list>
#include "FileOpener.h"
#include "ListLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"
#include "ArgumentParser.h"

/**Funkcja zarz¹dza wykonywaniem siê programu
 @param layoutFile plik zawieraj¹cy konfiguracjê uk³adu
 @param valuesFile plik zawieraj¹cy konfiguracjê stanów wejœæ uk³adu
 @param layoutFile plik do którego zostanie zapisane rozwi¹zanie
 */
void run_program(const string& layoutFile, const string& valuesFile, const string& outputFile);