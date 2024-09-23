/********************************************************************************
	Title: 	  dataClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for dataClass.cpp 
*********************************************************************************/
#ifndef DATACLASS_H
#define DATACLASS_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include "PokedexDriver.h"

using namespace std;

void addToPokedex();
int main();

class Data
{
	private: 
		string studentName;
		string favPokemon;
		string favStarter;
	public:
		void addToPokedex();
		void inputFromUser();
		void displayPokedex();
		void pokedexCount();
}

#endif
