#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

#include <string>

class NumberGuesser {
public:
    NumberGuesser(int lo = 1, int hi = 100);
    
    std::string guess(int n);
    void reset(int lo = 1, int hi = 100);

    int getGuessCount() const { return guessCount; }
    bool isSolved() const { return solved; }

    static int gamesPlayed;
    static void printGamesPlayed();

private:
    int secretNumber;
    int maxGuesses;
    int guessCount;
    bool solved;
};

#endif
