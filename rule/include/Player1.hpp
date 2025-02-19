//
// Created by pc on 25. 2. 12.
//

#ifndef PLAYER1_HPP
#define PLAYER1_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include <string>


class Player1 : public Player
{
public:
    std::string name;
    std::vector<Card> hand;

    Player1();
    Player1(std::string pname);

    bool isTurn() override;
    void drawCard(std::vector<Card>& deck) override;
    bool isValidCard(Card& topcard) override;
    bool playCard(int index, Card& topcard, std::vector<Card>& discardStack) override;
    int getCardCount();
    bool checkTwoJoker() override;
    bool isZero() override;
};

#endif //PLAYER1_HPP