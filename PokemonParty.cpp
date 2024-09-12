//
// Created by louis on 12/09/2024.
//

#include "PokemonParty.h"
#include <iostream>

PokemonParty::PokemonParty(const std::vector <std::string> & names, PokemonPC* pokeball) : linkedPokeball(pokeball) {
    for (const std::string& name : names) {
        if (battlePokemon.size() >= MAX_SIZE) {
            std::cout << "L'equipe est complete" << std::endl;
            break;
        }
        Pokemon* pokemon = linkedPokeball -> getOnePokemonByName(name);
        if (pokemon != nullptr) {
            battlePokemon.push_back(pokemon);
        }
        else {
            std::cout << "Impossible de trouver le Pokemon : " << name << std::endl;
        }
    }
}

PokemonParty::PokemonParty(const std::vector <int> & ids, PokemonPC* pokeball) : linkedPokeball(pokeball) {
    for (int id : ids) {
        if (battlePokemon.size() >= MAX_SIZE) {
            std::cout << "L'equipe est complete" << std::endl;
            break;
        }
        Pokemon* pokemon = linkedPokeball -> getOnePokemonById(id);
        if (pokemon != nullptr) {
            battlePokemon.push_back(pokemon);
       }
        else {
            std::cout << "Impossible de trouver l'id : " << id << std::endl;
        }
    }
}

/*void PokemonParty::RemovePokemonFromPartybyName(string name, int i){
    Pokemon* onepokemon = battlePokemon.at(i);
    linkedPokeball -> AddPokemonback(onepokemon);
    std::cout << "Au revoir " << onepokemon -> getName() << std::endl;
}*/

void PokemonParty::disband() {
    std::cout << "********* Retour dans le PC **********" << std::endl;
    for (Pokemon* p : battlePokemon) {
        linkedPokeball -> AddPokemonback(p);
        std::cout << p ->getName() << " est dans le PC" << std::endl;
    }
    battlePokemon.clear();
}

PokemonParty::~PokemonParty(){
}

void PokemonParty::displayParty() const {
    std::cout << "********* Equipe Pokemon *********" << std::endl;
    for (Pokemon *pokes : battlePokemon) {
        pokes -> displayInfo();
    }
}

Pokemon *PokemonParty::getOnePokemonByName(string name) {
    int IndexInList = this -> FindByName(name);
    if (IndexInList!=-1) {
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokemon *PokemonParty::getOnePokemonById(int id) {
    if (id>0 && id<=721) {
        Pokemon *pokemon = nullptr;
        int IndexInList = this->FindById(id);
        if (IndexInList != -1) {
            Pokemon *pokemon = arrayOfPokemon.at(IndexInList);
            arrayOfPokemon.erase(arrayOfPokemon.begin() + IndexInList);
            return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
        }

    }
    return nullptr;
}