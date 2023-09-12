#include <bits/stdc++.h>
using namespace std;

char guessLetter()
{
    char guess;
    cout << "The letter you guess : ";
    cin >> guess;
    while (toupper(guess) < 'A' || toupper(guess) > 'Z')
    {
        cout << "The letter must be in the English alphabet, try again : ";
        cin >> guess;
    }
    return guess;
}

void checkGuessedLetter(char &guess, string &answer, string &lines, int &wrongGuesses)
{
    int count = 0;
    for (int i = 0; i < answer.size(); i++){
        if (answer[i] == guess){
            lines[i] = guess;
            count++;
        }
    }
    if (count == 0){
        wrongGuesses++;
        cout << "The secret word doesn't contain the letter " << guess << " !" << endl;

    }
    else {
        if (count == 1) cout << "There is 1 " << guess << " in the secret word !" << endl;
        else cout << "There are " << count << " " << guess << " in the secret word !" << endl;
    }
    cout << "Number of wrong guesses : " << wrongGuesses << endl
         << "Secret word : " << lines << endl;
}

const int maxOfWrongGuesses = 7;

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
const string WORD_LIST[] = {"admin", "apple", "advice", "approve", "architech", "asteroid", "basketball", "blue", "blind", "breakfast", "binary",
                            "cosmos", "charity", "clever", "calendar", "cylinder", "domitory", "dancer", "drink", "daredevil", "dimension",
                            "europe", "endanger", "earth", "epilogue", "education", "fantasy", "flavor", "favorite", "flash", "farmer",
                            "global", "geometry", "green", "giant", "gentle", "happy", "handle", "hacker", "helicopter", "hunter",
                            "internet", "island", "important", "intelligent", "ireland", "jupiter", "jacket", "jump", "jetpack", "jungle",
                            "king", "ketchupp", "karate", "kilobyte", "kungfu", "lantern", "lucky", "little", "letter", "lonely",
                            "mecury", "mathematics", "meteorite", "multiverse", "marble", "neptune", "necktie", "normal", "number", "national",
                            "opening", "overthinking", "optimistic", "online", "oscar", "pluto", "player", "passionate", "pingpong", "pencil",
                            "quantumania", "question", "queue", "queen", "quick", "random", "rubik", "robbery", "ranking", "regular",
                            "sentimental", "sunshine", "silver", "shopping", "spiderman", "tender", "terrible", "total", "thunder", "trouble",
                            "universe", "under", "umbrella", "uniform", "uranus", "vegetable", "vitamin", "voltage", "virtual", "volume",
                            "watch", "worldwide", "wonderful", "worm", "winner", "youtube", "yoghurt", "yummy", "yard", "yoga", "zeus"};
int main()
{
    srand(time(0));
    string answer = WORD_LIST[rand() % sizeof(WORD_LIST) / sizeof(string)];
    string lines = string(answer.length(), '_');
    int wrongGuesses = 0;
    char guess;
    do {
        guess = guessLetter();
        checkGuessedLetter(guess, answer, lines, wrongGuesses);
        cout << FIGURE[wrongGuesses] << endl;
    } while (wrongGuesses < maxOfWrongGuesses && lines != answer);
    if (wrongGuesses < maxOfWrongGuesses) cout << "You win !";
    else cout << "You lose ! The secret word is " << answer;
    return 0;
}
