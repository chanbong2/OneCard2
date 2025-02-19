//
// Created by pc on 25. 2. 12.
//

#ifndef PLAYER2_HPP
#define PLAYER2_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include <string>


class Player2 : public Player
{
public:
    std::string name;
    std::vector<Card> hand;

    Player2();
    Player2(std::string pname);

    bool isTurn() override;
    void drawCard(std::vector<Card>& deck) override;
    bool isValidCard(Card& topcard) override;
    bool playCard(int index, Card& topcard, std::vector<Card>& discardStack) override;
    int getCardCount();
    bool checkTwoJoker() override;
    bool isZero() override;
};

#endif //PLAYER2_HPP
