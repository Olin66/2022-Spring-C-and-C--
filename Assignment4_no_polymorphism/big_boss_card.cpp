#include "player.h"
#include "big_boss_card.h"

BigBossCard::BigBossCard(std::string name, int attack, int defense): Card(name, attack, defense) {}

void BigBossCard::effect(Card& opponentCard, Player& player, Player& opponent){
    for (auto & i : player.deck)
    {
        i.attack += opponentCard.attack;
        i.defense += opponentCard.defense;
    }
    for (auto it = opponent.deck.begin();it != opponent.deck.end();)
    {
        if ((*it).attack == opponentCard.attack || (*it).defense == opponentCard.defense)
            it = opponent.deck.erase(it);
        else 
            ++it;
    }
    // std::cout<<"The effect of BigBossCard"<<std::endl;
}