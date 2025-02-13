//
// Created by pc on 25. 2. 10.
//

#include <iostream>
#include "Deck.hpp"
#include <algorithm>
#include <random>
#include "Enum.hpp"
#include "Card.hpp"

void Deck::initialBegin() {
    cards.clear();

    // for (int cardSuit = SPADE; cardSuit <= CLUB; cardSuit++) {
    //     for (int cardNumber = ACE; cardNumber <= KING; cardNumber++) {
    //         cards.push_back(Card(static_cast<cardSuit>(cardSuit), static_cast<cardNumber>(cardNumber)));
    //     }
    // }
    // cardSuit과 cardNumber를 enum 타입으로 변경해줘야 한다고 한다. (아래에 변경 사항 저장)

    for (cardSuit suit = SPADE; suit <= CLUB; suit = static_cast<cardSuit>(suit + 1)) {
        for (cardNumber number = ACE; number <= KING; number = static_cast<cardNumber>(number + 1)) {
            cards.push_back(Card(suit, number));
        }
    }
    cards.push_back(Card(BLACKJOKER, NONE));
    cards.push_back(Card(COLORJOKER, NONE));
}

void Deck::shuffleDeck()
{
    std::random_device random;
    std::mt19937 g(random());
    std::ranges::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard() {

}

size_t Deck::remainedCards() const
{
    return cards.size();
}
// int로 선언했으나, 반환값이 부호가 없으므로 unsigned long인 size_t로 변환을 추천받아 변경했음


bool Deck::isEmpty() const
{
    return cards.empty();
}

// isEmpty와 remainedCards에 const를 추가
// 클래스 멤버를 변경하지 않고, 조회만 수행하기 때문에 const를 붙이는 것을 추천받았다.
// 오직 읽기만 수행한다는 의미를 내포하고 있음.
//
// 컴파일러가 최적화할 수 있는 여지가 커진다는 장점도 존재한다고 한다.


void Deck::refillDeck(std::vector<Card>& discardStack)
{
    Card topCard = discardStack.back();
    discardStack.pop_back();

    cards.insert(cards.end(), discardStack.begin(), discardStack.end());
    discardStack.clear();
    discardStack.push_back(topCard);
    shuffleDeck();
    std::cout << "Deck has been refilled, except for topCard." << std::endl;
    // discardStack에서 topCard만 뺀 나머지를 Deck에다가 집어넣음
    // 그리고 shuffleDeck 수행
}