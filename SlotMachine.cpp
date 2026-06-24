#include "SlotMachine.h"
#include <cstdlib>

SlotMachine::SlotMachine() : coins(100), totalSpins(0) {
    std::cout << "\n🎰 Welcome to the Premium Progressive Slot Machine! 🎰\n";
    for(int i=0; i<3; ++i) reel[i] = "Bar";
}

SlotMachine::SlotMachine(int startCoins) : totalSpins(0) {
    coins = (startCoins > 0) ? startCoins : 100;
    for(int i=0; i<3; ++i) reel[i] = "Bar";
}

SlotMachine::~SlotMachine() {
    std::cout << "\n[Slot Destructor] Thanks for playing! You leave with " << coins << " coins.\n";
}

void SlotMachine::setCoins(int c) {
    if (c >= 0) coins = c;
}

std::string SlotMachine::randomSymbol() {
    const std::string symbols[] = {"Cherry", "Bell", "Bar", "7", "Lemon"};
    return symbols[rand() % 5];
}

bool SlotMachine::spin(int bet) {
    if (bet <= 0 || bet > coins) {
        std::cout << "❌ Error: Invalid bet amount!\n";
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        reel[i] = randomSymbol();
    }
    totalSpins++;

    if (reel[0] == reel[1] && reel[1] == reel[2]) {
        coins += (bet * 5) - bet;
        return true;
    } else if (reel[0] == reel[1] || reel[1] == reel[2] || reel[0] == reel[2]) {
        coins += (bet * 2) - bet;
        return true;
    } else {
        coins -= bet;
        return false;
    }
}

void SlotMachine::printResult() const {
    std::cout << " [ " << reel[0] << " | " << reel[1] << " | " << reel[2] << " ] -> ";
}

void SlotMachine::resetMachine() {
    coins = 100;
    totalSpins = 0;
}

SlotMachine& SlotMachine::operator=(const SlotMachine& other) {
    if (this != &other) {
        coins = other.coins;
        totalSpins = other.totalSpins;
        for(int i = 0; i < 3; ++i) {
            reel[i] = other.reel[i];
        }
    }
    return *this;
}
