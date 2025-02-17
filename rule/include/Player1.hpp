//
// Created by pc on 25. 2. 12.
//

#ifndef PLAYER1_HPP
#define PLAYER1_HPP

#include "Enum.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include "Game.hpp"
#include <string>


class Player1
{
public:
    std::string name;
    std::vector<Card> hand;
    Player1();
    Player1(std::string pname);
    void drawCard(std::vector<Card> deck);
    bool isTurn();
    bool isValidCard(Card& topcard);
    bool playCard(int index, Card& topcard, std::vector<Card>& discardStack);
    void showHand();
    void returnIndex(Card& topcard, std::vector<Card>& discardStack);
    int getCardCount();
    bool isBothJoker();
    bool isZero();
};

#endif //PLAYER1_HPP