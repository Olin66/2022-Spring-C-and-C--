#include <string>
#include "card.h"
#include "player.h"

Player::Player(std::vector<Card> &deck, std::string name) : deck(deck), name(name) {
    for (int i = 0; i < 5; i++)
        draw();
}

void Player::draw() {
    if (deck.empty()) return;
    Card &c = deck.back();
    deck.pop_back();
    hand.push_back(c);
}

Card Player::play(int index) {
    Card &c = hand[index];
    hand.erase(hand.begin() + index);
    return c;
}

void Player::displayHand() {
    for (auto &i: hand) std::cout << i << std::endl;
}