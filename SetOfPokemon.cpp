//
// Created by louis on 09/09/2024.
//

#include "SetOfPokemon.h"
#include <iostream>
#include <fstream>

void SetOfPokemon::displayList() {
    std::cout << "******* Attrapez-les tous ! *******" << std::endl;
    for(Pokemon * pokemon : arrayOfPokemon){
        pokemon -> displayInfo();
    }
}

int SetOfPokemon::FindByName(string name){
    for (int i=0; i < arrayOfPokemon.size(); i++){
        if (name == arrayOfPokemon.at(i)->getName()){
            return i;
        }

    }
    return 0;
}

int SetOfPokemon::FindById(int id){
    if (id > 721){
        std::cerr << "Numéro de Pokedex introuvable" << std::endl;
        return -1;
    }
    for (size_t i=0; i < arrayOfPokemon.size(); i++){
        if (id == arrayOfPokemon.at(i)-> getId()){
            return static_cast <int> (i);
        }
    }
    return 0;
}

SetOfPokemon::SetOfPokemon(){
}