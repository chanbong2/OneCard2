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
    Player1();
    Player1(std::string pname);

    void drawCard(std::vector<Card>& deck) override;
    bool isTurn() override;
    bool isValidCard(Card& topcard) override;
    bool playCard(int index, Card& topcard, std::vector<Card>& discardStack) override;
    void showHand() override;
    void returnIndex(Card& topcard) override;
    int getCardCount() override;
    bool isBothJoker() override;
    bool isZero() override;
};

#endif //PLAYER1_HPP