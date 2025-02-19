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

    virtual bool isTurn();
    virtual void drawCard(std::vector<Card>& deck);
    virtual bool isValidCard(Card& topcard);
    virtual bool playCard(int index, Card& topcard, std::vector<Card>& discardStack);
    virtual int getCardCount();
    virtual bool checkTwoJoker();
    virtual bool isZero();
    virtual ~Player() = default;
};

#endif //PLAYER_HPP
