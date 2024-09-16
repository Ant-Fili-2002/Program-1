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

using namespace std;

//Function for adding to the Pokedex
void addToPokedex(){
    PokemonInfo pokeInfo;
    //Find out the information of the student
    cout << "Name of student: ";
    cin >> pokeInfo.studentName;
    cout << "Name of Favorite Pokemon: ";
    cin >> pokeInfo.favPokemon;
    cout << "Name of Favorite Starter Pokemon: ";
    cin >> pokeInfo.favStarter;
    cout << endl;

    //Record it to Files
    fstream pokedexInfo;
    pokedexInfo.open("pokedex.txt",ios::app);


    //Output the info
    pokedexInfo << "ID Number: " << numIDs << endl;
    pokedexInfo << "Student Name: " << pokeInfo.studentName << endl;
    pokedexInfo << "Favorite Pokemon: " << pokeInfo.favPokemon << endl;
    pokedexInfo << "Favorite Starter: " << pokeInfo.favStarter << endl;

    int IDArray[numIDs];
    numIDs++;
    return numIDs;
}

//Function for Displaying the Pokedex
void displayPokedex(){
    ifstream displayText("pokedex.txt");

    if (displayText.is_open()){
        cout << endl;
        cout << displayText.rdbuf();
        cout << endl;
    }

}


void inputFromUser(){
    int userInput;

    //Loop
    do{
    cout << "What would you like to do?" << endl;
    cout << "1. Display PokeDex" << endl;
    cout << "2. Add to PokeDex" << endl;
    cout << "3. Remove from PokeDex" << endl;
    cout << "4. Exit" << endl;
    cin >> userInput;

    //if user wishes to display the PokeDex
    if (userInput == 1){
       displayPokedex();
    }
    //if user wihses to add to the PokeDex
    else if (userInput == 2) {
        addToPokedex();
    }
    //if user wishes to remove from PokeDex
    else if (userInput == 3){
        
    }
    else if (userInput == 4){
    }
    else {
        cout << "Sorry, that isn't an option" << endl;
    }
    }while (userInput != 4);

    cout << "Goodbye!" << endl;
    cout << endl;

}


int main(){
    

    //Make sure the pokedex file exists
    fstream pokeDexFile;

    pokeDexFile.open("pokedex.txt");
    //Create it if it doesn't exist
    if (!pokeDexFile){
    ofstream pokedexInfo("pokedex.txt");
    };
    //Greet the user
    cout << "Hello! And welcome to the TN Tech PokeDex!" << endl;
    cout << "------------------------------------------" << endl;
    
    //Main Function
    inputFromUser();


    return 0;
}
