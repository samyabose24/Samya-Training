#include <iostream>
#include <string>

using namespace std;

int main() {
    string primeInteger;

    // Display message at the very start of the program
    cout << "Positive Prime Integer Tester" << endl;

    // Start an infinite loop that keeps asking for numbers until the quitting condition is met
    while (true) {
        cout << "(Enter 'q' to quit) Enter a positive integer: ";

        // getline to read the whole line (even if it has spaces or text)
        // This prevents the program from looping forever if the user types a sentence (multiple words)
        getline(cin, primeInteger);

        // Exit Condition (If the user types 'q', break out of the while loop)
        if (primeInteger == "q") {
            break;
        }

        // Checks if the user just presses Enter (has entered nothing
        /*if (primeInteger.length() == 0) {
            continue;
        }*/

        // Validation (Check every character to make sure it is a digit)
        bool isValid = true;
        for (int i = 0; i < primeInteger.length(); i++) {
            // If the character is not between '0' and '9' and is negative, it is invalid
            if (primeInteger[i] < '0' || primeInteger[i] > '9' ||) {
                isValid = false;
                break; // Stop checking as soon as we find one bad character
            }
        }

        // If the input was invalid, print invalid input message and restart the loop
        if (!isValid) {
            cout << "Invalid input. Please enter a positive integer" << endl;
            continue;
        }

        // Conversion (Changes the string into an integer "number")
        int num = 0;
        for (int i = 0; i < primeInteger.length(); i++) {
            num = num * 10 + (primeInteger[i] - '0');
        }

        // Prime Logic (Determine if the number is a prime number or not)
        // Prime numbers must be greater than or equal to 2
        if (num < 2) {
            cout << num << " is not a positive prime integer." << endl;
        } else {
            bool isPrime = true;
            // Check for any divisors between 2 and the number itself
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    isPrime = false; // Found a factor, so it's not prime
                    break;
                }
            }

            // Report the result to the user
            if (isPrime) {
                cout << num << " is a positive prime integer!" << endl;
            } else {
                cout << num << " is not a positive prime integer." << endl;
            }
        }
    }

    // Quit message (Runs only after the loop is broken by entering 'q')
    cout << "Quitting the program..... Goodbye!" << endl;

    return 0;
}