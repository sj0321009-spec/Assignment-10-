#ifndef WORDSCRAMBLE_H
#define WORDSCRAMBLE_H

#include <string>

class WordScramble {
public:
    WordScramble();
    WordScramble(std::string word, int lives);

    void setWord(std::string word);
    bool tryGuess(std::string attempt);
    
    std::string getScrambled() const { return scrambled; }
    int getLivesLeft() const { return livesLeft; }
    bool isWon() const { return won; }
    std::string reveal() const { return originalWord; }

private:
    std::string originalWord;
    std::string scrambled;
    int livesLeft;
    bool won;
    void scramble();
};

#endif
