#ifndef ARCADEMANAGER_H
#define ARCADEMANAGER_H

#include <string>
#include "SlotMachine.h"
#include "NumberGuesser.h"
#include "WordScramble.h"

class ArcadeManager {
public:
    // Required Nested HighScore Struct
    struct HighScore {
        std::string playerName;
        int score;
    };

    ArcadeManager();
    void setPlayer(std::string name, int tkns);
    void launchMenu();
    void printStats() const;
    void awardBonus(int bonus);

    static int totalSessions;
    static void printLeaderboard();

private:
    std::string playerName;
    int totalTokens;
    std::string lastGame;

    SlotMachine slots;
    NumberGuesser guesser;
    WordScramble scrambler;
    

    void runSlots();
    void runGuesser();
    void runScramble();
    
    
    // Bonus Challenge 2: Persistence declarations
    void saveSession();
    void loadSession();
};

#endif
