//
// Created by louis on 11/09/2024.
//

#include "PokemonPC.h"
#include "Pokedex.h"
#include "SetOfPokemon.h"
#include <iostream>

void PokemonPC::EncounterPokemon(){
    int value = rand()%800;
    Pokemon* encounter = Pokedex::getInstance()->getOnePokemonById(value);
    if (encounter != nullptr) {
        std::cout << "Vous avez capture " << encounter->getName() << " !" << std::endl;
        this->arrayOfPokemon.push_back(encounter);
        encounter->displayInfo();
    }
    else {
        std::cout << "Vous ne trouvez rien" << std::endl;
    }
}

void PokemonPC::SearchPokemon(string name) {
    Pokemon *search = Pokedex::getInstance()->getOnePokemonByName(name);
    std::cout << "Vous avez capture " << search -> getName() << " !" << std::endl;
    this->arrayOfPokemon.push_back(search);
    search -> displayInfo();
}

Pokemon* PokemonPC::getOnePokemonByName(string name) {
    int IndexInList = this -> FindByName(name);
    if (IndexInList!=-1) {
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokemon* PokemonPC::getOnePokemonById(int id) {
    int IndexInList = this -> FindById(id);
    if (IndexInList!=-1){
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

void PokemonPC::AddPokemonback(Pokemon *pokemon) {
    arrayOfPokemon.push_back(pokemon);
    std::cout << pokemon -> getName() << " est retourne dans le PC" << std::endl;
}

PokemonPC::PokemonPC() {

}

/*void PokemonPC::AddPokemonbyName(string name){
    Pokemon* pokemon = Pokedex::getInstance()->getOnePokemonByName(name);
    if (pokemon != nullptr){
        arrayOfPokemon.push_back(pokemon);
        std::cout << "Vous avez capture " << name << std::endl;
    }
    else {
        std::cout << name << " s'est enfui !" << std::endl;
    }
}

void PokemonPC::AddPokemonbyId(int id){
    Pokemon* pokemon = Pokedex::getInstance()->getOnePokemonById(id);
    if (pokemon != nullptr){
        arrayOfPokemon.push_back(pokemon);
        std::cout << "Vous avez capture le Pokemon # " << id << std::endl;
    }
    else {
        std::cout << "Le Pokemon # " << id << " s'est enfui !" << std::endl;
    }
}

void PokemonPC::RemovePokemonByName(const std::string &name) {
    for (auto it = arrayOfPokemon.begin(); it != arrayOfPokemon.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            arrayOfPokemon.erase(it);
            std::cout << "Removed pokemon " << name << " from pokeball" << std::endl;
        }
    }
}

void PokemonPC::RemovePokemonById(int id) {
    for (auto it = arrayOfPokemon.begin(); it != arrayOfPokemon.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            arrayOfPokemon.erase(it);
            std::cout << "Removed pokemon with ID " << id << " from pokeball" << std::endl;
        }
    }
}*/


