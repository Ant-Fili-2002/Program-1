/********************************************************************************
	Title: 	    PokedexDriver.cpp
	Authors:    Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	    09/11/2024
	Purpose:    Header file for PokedexDriver.cpp
*********************************************************************************/

#ifndef POKEDEXDRIVER_H
#define POKEDEXDRIVER_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include "dataClass.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;

//Number of entries is automatically 0 until told otherwise
int numIDs = 1;
//Number of max entries is just like the first gen number of pokemon
const int maxPokemon = 150;

//Function Prototypes:
void addToPokedex();
void displayPokedex();
void inputFromUser();
void deletePokemon(int numPokemon, int pokemonChoice);
void pokedexCount();
//Main
int main();

#endif
