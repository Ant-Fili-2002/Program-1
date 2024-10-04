/********************************************************************************
	Title: 	  otherClass.h
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Header file for otherClass.cpp 
*********************************************************************************/
#ifndef OTHERCLASS_H
#define OTHERCLASS_H

#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"

using namespace std;

class Info{
private:
	string favPokemon[maxPokemon];
    	string favStarter[maxPokemon];
public:
	friend class Student;
	friend class PokedexInfo;
	void displayPokedex();

#endif
