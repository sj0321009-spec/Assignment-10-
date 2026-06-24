#include "NumberGuesser.h"
#include <iostream>
#include <cstdlib>

int NumberGuesser::gamesPlayed = 0;

NumberGuesser::NumberGuesser(int lo, int hi) {
    maxGuesses = 7;
    reset(lo, hi);
}

void NumberGuesser::printGamesPlayed() {
    std::cout << "📈 Total Number Guesser Runs Across Sessions: " << gamesPlayed << "\n";
}

std::string NumberGuesser::guess(int n) {
    guessCount++;
    if (n == secretNumber) {
        solved = true;
        return "Correct!";
    } else if (guessCount >= maxGuesses) {
        return "Out of Guesses";
    } else if (n > secretNumber) {
        return "Too High";
    } else {
        return "Too Low";
    }
}

void NumberGuesser::reset(int lo, int hi) {
    if (lo > hi) std::swap(lo, hi);
    secretNumber = rand() % (hi - lo + 1) + lo;
    guessCount = 0;
    solved = false;
    gamesPlayed++;
}
