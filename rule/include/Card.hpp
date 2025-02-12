//
// Created by pc on 25. 2. 10.
//

#ifndef CARD_HPP
#define CARD_HPP

#include "Enum.hpp"
//#include "Deck.hpp"
//#include "Player.hpp"
// #include "Game.hpp"

class Card {
    public:
    cardSuit suit;
    cardNumber number;

    Card();
    Card(cardSuit suit, cardNumber number);

    // 문득 든 생각인데
    // Card 클래스에 isValid, isSpecial, isAttack 등의 메소드를 추가하는게 맞나?
    // 이건 여기서 판단할 문제가 아니라, Player가 판단해야 할 문제 아닌가?
    void display();
    bool isValidCard(Card& topcard);
    // bool isSpecialCard();
    // bool isAttack();
    // bool isDefend();
    // bool isChangeSuit();
};

#endif //CARD_HPP
