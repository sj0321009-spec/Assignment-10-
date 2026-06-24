#include "ArcadeManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "====================================\n"
              << "     INITIALIZING CAMPUS ARCADE     \n"
              << "====================================\n";

    ArcadeManager coreArcade;
    std::string user;
    int startingTokens;

    std::cout << "Enter profile designation moniker: ";
    std::cin >> user;
    std::cout << "Purchase incoming token investment value: ";
    if(!(std::cin >> startingTokens)) startingTokens = 100;

    coreArcade.setPlayer(user, startingTokens);
    coreArcade.launchMenu();

    return 0;
}
