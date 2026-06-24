#include "WordScramble.h"
#include <cstdlib>
#include <algorithm>

WordScramble::WordScramble() {
    const std::string wordBank[] = {
        "computer", "science", "program", "pointer", "compile",
        "dynamic", "runtime", "virtual", "inherit", "library"
    };
    livesLeft = 5;
    won = false;
    setWord(wordBank[rand() % 10]);
}

WordScramble::WordScramble(std::string word, int lives) {
    livesLeft = (lives > 0) ? lives : 5;
    won = false;
    setWord(word);
}

void WordScramble::setWord(std::string word) {
    originalWord = word;
    won = false;
    scramble();
}

void WordScramble::scramble() {
    scrambled = originalWord;
    int n = scrambled.length();
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(scrambled[i], scrambled[j]);
    }
    if (scrambled == originalWord && n > 1) {
        scramble();
    }
}

bool WordScramble::tryGuess(std::string attempt) {
    if (attempt == originalWord) {
        won = true;
        return true;
    }
    livesLeft--;
    return false;
}
