//
// Created by pc on 25. 2. 10.
//
#include "Game.hpp"
#include <iostream>
#include "Deck.hpp"
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

void Game::startGame() {
    std::cout << "Game has started!" << std::endl;
    showStatus();

    while (!gameOver) {
        playTurn();
        changeTurn();
    }
}
    // joker check 함수도 만들기

void Game::playTurn() {
    std::cout << currentPlayer->getName() << "'s turn!" << std::endl;

    showStatus();
}

void Game::changeTurn() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
    }
    else {
        currentPlayer = &player1;
    }
}

void Game::checkWinner() {
    if (player1.getCardCount() == 0) {
        std::cout << player1.getName() << " wins the game!" << std::endl;
    } else if (player2.getCardCount() == 0) {
        std::cout << player2.getName() << " wins the game!" << std::endl;
    } else {
        std::cout << "The game is still on." << std::endl;
    }
    gameOver = true;
}

void Game::shuffleDeck() {
    deck.shuffleDeck();
}


void Game::dealCards() {
    for (int i = 0; i < 7; ++i) {
        player1.drawCard(deck.drawCard());
        player2.drawCard(deck.drawCard());
    }
}

void Game::showStatus() {
    std::cout << "Top Card: " << topCard.suit << " " << topCard.number << std::endl;
    std::cout << player1.getName() << " has " << player1.getCardCount() << " cards." << std::endl;
    std::cout << player2.getName() << " has " << player2.getCardCount() << " cards." << std::endl;
}

Card Game::getTopCard() const {
    return topCard;
}


