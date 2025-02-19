//
// Created by pc on 25. 2. 10.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"
#include <vector>
#include <string>

class Player {
public:
    std::string name;
    std::vector<Card> hand;

    virtual void drawCard(std::vector<Card>& deck);
    virtual bool isTurn();
    virtual bool isValidCard(Card& topcard);
    virtual bool playCard(int index, Card& topcard);
    virtual void showHand();
    virtual void returnIndex(Card& topcard);
    virtual int getCardCount();
    virtual bool isBothJoker();
    virtual bool isZero();
    virtual ~Player() = default;
};

#endif //PLAYER_HPP
