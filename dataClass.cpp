/*************************************************************************
	Title: 	 dataClass.cpp
	Authors: Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	 09/11/2024
	Purpose: Stores the information of students, their favorite 
 	         Pokemon and favorite starter Pokemon.
*************************************************************************/

#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"

//****************************************************************************
//                                 addToPokedex()
//
// task:          Collects the information of a Tech Student: name, favorite
//		  pokemon & favorite starter pokemon.
//
//****************************************************************************
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
};


//*****************************************************************************
//                                 deletePokemon(int, int)
//
// task:          Allows the user to delete the information of a Tech Student.
//
//*****************************************************************************
void deletePokemon(int numPokemon, int pokemonChoice){
fstream pokeDelete;
pokeDelete.open("pokedex.txt", std::ios::out);

//If it's the highest number
    if (numPokemon == pokemonChoice){
        string lineRandom;
        //Loop until you find the right line
        for (int j = 0; j < (numPokemon*4)-4; j++){
            getline(pokeDelete, lineRandom);
        }
        pokeDelete << "";
        pokeDelete << "";
        pokeDelete << "";
        pokeInfo.studentName[numPokemon] = "";
        pokeInfo.favPokemon[numPokemon] = "";
        pokeInfo.favStarter[numPokemon] = "";

    }
    else if (numPokemon > pokemonChoice){
    for (int i = pokemonChoice; i < numPokemon; ++i){
    pokeInfo.studentName[i] = pokeInfo.studentName[i + 1];
    pokeInfo.favPokemon[i] = pokeInfo.favPokemon[i + 1];
    pokeInfo.favStarter[i] = pokeInfo.favStarter[i + 1];
    }
    }
    numIDs--;

    for (int q = 1; q < numPokemon - 1; q++){
    pokeDelete << "ID Number: " << q << endl;
    pokeDelete << "Student Name: " << pokeInfo.studentName[q] << endl;
    pokeDelete << "Favorite Pokemon: " << pokeInfo.favPokemon[q] << endl;
    pokeDelete << "Favorite Starter: " << pokeInfo.favStarter[q] << endl;
    }
    pokeDelete.close();

};
