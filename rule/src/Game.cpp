//
// Created by pc on 25. 2. 10.
//
#include "Game.hpp"
#include <iostream>
#include "Deck.hpp"
#include "Player.hpp"
#include "Player1.hpp"
#include "Player2.hpp"
#include <ctime>

Game::Game()
{
    player1 = Player1("Player1");
    player2 = Player2("Player2");
    currentPlayer = &player1;
    opponent = &player2;
    cardNumberToWin = 15;
    turnNumber = 0;
}

Game::Game(std::string name1, std::string name2)
{
    player1 = Player1(name1);
    player2 = Player2(name2);
    currentPlayer = &player1;
    opponent = &player2;
    cardNumberToWin = 15;
    turnNumber = 0;
}

void Game::startGame()
{
    deck.initialBegin();
    deck.shuffleDeck();

    for (int i = 0; i < 7; ++i) {
        player1.drawCard(deck.cards);
        player2.drawCard(deck.cards);
    }

    setTopCard();
    playTurn();
}

void Game::setTopCard() {
    topCard = deck.cards.back();
    deck.cards.pop_back();
}

bool Game::checkWinner() {
    return (currentPlayer->isBothJoker() || currentPlayer->isZero() || currentPlayer->getCardCount() >= cardNumberToWin);
}

void Game::changeTurn()
{
    std::swap(currentPlayer, opponent);  // 턴 넘기기
    turnNumber++;
    std::cout << "\n==============================\n";
    std::cout << "턴이 넘어갑니다! 현재 턴: " << turnNumber << "턴\n";
    std::cout << "오픈 카드: ";
    topCard.display();
    std::cout << "==============================\n";
}

// playTurn부터 다시 시작해야함
void Game::playTurn() {
    std::cout << currentPlayer->getName() << "'s turn!" << std::endl;

    showStatus();
}



void Game::shuffleDeck() {
    deck.shuffleDeck();
}




void Game::showStatus() {
    std::cout << "Top Card: " << topCard.suit << " " << topCard.number << std::endl;
    std::cout << player1.getName() << " has " << player1.getCardCount() << " cards." << std::endl;
    std::cout << player2.getName() << " has " << player2.getCardCount() << " cards." << std::endl;
}

Card Game::getTopCard() const {
    return topCard;
}


