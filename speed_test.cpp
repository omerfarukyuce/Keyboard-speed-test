#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h> 

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

std::string getRandomWord(std::vector<std::string>& words) {
    int randomIndex = rand() % words.size();
    std::string word = words[randomIndex];
    words.erase(words.begin() + randomIndex);
    return word;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::vector<std::string> wordList = {
        "run", "apple", "and", "jump", "banana", "but",
        "cherry", "date", "elderberry", "fig", "grape",
        "honeydew", "kiwi", "lemon", "mango", "nectarine",
        "orange", "papaya", "quince", "raspberry", "strawberry",
        "tangerine", "ugly", "watermelon", "blueberry", "blackberry",
        "cantaloupe", "dragonfruit", "grapefruit", "jackfruit",
        "kumquat", "lime", "mulberry", "olive", "peach", "pear",
        "pineapple", "plum", "pomegranate", "run", "jump",
        "swim", "read", "write", "code", "play", "sing",
        "dance", "think", "create", "build", "imagine",
        "explore", "discover", "believe", "understand", "learn",
        "teach", "grow", "move", "listen", "speak", "observe",
        "communicate", "develop", "analyze", "design", "solve",
        "collaborate", "improve", "enjoy", "experiment", "travel",
        "experience", "the", "is", "in", "on", "at", "of", "for", "with", "about"
    };

    std::cout << "Typing speed test is starting. Type the given words and press space. You have 1 minute.\n";
    std::cout << "Press any key to start.\n";
    _getch();

    std::time_t start = std::time(nullptr);
    std::time_t end = start + 60; // 1 minute later

    int wordCount = 0;
    int correctWords = 0;
    int incorrectWords = 0;

    while (std::time(nullptr) < end && !wordList.empty()) {
        std::string randomWord = getRandomWord(wordList);
        std::cout << randomWord << " ";
        std::string userInput;
        char ch;
        while ((ch = _getch()) != ' ') {
            if (ch == '\b' && !userInput.empty()) {
                userInput.pop_back();
                std::cout << "\b \b";  // Remove the character visually
            }
            else if (ch != '\b') {
                userInput += ch;
                std::cout << ch;
            }
        }

        if (userInput == randomWord) {
            std::cout << " " << GREEN << userInput << RESET << "   ";
            correctWords++;
        }
        else {
            std::cout << " " << RED << userInput << RESET << "   ";
            incorrectWords++;
        }
        wordCount++;
    }

    double wpm = static_cast<double>(wordCount) / 1.0; // 1 minute

    std::cout << "\nTest finished!\n";
    std::cout << "Total words typed: " << wordCount << "\n";
    std::cout << "Correct words: " << correctWords << "\n";
    std::cout << "Incorrect words: " << incorrectWords << "\n";
    std::cout << "Words per minute (WPM): " << wpm << "\n";

    return 0;
}
