//
// Created by pc on 25. 2. 10.
//
#include "Game.hpp"
#include <iostream>
#include <ctime>

Game::Game(Player2& p1, Player2& p2)
    : player1(p1), player2(p2), currentPlayer(&player1), gameOver(false) {
    deck.initialBegin();
    deck.shuffleDeck();
    setTopCard(deck.drawCard());
    dealCards();
}

void Game::startGame() {
    std::cout << "Game has started!" << std::endl;
    showStatus();

    while (!gameOver) {
        playTurn();
        changeTurn();
    }

    checkJoker() {
        if (player1.)
    };
}

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
        player1.addCard(deck.drawCard());
        player2.addCard(deck.drawCard());
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

void Game::setTopCard(Card& card) {
    topCard = card;
}

