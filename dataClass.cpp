/*************************************************************************
	Title: 	 dataClass.cpp
	Authors: Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	 09/11/2024
	Purpose: Stores the information of students, their favorite 
 	         Pokemon and favorite starter Pokemon.
*************************************************************************/

#include "dataClass.h"
#include "storageClass.h"
#include "pokedexDriver.h"

int addToPokedex(int)
{
    PokemonInfo pokeInfo;
    cout << "A Wild Tech Student Appeared!";
    cout << "\nQUICK! Add Them to Your Pokedex!";
	
//Find out the information of the student
    cout << "\nName of Student: ";
    	cin >> pokeInfo.studentName;
    cout << "\nName of Favorite Pokemon: ";
    	cin >> pokeInfo.favPokemon;
    cout << "\nName of Favorite Starter Pokemon: ";
    	cin >> pokeInfo.favStarter;
    cout << endl;

//Record it to Files
    fstream pokedexInfo;
    pokedexInfo.open("pokedex.txt",ios::app);

    int IDArray[numIDs];
    numIDs++;
    return numIDs;
}
