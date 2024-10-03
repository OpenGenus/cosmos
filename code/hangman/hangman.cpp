#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Takes in the word user is trying to guess as parameter
// Returns true if user guesses the full word 
// Returns false otherwise
bool guessWord(string word) {
    cout << "Guess the word (all characters lowercase): ";
    string guess;
    cin >> guess;
    cout << endl;
    if (guess.compare(word) == 0) {
        return true;
    }
    return false;
}

bool checkGuess(string guess) {
    if (guess.length() != 1) {
        return false;
    }
    return true;
}

// Runs Hangman game
void game() {
    // Getting random index (out of 370,103) from the word database
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 370103);
    int index = dis(gen);

    // Pulling the word from the database
    string word, temp;
    fstream myFile;
    myFile.open("words_alpha.txt");
    while (index > 0) {
        getline(myFile, temp);
        index--;
    }
    getline(myFile, word);
    myFile.close(); 
    
    // Creating variables to store guesses by user and letters with indices of the word
    unordered_set<char> guesses;
    unordered_map<char, vector<int>> letters;

    // knownLetters is what user sees and lettersLeft is the number of letters user has left to guess
    string knownLetters = "";
    int lettersLeft = word.length();

    // Putting underscore for each letter in word to show user
    // Also storing each letter with corresponding index in unordered_map
    for (int i = 0; i < word.length(); i++) {
        char c = word.at(i);
        knownLetters += "_";

        letters[c].push_back(i);
    }

    // Setting number of strikes to 0, at 5 strikes the user loses
    int strikes = 0;

    // While the user hasn't guessed every letter
    while (lettersLeft > 0) {
        cout << "You have " << strikes << " strikes.\n";
        if (strikes > 4) {
            cout << "You lose. Try again!\n";
            break;
        }

        cout << knownLetters << endl;

        // Takes in character as an input, allows user to guess the whole word
        cout << "Guess a letter (lowercase) or enter 1 if you want to guess the word: ";
        string guessStr;
        cin >> guessStr;

        // If user inputs more than 1 character, let them input again
        while (!checkGuess(guessStr)) {
            cout << "Please guess a single character: ";
            cin >> guessStr;
        }

        char guess = guessStr.at(0);

        // If they guess the word, the game ends whether they are right or wrong
        if (guess == '1') {
            if (guessWord(word)) {
                cout << "You win!\n";
            }
            else {
                cout << "You lose. Try again!\n";
            }
            break;
        }

        // If user has already guessed letter, then prompt them to guess a different letter
        while (guesses.count(guess) != 0 || !checkGuess(guessStr)) {
            if (!checkGuess(guessStr)) {
                cout << "Please guess a single character\n";
            }
            else {
                cout << "You have already guessed \'" << guess << "\'" << endl;
            }
            cout << "Please guess again: \n";
            cin >> guessStr;
            guess = guessStr.at(0);
        }

        // Add new guess to the unordered_set
        guesses.insert(guess);
        cout << endl;

        // If letter has no indices, then it isn't in the word, so that's a strike
        if (letters[guess].size() == 0) {
            strikes++;
        }

        // Else, reveal the letter at each index and decrement lettersLeft
        else {
            for (int i : letters[guess]) {
                knownLetters.at(i) = guess;
                lettersLeft--;
            }
        }

        // If there are no letters left, then the user wins
        if (lettersLeft == 0) {
            cout << "You win!\n";
        }
    }
    cout << "\nThe word was: " << word << endl;

    // Allows the user to play again without recompiling
    int playAgain;
    cout << "\nPress 1 if you would like to play again\n";
    cin >> playAgain;
    if (playAgain == 1) {
        cout << endl;
        game();
    }
}


int main() {
    // Ensures different index on each compile
    srand(time(nullptr));
    
    game();
    return 0;
}