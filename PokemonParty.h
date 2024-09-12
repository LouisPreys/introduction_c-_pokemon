//
// Created by louis on 12/09/2024.
//

#ifndef EXERCICEPOKEMON_POKEMONPARTY_H
#define EXERCICEPOKEMON_POKEMONPARTY_H

#include "SetOfPokemon.h"
#include "PokemonPC.h"

class PokemonParty : public SetOfPokemon{
private :
    static const int MAX_SIZE = 6;
    std::vector <Pokemon *> battlePokemon;
    PokemonPC* linkedPokeball;
public :
    PokemonParty(const std::vector <std::string> & names, PokemonPC* pokeball);
    PokemonParty(const std::vector <int> & ids, PokemonPC* pokeball);
    void displayParty() const;
    Pokemon* getOnePokemonByName(string name);
    Pokemon* getOnePokemonById(int id);
    void disband();
    ~PokemonParty();

    void RemovePokemonFromPartybyName(string name, int i);
};

#endif //EXERCICEPOKEMON_POKEMONPARTY_H
