/********************************************************************************
	Title: 	    PokedexDriver.cpp
	Authors:    Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  	    09/11/2024
	Purpose:    Contains full program flow, all classes used, all 
                    functions can be tested, takes user input & ends naturally
*********************************************************************************/

//Include
#include "dataClass.h"
#include "PokedexDriver.h"
#include "storageClass.h"
#include "otherClass.h"


//****************************************************************************
//                                 main()
//
// task:          Contains the user menu and calls onto the other functions 
//                based off of the user input.
//****************************************************************************
int main(){
//Variables
int userInput;
int pokeDelete;
Student studentInfo;
Info pokemonInfo;

//Make sure there is a file
    fstream pokedexCheck;

    pokedexCheck.open("pokedex.txt");

    if (!pokedexCheck){
        ofstream pokedexInfo("pokedex.txt");
    }
    pokedexCheck.close();

    //Introduce the User to the Program
    cout << "-------------------------------" << endl;
    cout << "Welcome to the TN Tech Pokedex!" << endl;
    cout << "-------------------------------" << endl;
//Do-while loop until User wishes to close
do{
    cout << "What would you like to do?" << endl;
    cout << "1. Display pokedex" << endl;
    cout << "2. Add to pokedex" << endl;
    cout << "3. Remove from pokedex" << endl;
    cout << "4. End program" << endl;
    cin >> userInput;
    
    if (userInput == 1){
        pokemonInfo.displayPokedex();
    }
    else if (userInput == 2){
        studentInfo.addToPokedex();
    }
    else if (userInput == 3){
        pokemonInfo.displayPokedex();
        cout << "Which entry would you like to delete? ";
        cin >> pokeDelete;
        studentInfo.deletePokemon(numIDs, pokeDelete);
    }
    else{
        cout << "Sorry, I don't recognize that input" << endl;
        break;
    }


}while (userInput != 4);
	return 0;
}
