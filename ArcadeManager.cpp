#include "ArcadeManager.h"
#include <iostream>
#include <fstream>

int ArcadeManager::totalSessions = 0;

// Shared Mock Global Array Structure representing standard static leaderboards
static ArcadeManager::HighScore globalLeaderboard[3] = {
    {"Alice", 500}, {"Bob", 300}, {"Charlie", 150}
};

ArcadeManager::ArcadeManager() : playerName("Guest"), totalTokens(100), lastGame("None"), guesser(1, 100) {
    totalSessions++;
    loadSession(); // Check for existing records on boot
}

void ArcadeManager::setPlayer(std::string name, int tkns) {
    if(!name.empty()) playerName = name;
    if(tkns > 0) totalTokens = tkns;
    slots.setCoins(totalTokens);
}

void ArcadeManager::printLeaderboard() {
    std::cout << "\n🏆 --- ALL-TIME ARCADE LEADERBOARD --- 🏆\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << i+1 << ". " << globalLeaderboard[i].playerName << " - " << globalLeaderboard[i].score << " pts\n";
    }
}

void ArcadeManager::awardBonus(int bonus) {
    if(bonus > 0) {
        totalTokens += bonus;
        slots.setCoins(slots.getCoins() + bonus);
        std::cout << "🎁 Loyalty Bonus! Added " << bonus << " tokens to your system balance.\n";
    }
}

void ArcadeManager::printStats() const {
    std::cout << "\n📊 --- CURRENT SESSION STATS --- 📊\n"
              << "👤 Player Name  : " << playerName << "\n"
              << "🪙 Tracked Tokens: " << totalTokens << "\n"
              << "🎰 Slot Machine Coins: " << slots.getCoins() << "\n"
              << "🎮 Last Game Run : " << lastGame << "\n"
              << "🌎 Active Sessions Context Counter: " << totalSessions << "\n";
}

void ArcadeManager::runSlots() {
    lastGame = "Slot Machine";
    int bet;
    std::cout << "\n--- 🎰 SLOT ENGINE INTERFACE --- \n";
    std::cout << "Current Bal: " << slots.getCoins() << ". Input your wager: ";
    if(!(std::cin >> bet)) return;

    if(slots.spin(bet)) {
        std::cout << "🎉 WINNER! ";
        slots.printResult();
        std::cout << "Balance updated to: " << slots.getCoins() << "\n";
    } else {
        std::cout << "💀 LOSER! ";
        slots.printResult();
        std::cout << "Balance dropped to: " << slots.getCoins() << "\n";
    }
    totalTokens = slots.getCoins();
}

void ArcadeManager::runGuesser() {
    lastGame = "Number Guesser";
    guesser.reset(1, 100);
    int activeGuess;
    std::cout << "\n--- 🔮 GUESS THE NUMBER (1-100) --- \n";

    while(!guesser.isSolved()) {
        std::cout << "Attempt (" << guesser.getGuessCount() + 1 << "/7): ";
        if(!(std::cin >> activeGuess)) return;

        std::string verdict = guesser.guess(activeGuess);
        std::cout << " -> " << verdict << "\n";

        if(verdict == "Correct!") {
            std::cout << "🏆 Incredible work! You resolved it in " << guesser.getGuessCount() << " tries.\n";
            awardBonus(50);
            break;
        } else if(verdict == "Out of Guesses") {
            std::cout << "💥 Out of resources! Game over.\n";
            break;
        }
    }
}

void ArcadeManager::runScramble() {
    lastGame = "Word Scramble";
    scrambler = WordScramble(); // generate fresh word
    std::string userAttempt;
    std::cout << "\n--- 🔠 WORD SCRAMBLE CHALLENGE --- \n";

    while(scrambler.getLivesLeft() > 0 && !scrambler.isWon()) {
        std::cout << "Scrambled Word: " << scrambler.getScrambled() << "\n"
                  << "Lives Left    : " << scrambler.getLivesLeft() << "\n"
                  << "Your Guess    : ";
        std::cin >> userAttempt;

        if(scrambler.tryGuess(userAttempt)) {
            std::cout << "🎉 Correct! You decoded the sequence.\n";
            awardBonus(75);
            break;
        } else {
            std::cout << "❌ Wrong guess!\n";
        }
    }
    if(!scrambler.isWon()) {
        std::cout << "💀 Out of lives! The true answer was: " << scrambler.reveal() << "\n";
    }
}

void ArcadeManager::saveSession() {
    std::ofstream outFile("arcade_save.txt");
    if (outFile.is_open()) {
        outFile << playerName << "\n" << totalTokens << "\n" << lastGame << "\n";
        outFile.close();
    }
}

void ArcadeManager::loadSession() {
    std::ifstream inFile("arcade_save.txt");
    if (inFile.is_open()) {
        inFile >> playerName >> totalTokens >> lastGame;
        inFile.close();
    }
}

void ArcadeManager::launchMenu() {
    int choice;
    do {
        std::cout << "\n====================================\n"
                  << "        CAMPUS ARCADE MATRIX        \n"
                  << "====================================\n"
                  << "1. Play Slot Machine\n"
                  << "2. Play Number Guesser\n"
                  << "3. Play Word Scramble\n"
                  << "4. View Live Session Stats\n"
                  << "5. Read System Hall of Fame\n"
                  << "6. Exit Application Framework\n"
                  << "Choice: ";
        if(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        switch(choice) {
            case 1: runSlots(); break;
            case 2: runGuesser(); break;
            case 3: runScramble(); break;
            case 4: printStats(); break;
            case 5: printLeaderboard(); NumberGuesser::printGamesPlayed(); break;
            case 6: saveSession(); std::cout << "💾 State serialized. Farewell!\n"; break;
            default: std::cout << "Unknown option.\n";
        }
    } while (choice != 6);
}
