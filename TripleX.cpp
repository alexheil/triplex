#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {

    // Print welcome messages to terminal
    std::cout << std::endl;
    std::cout << "You are a secret agent breaking into a level " << Difficulty << std::endl;
    std::cout << "server room. You must solve a puzzle to continue..." << std::endl;

}

// Must return boolean at any place a function would end.
bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code.\n";
    std::cout << "The codes add up to: " << CodeSum << std::endl;
    std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

    // Declare variables for declaring variables.
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess coreect.
    if (CodeSum == GuessSum && CodeProduct == GuessProduct) {
        std::cout << "\nYou broke in!" <<std::endl;
        return true;
    } 
    else {
        return false;
    }

}

int main() {

    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    // Loop game until all levels are complete.
    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors.
        std::cin.ignore(); // Discards the buffer.

        if (bLevelComplete) {
            ++LevelDifficulty;
        } else {
            std::cout << "\nYou exploded! Better luck in the afterlife, noob.\n" << std::endl;
            return 0;
        }
        
    }

    std::cout << "\nYou win, snowflake!\n";

    return 0;

}