#include "player.h"
#include "exchange_card.h"

ExchangeCard::ExchangeCard(std::string name, int attack, int defense): Card(name, attack, defense) {}

void ExchangeCard::effect(Card& opponentCard, Player& player, Player& opponent){
    int temp = opponentCard.attack;
    opponentCard.attack = opponentCard.defense;
    opponentCard.defense = temp;
    // std::cout<<"The effect of ExchangeCard"<<std::endl;
}