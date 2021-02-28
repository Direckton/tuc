/** @file */

/*
 Basically_tuc

 Projekt ppk
 */
 //Plik nag��wkowy funkcji FunctionHandler.cpp
#pragma once

#include <iostream>
#include <string>
#include <list>
#include "FileOpener.h"
#include "ListLoader.h"
#include "LogicOperator.h"
#include "OutputingFile.h"
#include "ArgumentParser.h"

/**Funkcja zarz�dza wykonywaniem si� programu
 @param layoutFile plik zawieraj�cy konfiguracj� uk�adu
 @param valuesFile plik zawieraj�cy konfiguracj� stan�w wej�� uk�adu
 @param layoutFile plik do kt�rego zostanie zapisane rozwi�zanie
 */
void run_program(const string& layoutFile, const string& valuesFile, const string& outputFile);