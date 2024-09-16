/**************************************************************************
	Title: 		PokedexDriver.cpp
	Authors:  	Anthony Filigenzi, Jocelyn Lee, Kylie Truong & Adam Yang
	Date:  		09/11/2024
	Purpose:    Contains full program flow, all classes used, all 
                functions can be tested, takes user input & ends naturally
**************************************************************************/



//Include
#include <fstream>
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>
using namespace std;

void storeInfo(){
    //Find out the information of the student
    string studName;
    string favPokemon;
    string favStarter;
    cout << "Name of student: ";
    cin >> studName;
    cout << "Name of Favorite Pokemon: ";
    cin >> favPokemon;
    cout << "Name of Favorite Starter Pokemon: ";
    cin >> favStarter;

    //Record it to Files
    fstream pokedexInfo;
    pokedexInfo.open("pokedex.txt");

    //Create the file if it doesn't exist
    if (!pokedexInfo){
    ofstream pokedexInfo("pokedex.txt");
    };


    //Output the info
    pokedexInfo << studName << " " << favPokemon << " " << favStarter << endl;

    pokedexInfo.close();


}


int main(){

    storeInfo();


    return 0;
}
