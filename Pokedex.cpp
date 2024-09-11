///////////////////////////////////
//Anthony Filigenzi
//Kylie Truong
//

//9/11/2024




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
    cout << "Name of student: ";
    cin >> string studName;
    cout << "Name of Favorite Pokemon: ";
    cin >> string favPokemon;
    cout << "Name of Favorite Starter Pokemon: ";
    cin >> string favStarter;

    //Record it to Files
    ifsteam pokedexIn;
    ofstream pokedexOut;
    pokedexFile.open("pokedex.txt");
    
    //Create file if it doesn't already exist
    if (!pokedexFile){
    pokedexOut("pokedex.txt");
    }

    pokedexOut << studName << " " << favPokemon << " " << favStarter << endl;

    


}


int main(){

    storeInfo();


    return 0;
}