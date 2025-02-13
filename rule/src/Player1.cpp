//
// Created by pc on 25. 2. 12.
//

#include "Player1.hpp"
#include <iostream>
#include "Deck.hpp"


Player1::Player1()
{
    name = "Unknown";
}

Player1::Player1(std::string pname)
{
    name = pname;
}

bool isTurn() {} // todo

void Player1::drawCard(Card& topcard)
{
    hand.push_back(topcard);
}

// bool Player1::isValidCard(Card& topcard) {
//     int len = hand.size();
//     for (int idx = 0; idx < len; idx++) {
//         Card selectedcard = hand[idx];
//         if (selectedcard.suit == topcard.suit || selectedcard.number == topcard.number) return true;
//         else return false;
//     }
// }
bool Player1::isValidCard(Card& topcard) {
    Card selectedcard = hand[idx];
    if (selectedcard.suit == topcard.suit || selectedcard.number == topcard.number) return true;
    else return false;
    }
}
// 각 카드마다 낼 수 있는 카드인지 어떻게 판별하지? enum으로 true false를 집어넣어야 하나?
// returnIndex 함수를 통해서 idx를 저장하고 내면 될 것 같음.

bool Player1::playCard(int index, Card& topcard, std::vector<Card>& discardStack) {
    std::cin >> index;
    Card selectedcard = hand[index];

    if (selectedcard.isValidCard(topcard))
    {
        discardStack.push_back(topcard);
        topcard = selectedcard;
    }

    hand.erase(hand.begin() + index);
    selectedcard.display();
    return true;
}

void Player1::showHand()
{
    int len = hand.size();
    for (int idx = 0; idx < len; idx++){
        hand[idx].display();
    }
}

int Player1::getCardCount()
{
    int size = hand.size();
    return size;
}

void Player1::returnIndex(Card& topcard, std::vector<Card>& discardPile)
{
    std::vector<int> ans;
    int size = hand.size();
    for (int idx = 0; idx < size; idx++)
    {
        Card selectedcard = hand[idx];
        if (selectedcard.isValidCard(topcard))
        {
            ans.push_back(idx);
        }
    }
    int len = ans.size();
    if (len == 0)
    {
        drawCard(topcard);
    }
    else
    {
        std::cout << "낼 수 있는 카드의 인덱스는 : ";
        for (int idx = 0; idx < len; idx++)
        {
            std::cout << ans[idx] << " ";
        }
    }
    std::cout << std::endl;
}

bool Player1::isBothJoker()
{
    int size = hand.size();
    int count = 0;
    for (int idx = 0; idx < size; idx++)
    {
        Card selectedcard = hand[idx];
        if (selectedcard.suit == BLACKJOKER || selectedcard.suit == COLORJOKER) count++;
    }
    if (count == 2) return true;
    else return false;
}

bool Player1::isZero()
{
    if (hand.size() == 0) return true;
}