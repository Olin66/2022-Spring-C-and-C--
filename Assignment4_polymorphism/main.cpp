#include <iostream>
#include <random>
#include <vector>
#include<algorithm>
#include<ctime>

#include "card.h"
#include "exchange_card.h"
#include "player.h"
#include "big_boss_card.h"

using namespace std;

int main() {
    srand(unsigned(time(nullptr)));
    vector<Card *> player1;
    vector<Card *> player2;
    //initialize player1
    for (int i = 1; i <= 21; ++i) {
        string name = "card1_" + to_string(i);
        int attack = rand() % 10 + 1;
        int defense = rand() % 10 + 1;
        Card *card = new Card(name, attack, defense);
        player1.push_back(card);
    }
    Card *bossCard1 = new BigBossCard("boss1", 10, 10);
    Card *exchangeCard1_1 = new ExchangeCard("exchange1_1", 5, 5);
    Card *exchangeCard1_2 = new ExchangeCard("exchange1_2", 4, 6);
    Card *exchangeCard1_3 = new ExchangeCard("exchange1_3", 10, 4);
    player1.push_back(bossCard1);
    player1.push_back(exchangeCard1_1);
    player1.push_back(exchangeCard1_2);
    player1.push_back(exchangeCard1_3);
    shuffle(player1.begin(), player1.end(), std::mt19937(std::random_device()()));
    //initialize player2
    for (int i = 1; i <= 21; ++i) {
        string name = "card2_" + to_string(i);
        int attack = rand() % 10 + 1;
        int defense = rand() % 10 + 1;
        Card *card = new Card(name, attack, defense);
        player2.push_back(card);
    }
    Card *bossCard2 = new BigBossCard("boss2", 10, 10);
    Card *exchangeCard2_1 = new ExchangeCard("exchange2_1", 5, 5);
    Card *exchangeCard2_2 = new ExchangeCard("exchange2_2", 4, 6);
    Card *exchangeCard2_3 = new ExchangeCard("exchange2_3", 10, 4);
    player2.push_back(bossCard2);
    player2.push_back(exchangeCard2_1);
    player2.push_back(exchangeCard2_2);
    player2.push_back(exchangeCard2_3);
    shuffle(player2.begin(), player2.end(), std::mt19937(std::random_device()()));
    Player p1(player1, "player1");
    Player p2(player2, "player2");
    //play the game
    double sum1 = 0, sum2 = 0;
    int round = 0;
    Player *winner = nullptr;
    while (++round <= 20) {
        cout << "round " << round << ": " << endl;
        int temp = rand() % 5;
        Card *c1 = p1.play(temp);
        Card *c2 = p2.play(temp);
        cout<<"Card 1: "<<(*c1)<<endl;
        cout<<"Card 2: "<<(*c2)<<endl;
        int dice = rand() % 2;
        if (dice) {
            sum1 += c1->power(*c2);
            c1->effect(*c2, p1, p2);
            sum2 += c2->power(*c1);
            c2->effect(*c1, p2, p1);
        } else {
            sum2 += c2->power(*c1);
            c2->effect(*c1, p2, p1);
            sum1 += c1->power(*c2);
            c1->effect(*c2, p1, p2);
        }
        cout << "sum1=" << sum1 << "  " << "sum2=" << sum2 << endl;
        if (sum1 >= 100 && sum2 < 100) {
            winner = &p1;
            break;
        } else if (sum1 < 100 && sum2 >= 100) {
            winner = &p2;
            break;
        } else if (sum1 >= 100 && sum2 >= 100) {
            if (sum1 > sum2) {
                winner = &p1;
                break;
            } else if (sum2 < sum1) {
                winner = &p2;
                break;
            }
        }
        if (p1.deck.empty() && !p2.deck.empty()) {
            // cout<<"p2:"<<p2.deck.size()<<endl;
            winner = &p2;
            break;
        } else if (!p1.deck.empty() && p2.deck.empty()){
            // cout<<"p1:"<<p1.deck.size()<<endl;
            winner = &p1;
            break;
        } else if (p1.deck.empty() && p2.deck.empty()) break;
        p1.draw();
        p2.draw();
        delete c1;
        delete c2;
    }
    if (winner == nullptr) cout << "Draw!" << endl;
    else cout << "The winner is " << winner->name << endl;
    p1.displayHand();
    p2.displayHand();
    for (auto & i : p1.deck)    delete i;
    for (auto & i : p1.hand)    delete i;
    for (auto & i : p2.deck)    delete i;
    for (auto & i : p2.hand)    delete i;
}
