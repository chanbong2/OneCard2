//
// Created by pc on 25. 2. 10.
//
#include "Game.hpp"
#include <iostream>
#include "Deck.hpp"
#include "Player.hpp"
#include "Player1.hpp"
#include "Player2.hpp"

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
    playGame();
}

void Game::setTopCard() {
    topCard = deck.cards.back();
    deck.cards.pop_back();
}

bool Game::checkWinner() {
    return (currentPlayer->checkTwoJoker() || currentPlayer->isZero() || currentPlayer->getCardCount() >= cardNumberToWin);
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
void Game::playGame() {

}


// 어차피 deck에서 끌어쓰는거라 굳이 정의 안 해도 될 것 같음
// void Game::shuffleDeck() {
//     deck.shuffleDeck();
// }
