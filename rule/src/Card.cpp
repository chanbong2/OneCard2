//
// Created by pc on 25. 2. 10.
//

//
#include "Card.hpp"
#include <iostream>

Card::Card(cardSuit suit, cardNumber number)
    : suit(suit), number(number) {}

void Card::display()
{
    std::cout << "문양 : " << suit << std::endl;
    std::cout << "숫자 : " << number << std::endl;
    if (suit == SPADE || suit == CLUB || suit == BLACKJOKER) std::cout << "색깔 : BLACK" << std::endl;
    else std::cout << "색깔 : RED" << std::endl;
}

bool Card::isValidCard(Card& topcard) {
    if (this->suit == topcard.suit) return true;
    if (this->number == topcard.number) return true;
    if (this->suit == COLORJOKER && (topcard.suit == HEART || topcard.suit == DIAMOND)) return true;
    if (this->suit == BLACKJOKER && (topcard.suit == SPADE || topcard.suit == CLUB)) return true;

    return false;
}

// bool Card::isSpecialCard() {
//     return skill != NONE;
// }
//
// bool Card::isAttack() {
//     return skill == ATTACK;
// }
//
// bool Card::isDefend() {
//     return skill == DEFEND;
// }
//
// bool Card::isChangeSuit() {
//     return number == SEVEN;
// }