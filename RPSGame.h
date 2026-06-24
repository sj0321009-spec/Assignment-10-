#ifndef RPSGAME_H
#define RPSGAME_H

#include <string>

class RPSGame {
public:
    RPSGame();  // Constructor
    ~RPSGame(); // Destructor

    // Mutators
    void setChoice(std::string userChoice);
    void playRound();

    // Accessors
    std::string getComputerChoice() const { return computerChoice; }
    std::string getResult() const { return result; }
    
    // Inline function
    int getRoundsPlayed() const { return roundsPlayed; }

private:
    std::string playerChoice;
    std::string computerChoice;
    std::string result;
    int roundsPlayed;

    std::string generateComputerChoice();
};

#endif
