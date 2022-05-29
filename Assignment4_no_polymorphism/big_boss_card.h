#pragma once

#include "card.h"

class BigBossCard: public Card
{

public:
    BigBossCard(std::string name, int attack, int defense);

    void effect(Card& opponentCard, Player& player, Player& opponent);
};
