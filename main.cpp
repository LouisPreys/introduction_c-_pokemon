#include <iostream>
#include "Pokemon.h"
#include "Pokedex.h"
#include "SetOfPokemon.h"
#include "PokemonPC.h"
#include "PokemonParty.h"

int main() {
    srand (time(NULL));
    std::cout << "Pokemon test" << std::endl;

    //Pokemon Mewtwo(150,"Mewtwo",1000,100,100,150,130,140,1);
    //Pokemon p2(Mewtwo);
    //Pokemon Simiabraz(392,"Simiabraz",350,120,80,120, 80, 130,4);
    //Pokemon Cotovol(210, "Cotovol", 100, 20, 30, 10, 20, 40, 2);
    //Pokemon Levaurien(680, "Levaurien", 1000, 120, 60, 100, 80, 200, 8);
    //Mewtwo.Pokemonbattle(Cotovol);
    //Levaurien.Pokemonbattle(Cotovol);

    std::cout << "Nombre de Pokemon en memoire : " << Pokemon::getNumberofPokemon() << std::endl;

    Pokedex* pokedex = Pokedex::getInstance();

    std::cout << "Nombre de Pokemon en memoire : " << Pokemon::getNumberofPokemon() << std::endl;

    PokemonPC* pokeball= new PokemonPC();
    pokeball -> EncounterPokemon();
    //pokeball -> displayList();

    Pokemon* pokename = pokedex->getOnePokemonByName("Graveler");
    if (pokename != nullptr) {
        std::cout << "Vous avez trouve : " << pokename->getName() << std::endl;
    }
    else {
        std::cout << "Ce Pokemon n'existe pas." << std::endl;
    }

    Pokemon* pokeid = pokedex -> getOnePokemonById(442);
    if (pokeid != nullptr) {
        std::cout << "Vous avez trouve : " << pokeid->getName() << std::endl;
    } else {
        std::cout << "Ce Pokemon n'existe pas." << std::endl;
    }

    pokeball -> EncounterPokemon();

    pokeball -> SearchPokemon("Torterra");
    pokeball -> SearchPokemon("Infernape");
    pokeball -> SearchPokemon("Empoleon");
    pokeball -> SearchPokemon("Staraptor");
    pokeball -> SearchPokemon("Weavile");
    pokeball -> SearchPokemon("Garchomp");
    pokeball -> SearchPokemon("Magnezone");

    std::vector<string> names = {"Torterra","Infernape","Empoleon","Staraptor","Weavile","Garchomp","Magnezone"};
    PokemonParty myparty(names ,pokeball);


    myparty.displayParty();
    myparty.disband();
    myparty.displayParty();

    /*myParty.displayList();
    pokeball.displayList();
    myParty.disband();*/

    return 0;
}
