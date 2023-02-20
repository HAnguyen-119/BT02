#include <bits/stdc++.h>
using namespace std;
int chosenNumber()
{
    return rand()%100 + 1;
}
int guessNumber()
{
    int number;
    cin >> number;
    while (number < 1 || number > 100) {
        cout << "The number must be in range 1 - 100, try again : ";
        cin >> number;
    }
    return number;

}
void checkGuessedNumber(int answer, int guessedNumber)
{
    if (guessedNumber > 0 && guessedNumber <= 100){
        if (guessedNumber < answer) cout << "Too small !" << endl;
        else if (guessedNumber > answer) cout << "Too big !" << endl;
        else cout << "You win !" << endl;
    }
}
int main()
{
    srand(time(0));
    int answer = chosenNumber();
    int guess;
    do {
        cout << "The number you guess : ";
        guess = guessNumber();
        checkGuessedNumber(answer, guess);
    } while (guess != answer);
    return 0;
}

