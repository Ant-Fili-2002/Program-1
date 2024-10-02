/********************************************************************************
	Title: 	  storageClass.cpp
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Pointer to an array of pointers to the data in the data class. 
*********************************************************************************/

#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

#define numPointers 4

using namespace std;

string *array_name[pokeMax];
string *array_poke[pokeMax];
string *array_starter[pokeMax];
string* (*array_name)[pokeMax] = &array_name;
string* (*pArray_poke)[pokeMax] = &array_poke;
string* (*pArray_starter)[pokeMax] = &array_starter;
