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
#include <string>
#include "Player.hpp"
#include "Player1.hpp"
#include "Player2.hpp"
#include "Deck.hpp"
#include "Card.hpp"



class Game {
public:
    Player* currentPlayer;
    Player* opponent;
    Player1 player1;
    Player2 player2;
    Card topCard;
    Deck deck;
    std::vector<Card> discardStack;

    int turnNumber;
    int cardNumberToWin;

    Game();
    Game(std::string name1, std::string name2);
    void startGame();
    void setTopCard();
    bool checkWinner(); // 조커로 인한 패배 포함
    void changeTurn();
    void playGame();
    void isValidCard(Card& card);
    // void shuffleDeck(); 어차피 deck에서 끌어쓰는거라 굳이 정의 안 해도 될 것 같음
};


#endif //GAME_HPP
