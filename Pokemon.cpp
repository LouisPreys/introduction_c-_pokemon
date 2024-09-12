//
// Created by louis on 09/09/2024.
//

#include "Pokemon.h"
#include <iostream>

int Pokemon::numberofPokemon = 0;
//using namespace Pokemon;

    Pokemon::Pokemon(int id, const string &name, double hitPoint, double attack, double defense,
                     double spattack, double spdefense, double speed, int generation) :
                     id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense),
                     spattack(spattack), spdefense(spdefense), speed(speed), generation(generation) {
        //std::cout << "Ici le constructeur" << std::endl;
        //std::cout << "Id : " << id << std::endl;
        //std::cout << "Nom : " << name << std::endl;
        //std::cout << "HitPoint : " << hitPoint << std::endl;
        //std::cout << "Attack : " << attack << std::endl;
        //std::cout << "Defense : " << defense << std::endl;
        //std::cout << "SpAttack : " << spattack << std::endl;
        //std::cout << "SpDefense : " << spdefense << std::endl;
        //std::cout << "Speed : " << speed << std::endl;
        //std::cout << "Generation : " << generation << std::endl;

        numberofPokemon ++;
    }

    Pokemon::Pokemon(const Pokemon &anotherPokemon) : id(anotherPokemon.id), name(anotherPokemon.name),
                                                      hitPoint(anotherPokemon.hitPoint), attack(anotherPokemon.attack),
                                                      defense(anotherPokemon.defense), spattack(anotherPokemon.spattack),
                                                      spdefense(anotherPokemon.spdefense), speed(anotherPokemon.speed),
                                                      generation(anotherPokemon.generation) {
        //std::cout << "Recopie" << std::endl;

        numberofPokemon ++;
    }

    Pokemon::~Pokemon() {
        std::cout << "Ici le destructeur" << std::endl;

        numberofPokemon --;
    }

void Pokemon::displayInfo(){
    std::cout << "Pokemon #" << id << " : " << name << ", hitPoint : " << hitPoint <<
    ", Attack : " << attack << ", Defense : " << defense << ", SpAttack : " << spattack <<
    ", SpDefense : " << spdefense << ", Speed : " << speed << ", Generation : " << generation << std::endl;
    }

int Pokemon::getId() const {
    return id;
}

const string &Pokemon::getName() const {
    return name;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getGeneration() const {
    return generation;
}

void Pokemon::Pokemonbattle(Pokemon & anotherPokemon){
    while (hitPoint and anotherPokemon.hitPoint >0) {
        if (this -> speed >= anotherPokemon.speed) {
            if (this -> attack >= this -> spattack){
                if (this->attack >= anotherPokemon.defense) {
                    anotherPokemon.hitPoint = anotherPokemon.hitPoint - abs(attack - anotherPokemon.defense);
                    std::cout << "PV de " << anotherPokemon.name << " : " << anotherPokemon.hitPoint << std::endl;
                }
            }
                else {
                    if (rand() % 10 >= 5) {
                    anotherPokemon.hitPoint = anotherPokemon.hitPoint - abs(anotherPokemon.defense - attack );
                    std::cout << "PV de " << anotherPokemon.name << " : " << anotherPokemon.hitPoint << std::endl;
                    }
                else {
                    std::cout << name << "'s attack missed !" << std::endl;
                }
            }
            if (anotherPokemon.attack > this->defense) {
                hitPoint = hitPoint - abs(anotherPokemon.attack - defense);
                std::cout << "PV de " << name << " : " << hitPoint << std::endl;
            }
            else {
                if (rand() % 10 >= 5){
                    hitPoint = hitPoint - abs(defense - anotherPokemon.attack);
                    std::cout << "PV de " << name << " : " << hitPoint << std::endl;
                }
                else {
                    std::cout << anotherPokemon.name << "'s attack missed !" << std::endl;
                }
            }
        }
        else {
            if (anotherPokemon.attack > this->defense) {
                hitPoint = hitPoint - abs(anotherPokemon.attack - defense);
                std::cout << "PV de " << name << " : " << hitPoint << std::endl;
            }
            else {
                if (rand() % 10 >= 5) {
                    hitPoint = hitPoint - abs(defense - anotherPokemon.attack);
                    std::cout << "PV de " << name << " : " << hitPoint << std::endl;
                } else {
                    std::cout << anotherPokemon.name << "'s attack missed !" << std::endl;
                }
                if (this->attack >= anotherPokemon.defense) {
                    anotherPokemon.hitPoint = anotherPokemon.hitPoint - abs(attack - anotherPokemon.defense);
                    std::cout << "PV de " << anotherPokemon.name << " : " << anotherPokemon.hitPoint << std::endl;
                }
                else {
                    if (rand() % 10 >= 5) {
                        anotherPokemon.hitPoint = anotherPokemon.hitPoint - abs(anotherPokemon.defense - attack);
                        std::cout << "PV de " << anotherPokemon.name << " : " << anotherPokemon.hitPoint << std::endl;
                    }
                    else {
                        std::cout << name << "'s attack missed !" << std::endl;
                    }
                }
            }
        }
    }
    if (anotherPokemon.hitPoint <= 0) {
        std::cout << "You won !" << std::endl;
    }
    else {
        std::cout << "Try again !" << std::endl;
    }
}

int Pokemon::getNumberofPokemon() {
    return numberofPokemon;
}

double Pokemon::getSpeed() const {
    return speed;
}

double Pokemon::getSpattack() const {
    return spattack;
}

double Pokemon::getSpdefense() const {
    return spdefense;
}
