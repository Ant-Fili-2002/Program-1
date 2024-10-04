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
void addToPokedex(){
        cout << "A Wild Tech Student Appeared!";
        cout << "\nQUICK! Add Them to Your Pokedex!" << endl;
        cout << "Name of Student: ";
        cin.ignore();
        getline(cin, studentName[numIDs]);
        cout << "Name of Favorite Pokemon: ";
        getline(cin, pokeInfo.favPokemon[numIDs]);
        cout << "Name of Favorite Starter: ";
        getline(cin, pokeInfo.favStarter[numIDs]);
        cout << endl;

    //Record it to file
    fstream pokedexAdd;
    pokedexAdd.open("pokedex.txt", ios::app);
    pokedexAdd << "ID Number: " << numIDs << endl;
    pokedexAdd << "Student Name: " << studentName[numIDs] << endl;
    pokedexAdd << "Favorite Pokemon: " << pokeInfo.favPokemon[numIDs] << endl;
    pokedexAdd << "Favorite Starter: " << pokeInfo.favStarter[numIDs] << endl;
    numIDs++;
    pokedexAdd.close();
};


//*****************************************************************************
//                                 deletePokemon(int, int)
//
// task:          Allows the user to delete the information of a Tech Student.
//
//*****************************************************************************
void deletePokemon(int numPokemon, int choicePokemon){
   fstream pokeDelete;
pokeDelete.open("pokedex.txt", std::ios::out);

//If it's the highest number
    if (numPokemon == choicePokemon){
        string lineRandom;
        //Loop until you find the right line
        for (int j = 0; j < (numPokemon*4)-4; j++){
            getline(pokeDelete, lineRandom);
        }
        pokeDelete << "";
        pokeDelete << "";
        pokeDelete << "";
        studentName[numPokemon] = "";
        pokeInfo.favPokemon[numPokemon] = "";
        pokeInfo.favStarter[numPokemon] = "";

    }
    else if (numPokemon > choicePokemon){
	    for (int i = choicePokemon; i < numPokemon; ++i){
	    studentName[i] = studentName[i + 1];
	    pokeInfo.favPokemon[i] = pokeInfo.favPokemon[i + 1];
	    pokeInfo.favStarter[i] = pokeInfo.favStarter[i + 1];
	    }
    }
    numIDs--;

    for (int q = 1; q < numPokemon - 1; q++){
    pokeDelete << "ID Number: " << q << endl;
    pokeDelete << "Student Name: " << studentName[q] << endl;
    pokeDelete << "Favorite Pokemon: " << pokeInfo.favPokemon[q] << endl;
    pokeDelete << "Favorite Starter: " << pokeInfo.favStarter[q] << endl;
    }
    pokeDelete.close();
};
