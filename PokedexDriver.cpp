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


int numIDS = 0;
PokemonInfo pokeInfo;


//Count how many entries there are on Pokedex
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


}

//Function for Displaying the Pokedex
void displayPokedex(){
    ifstream displayText("pokedex.txt");
    int length;

    if (filesystem::file_size("pokedex.txt") == 0){
        cout << "NO ENTRIES FOUND" << endl;
        cout << endl;
        displayText.close();
    }
    else {
        cout << endl;
        cout << displayText.rdbuf();
        cout << endl;
    }

}
//****************************************************************************
//                                 main()
//
// task:          Contains the user menu and calls onto the other functions 
//                based off of the user input.
//****************************************************************************
int main()
{
    int endProgram = 0;
	
    //Make sure the pokedex file exists
    fstream pokeDexFile;
    pokeDexFile.open("pokedex.txt");
    
    //Create it if it doesn't exist
    if (!pokeDexFile)
    {
	ofstream pokedexInfo("pokedex.txt");
    };
	
    /*Main Menu Options*/
    cout << "Hello! And welcome to the TN Tech PokeDex!" << endl;
    cout << "------------------------------------------" << endl;
    do{
    cout << "Welcome To The World of Pokemon! What Would You Like to Do?";
    cout << "1. Display PokeDex" << endl;
    cout << "2. Add to PokeDex" << endl;
    cout << "3. Remove from PokeDex" << endl;
    cout << "4. Exit" << endl;
    	cin >> userInput;

    switch(userInput)
	/*Displays Pokedex*/
	case 1:
	    displayPokedex();
	    break;
	/*Adds New Student to Pokedex*/
	case 2:
	    addToPokedex();
	    break;
	/*deletes Pokedex*/
	case 3:
	    int pokeDelete;
            displayPokedex();
            cout << "Which pokemon entry would you like to delete?" << endl;
        	cin >> pokeDelete;
            deletePokemon(numIDs, pokeDelete);
	    break;
	/*Ends Program*/
	case 4:
	    endProgram = 1;
	    break;
    }while (endProgram != 1);

    cout << "See Ya Next Time!" << endl;
    cout << endl;
    /*Program 1 Complete :)*/
    return 0;
}
