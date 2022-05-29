#include "card.h"

Card::Card(std::string name, int attack, int defense) : name(name), attack(attack), defense(defense) {}

double Card::power(Card opponentCard) {
    return (this->attack - opponentCard.defense / 2) >= 0 ? this->attack - opponentCard.defense / 2 : 0;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.name << " " << card.attack << " " << card.defense;
    return os;
}

void Card::effect(Card &opponentCard, Player &player, Player &opponent) {
//    std::cout<<"The effect of Card"<<std::endl;
}