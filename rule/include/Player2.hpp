//
// Created by pc on 25. 2. 12.
//

#ifndef PLAYER2_HPP
#define PLAYER2_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include <string>


class Player2 : Player
{
public:
    Player2();
    Player2(std::string pname);

    void drawCard(std::vector<Card>& deck) override;
    bool isTurn() override;
    bool isValidCard(Card& topcard) override;
    bool playCard(int index, Card& topcard) override;
    void showHand() override;
    void returnIndex(Card& topcard) override;
    int getCardCount() override;
    bool isBothJoker() override;
    bool isZero() override;
};

#endif //PLAYER2_HPP
