//
// Created by pc on 25. 2. 10.
//

#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
// #include "Enum.hpp"
#include "Card.hpp"
#include "Player1.hpp"
#include "Player2.hpp"
// #include "Game.hpp"

class Deck {
public:
    std::vector<Card> cards;

    Deck();

    void initialBegin();
    void shuffleDeck();
    bool isEmpty();
    size_t remainedCards();
    void refillDeck(std::vector<Card>& discardStack);
};


#endif //DECK_HPP
