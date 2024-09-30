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


//Function for adding to the Pokedex
void addToPokedex(){
    //Create array for Class
    
    //Find out the information of the student
    cout << "Name of student: ";
    cin >> pokeInfo.studentName[numIDs];
    cout << "Name of Favorite Pokemon: ";
    cin >> pokeInfo.favPokemon[numIDs];
    cout << "Name of Favorite Starter Pokemon: ";
    cin >> pokeInfo.favStarter[numIDs];
    cout << endl;

    //Record it to Files
    fstream pokedexInfo;
    pokedexInfo.open("pokedex.txt", std::ios_base::app);


    //Output the info
    pokedexInfo << "ID Number: " << numIDs << endl;
    pokedexInfo << "Student Name: " << pokeInfo.studentName[numIDs] << endl;
    pokedexInfo << "Favorite Pokemon: " << pokeInfo.favPokemon[numIDs] << endl;
    pokedexInfo << "Favorite Starter: " << pokeInfo.favStarter[numIDs] << endl;

    pokedexInfo.close();

    numIDs++;
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
    numIDS--;

    for (int q = 1; q < numPokemon - 1; q++){
    pokeDelete << "ID Number: " << q << endl;
    pokeDelete << "Student Name: " << pokeInfo.studentName[q] << endl;
    pokeDelete << "Favorite Pokemon: " << pokeInfo.favPokemon[q] << endl;
    pokeDelete << "Favorite Starter: " << pokeInfo.favStarter[q] << endl;
    }
    pokeDelete.close();

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
    cin.ignore();

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
        int pokeDelete;
        displayPokedex();
        cout << "Which pokemon entry would you like to delete?" << endl;
        cin >> pokeDelete;
        deletePokemon(numIDs, pokeDelete);
        
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
    //Count number of lines
    pokedexCount();
    
    //Main Function
    inputFromUser();
    


    return 0;
}