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
    private:
    std::vector<Card> cards;
    Player2 player1;
    Player2 player2;

    public:
    Deck();

    void initialBegin();
    void shuffleDeck();
    void setTopCard();
    size_t remainedCards() const;
    bool isEmpty() const;
    void refillDeck(std::vector<Card>& discardStack);
    Card drawCard(Player2& p1);
};


#endif //DECK_HPP
