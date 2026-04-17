#include <iostream>
#include <string>

using namespace std;

int main() {
    string primeInteger;

    // Display message at the very start of the program
    cout << "Positive Prime Integer Tester" << endl;

    // Start an infinite loop that keeps asking for numbers until the quitting condition is met
    while (true) {
        cout << "(Enter 'q' to quit) Enter an integer: ";

        // getline to read the whole line (even if it has spaces or text)
        getline(cin, primeInteger);

        // Getting rid of any leading or trailing spaces in the user input
        // First While loop for trimming the leading spaces
        int start = 0;
        while (start < primeInteger.length() && primeInteger[start] == ' ') {
            start++;
        }
        // Second While loop for trimming the trailing spaces
        int end = primeInteger.length() - 1;
        while (end >= 0 && primeInteger[end] == ' ') {
            end--;
        }

        // Extracting the number from the user input using substr() ( Extracting the trimmed string using substring)
        if (start <= end) {
            primeInteger = primeInteger.substr(start, end - start + 1);
        }
        else {
            primeInteger = " "; // Input was all spaces
            // Error message for only spaces in input
            cout << "Input cannot be empty" << endl;
        }

        // Exit Condition (If the user types 'q', break out of the while loop)
        if (primeInteger == "q") {
            break;
        }

        // Validation (Check every character to make sure it is not an invalid input)
        bool isValid = true;
        bool isNegative = false;

        // Check if the first character is a minus sign
        if (primeInteger[0] == '-') {
            isNegative = true;
            // A minus sign by itself is invalid
            if (primeInteger.length() == 1) {
                isValid = false;
            }
        }

        // Check the rest of the characters
        // If it's negative, we start checking from index 1. If positive, index 0.
        int startIndex = (isNegative) ? 1 : 0;

        for (int i = startIndex; i < primeInteger.length(); i++) {
            if (primeInteger[i] < '0' || primeInteger[i] > '9') {
                isValid = false;
                break;
            }
        }

        // If the input had garbage or was just a "-", print Invalid Input and restart the loop
        if (!isValid) {
            cout << "Invalid input." << endl;
            continue;
        }

        // Conversion (Changes the string into an integer "number")
        int num = 0;
        for (int i = startIndex; i < primeInteger.length(); i++) {
            num = num * 10 + (primeInteger[i] - '0');
        }

        // Apply the negative sign if needed
        if (isNegative) {
            num = -num;
        }

        // Prime Logic (Determine if the number is a prime number or not)
        // When the user inputs a negative integer
        if (num < 0) {
            cout << num << " is a negative integer." << endl;
            // Prime numbers must be greater than or equal to 2
        } else if (num < 2) {
            cout << num << " is not a positive prime integer." << endl;
        } else {
            // Check for any divisors between 2 and the number itself
            bool isPrime = true;
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    isPrime = false;
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

