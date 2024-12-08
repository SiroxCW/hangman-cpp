
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <conio.h>

int main() {
    srand(time(0));
    int lineCount = 0;
    std::ifstream file("words.txt");
    std::string line;
    std::string randomWord;
    std::string wrongGuesses = "";
    std::string userInput;
    int stage = 1;

    while (getline(file, line)) {
        lineCount++;
    }
    int randomNumber = rand() % lineCount;
    lineCount = 0;
    file.clear();
    file.seekg(0, file.beg);
    
    while (getline(file, line)) {
        if (lineCount == randomNumber) {
            randomWord = line;
            break;
        }
        lineCount++;
    }
    file.close();

    std::string stringBlanks(randomWord.length(), '_');
    std::string hangmanASCIIstage1 =
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "             ";
    std::string hangmanASCIIstage2 =
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "           \n"
    "  /\\         ";
    std::string hangmanASCIIstage3 =
    "           \n"
    "           \n"
    "           \n"
    "   |       \n"
    "   |       \n"
    "  /\\         ";
    std::string hangmanASCIIstage4 =
    "           \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "  /\\         ";
    std::string hangmanASCIIstage5 =
    "    _____  \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "  /\\         ";
    std::string hangmanASCIIstage6 =
    "    _____  \n"
    "   |/      \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "  /\\         ";
    std::string hangmanASCIIstage7 =
    "    _____  \n"
    "   |/   |  \n"
    "   |       \n"
    "   |       \n"
    "   |       \n"
    "  /\\         ";
    std::string hangmanASCIIstage8 =
    "    _____  \n"
    "   |/   |  \n"
    "   |   (?) \n"
    "   |   /|\\ \n"
    "   |   /\\  \n"
    "  /\\         ";

    while (true) {
        system("cls");
        switch (stage) {
            case 1: std::cout << hangmanASCIIstage1 + "      " << stringBlanks; break;
            case 2: std::cout << hangmanASCIIstage2 + "      " << stringBlanks; break;
            case 3: std::cout << hangmanASCIIstage3 + "      " << stringBlanks; break;
            case 4: std::cout << hangmanASCIIstage4 + "      " << stringBlanks; break;
            case 5: std::cout << hangmanASCIIstage5 + "      " << stringBlanks; break;
            case 6: std::cout << hangmanASCIIstage6 + "      " << stringBlanks; break;
            case 7: std::cout << hangmanASCIIstage7 + "      " << stringBlanks; break;
            case 8: std::cout << hangmanASCIIstage8 + "      " << stringBlanks << "\n\nYou Lose! The word was " << randomWord << "!\n"; getch(); return 0;
        }
        std::cout << "\n\nWrong guesses: " << wrongGuesses << "\nPlease enter your guess: ";
        std::cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c){ return std::tolower(c); });
        if (userInput.length() > 1) {
            if (userInput == randomWord) {
                break;
            }
            else {
                stage++;
            }
        }
        else {
            if (randomWord.find(userInput) == std::string::npos) {
                stage++;
                wrongGuesses.append(userInput + ", ");
            }
            else {
                for (int i = 0; i <= randomWord.length() - 1; i++) {
                    if (!userInput.find(randomWord[i])) {
                        stringBlanks[i] = userInput[0];
                    }
                }
                if (stringBlanks.find('_') == std::string::npos) {
                    break;
                }
            }
        }
    }
    system("cls");
    switch (stage) {
        case 1: std::cout << hangmanASCIIstage1 + "      " << stringBlanks; break;
        case 2: std::cout << hangmanASCIIstage2 + "      " << stringBlanks; break;
        case 3: std::cout << hangmanASCIIstage3 + "      " << stringBlanks; break;
        case 4: std::cout << hangmanASCIIstage4 + "      " << stringBlanks; break;
        case 5: std::cout << hangmanASCIIstage5 + "      " << stringBlanks; break;
        case 6: std::cout << hangmanASCIIstage6 + "      " << stringBlanks; break;
        case 7: std::cout << hangmanASCIIstage7 + "      " << stringBlanks; break;
    }
    std::cout << "\n\n  You Won!" << "\n\n";
    getch();
    return 0;
}
