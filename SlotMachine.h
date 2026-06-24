#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <string>
#include <vector>

class SlotMachine {
public:
    SlotMachine();
    SlotMachine(int startCoins);
    ~SlotMachine();

    void setCoins(int c);
    bool spin(int bet);
    void printResult() const;
    void resetMachine();

    int getCoins() const { return coins; }
    int getTotalSpins() const { return totalSpins; }

    // Bonus Challenge 1: Assignment operator overload for deep copies
    SlotMachine& operator=(const SlotMachine& other);

private:
    int coins;
    std::string reel[3];
    int totalSpins;
    std::string randomSymbol();
};

#endif
