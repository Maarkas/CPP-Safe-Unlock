#include <iostream>
#include <ctime>

bool PlayGame(int LevelDifficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << LevelDifficulty;
    std::cout << " secure server room...\nYou need to enter the correct codes to continue...\n\n";

    // 3 Number codes
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print out sum and product to the terminal;
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << "\n\n";
    
    // Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nCode correct!";
        return true;
    } else {
        std::cout << "\nCode incorrect! Retry!";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }
    std::cout << "\n*** Great work, you've completed the game! ***\n";
    return 0;
}