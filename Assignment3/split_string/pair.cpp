#include "pair.h"

#include <iostream>

using namespace std;

Pair *splitPair(string s, int &length) {
    Pair *pairs = new Pair;
    length = 0;
    if (s.length() <= 2)
        return pairs;
    while (s.length() > 2) {
        if (s.length() >= 3) {
            pairs[length++] = {s.at(0), s.at(2)};
            if (s.length() >= 4) {
                pairs[length++] = {s.at(1), s.at(3)};
                s = s.substr(4, s.length() - 4);
            } else
                s = s.at(1) + s.substr(3, s.length() - 3);
        }
    }
    return pairs;
}

void printPair(Pair *pair) {
    cout << pair->c1 << " " << pair->c2 << endl;
}
