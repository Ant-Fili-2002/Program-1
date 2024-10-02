/********************************************************************************
	Title: 	  otherClass.cpp
	Authors:  Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	  09/11/2024
	Purpose:  Median for PokedexDriver.cpp and storage 
*********************************************************************************/
#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

using namespace std;

//****************************************************************************
//                                 pokedexCount()
//
// task:          Counts how many entries there are in the Pokedex
//
//****************************************************************************

void pokedexCount(){
    string line;
    int lineTotal = 0;
    int lineRead = 0;
    string s;
    int studentInfo = 0;


    fstream pokedexCount;
    pokedexCount.open("pokedex.txt");
    while(!pokedexCount.eof()){
    getline(pokedexCount, line);
    getline(pokedexCount, pokeInfo.studentName[studentInfo]);
    getline(pokedexCount, pokeInfo.favPokemon[studentInfo]);
    getline(pokedexCount, pokeInfo.favStarter[studentInfo]);
    lineTotal ++;
    studentInfo ++;
    }

    numIDs = lineTotal;



    pokedexCount.close();


};
