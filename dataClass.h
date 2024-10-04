/********************************************************************************
	Title: 	  dataClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for dataClass.cpp 
*********************************************************************************/
#ifndef DATACLASS_H
#define DATACLASS_H

#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;

class Student{
    Info pokeInfo;
private:
	string studentName[maxPokemon];
public:
	friend class PokedexInfo;
	void addToPokedex();
	void deletePokemon(int, int);
	


#endif
