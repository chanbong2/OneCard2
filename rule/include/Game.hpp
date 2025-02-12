// //
// // Created by pc on 25. 2. 10.
// //
// #ifndef GAME_H
// #define GAME_H
//
// class Game {
// public:
//     Game();
//     void start();
//     void printResult();
//
// private:
//     Card deck[52];
//     Player1 player1;
//     Player2 player2;
//
//     void initialBegin;
//     void shuffleDeck();
//     void dealCard(); // forceDrawCard로 표현 가능
//     void setOpen();
//     void startLoop();
//     void forceDrawCard(int drawNumber);
//
//     void printCurrentPlayer();
//     void printTurnNumber();
//     bool playAvailable();
//     void checkValidCard();
//     void checkSpecialCard();
//     void changeSuit();
//     void attack(); // forceDrawCard로 표현 가능
//     void colorJoker();
//     void blackJoker();
//     bool isWin();
//     void passTurn();
// };
//
// void Game::start() {
//     shuffleDeck();
//     dealCard();
// }
//
// void Game::printResult() {
//     // winner 출력
// }
//
//
//
//
//
// #endif //GAME_H
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player1.hpp"
#include "Player2.hpp"
#include "Deck.hpp"
#include "Card.hpp"



class Game {
private:
    Player2 player1;
    Player2 player2;
    Player2* currentPlayer;
    Card topCard;
    Deck deck;
    bool gameOver;

public:
    Game(Player2& p1, Player2& p2);
    void startGame();
    void changeTurn();
    void playTurn();
    void checkWinner();
    void checkJoker();
    bool isGameOver() const;
    void showStatus();
    void shuffleDeck();
    void dealCards();
    Card getTopCard() const;
    void setTopCard(Card& card);
};


#endif //GAME_HPP
