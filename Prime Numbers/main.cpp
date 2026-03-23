#include <iostream>

using namespace std;

int main() {
	double inputVal;
	int num;

	cout << "Positive Prime Integer Tester Game" << endl;

	while (true) {
		cout << "(Enter 0 to quit) Enter an integer: ";

		// Check if the input is text
		if (!(cin >> inputVal)) {
			cin.clear();
			cin.ignore(1000, '\n'); // Skip the text characters
			cout << "Invalid input." << endl;
			continue;
		}

		// Check if it was a decimal
		num = (int)inputVal;
		if (inputVal != (double)num) {
			cout << "Invalid input." << endl;
			continue;
		}

		// Exit condition
		if (num == 0) {
			break; // Break the loop
		}

		// Checking for Prime Number
		if (num < 2) {
			cout << "Not a positive prime integer." << endl;
		} else {
			bool isPrime = true;
			for (int i = 2; i < num; i++) {
				if (num % i == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) {
				cout << num << " is a positive prime integer!"  << endl;
			} else {
				cout << num << " is not a positive prime integer." << endl;
			}
		}
	}

	// Quit Message
	cout << "Thank you for playing. Goodbye!" << endl;

	return 0;
}