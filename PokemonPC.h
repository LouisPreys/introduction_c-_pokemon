//
// Created by louis on 11/09/2024.
//

#ifndef EXERCICEPOKEMON_POKEMONPC_H
#define EXERCICEPOKEMON_POKEMONPC_H

#include "SetOfPokemon.h"

class PokemonPC : public SetOfPokemon{
protected :
public :
    PokemonPC();
    Pokemon *getOnePokemonByName(string name);
    Pokemon *getOnePokemonById(int id);
    PokemonPC(const Pokemon &anotherPokemon);
    void EncounterPokemon();
    void SearchPokemon(string name);
    void AddPokemonbyName(string name);
    void AddPokemonbyId(int id);
    void RemovePokemonByName(const std::string& name);
    void RemovePokemonById(int id);
    void AddPokemonback(Pokemon* pokemon);
};

#endif //EXERCICEPOKEMON_POKEMONPC_H
