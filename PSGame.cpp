#include "RPSGame.h"
#include <cstdlib>

RPSGame::RPSGame() : playerChoice(""), computerChoice(""), result(""), roundsPlayed(0) {}

RPSGame::~RPSGame() {}

std::string RPSGame::generateComputerChoice() {
    const std::string choices[] = {"Rock", "Paper", "Scissors"};
    return choices[rand() % 3];
}

void RPSGame::setChoice(std::string userChoice) {
    playerChoice = userChoice;
}

void RPSGame::playRound() {
    computerChoice = generateComputerChoice();
    roundsPlayed++;

    if (playerChoice == computerChoice) {
        result = "Tie";
    } else if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
               (playerChoice == "Paper" && computerChoice == "Rock") ||
               (playerChoice == "Scissors" && computerChoice == "Paper")) {
        result = "Win";
    } else {
        result = "Lose";
    }
}
