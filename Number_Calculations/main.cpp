#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // Setting up the Files
    ifstream inputFile("Input.txt");
    ofstream outputFile("Results.txt");

    int numLines = 0;
    if (inputFile.is_open()) {
        inputFile >> numLines;
    }
    else {
        cout << "Error opening the File" << endl;
    }

    // Main loop
    for ( int i = 0; i < numLines; i++ ) {
        int numElements;
        inputFile >> numElements;

        vector <double> numbers;
        double sum = 0;

        //Read Numbers
        for ( int j = 0; j < numElements; j++ ) {
            double num;
            inputFile >> num;
            numbers.push_back(num);
            sum += num;
        }

        // Print the values of the list
        cout << "List " << i + 1 << " values: " << endl;
        outputFile << "List " << i + 1 << " values: " << endl;
        for (int j = 0; j < numbers.size(); j++) {
            cout << numbers[j] << " " << endl;
            outputFile << numbers[j] << " " << endl;
        }

        // CALCULATIONS
        // Calculating the Mean
        double mean = sum / numElements;

        // Calculating the Median
        // Sorting the values
        sort(numbers.begin(), numbers.end());
        double median = 0;

        // Case 1: For Even Sized List
        if ( numbers.size() % 2 == 0) {
            median = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2;
        }
        // Case 2: For Odd Sized List
        else {
            median = numbers[numbers.size() / 2];
        }

        // Finding the Mode
        double mode = numbers[0];
        int maxCount = 0;

        // For loop to find the Mode
        for ( int x = 0; x < numElements; x++ ) {
            int numFrequency = 0;
            for ( int y = 0; y < numElements; y++ ) {
                if (numbers[x] == numbers[y]) {
                    numFrequency++;
                }
            }
            if (numFrequency > maxCount) {
                maxCount = numFrequency;
                mode = numbers[x];
            }
        }

        // Print Output to Screen
        cout << "The Mean is " << mean << endl;
        cout << "The Median is " << median << endl;
        cout << "The Mode is " << mode << endl;

        // Print Output to File
        outputFile << "The Mean is " << mean << endl;
        outputFile << "The Median is " << median << endl;
        outputFile << "The Mode is " << mode << endl;
    }

    // Closing the Input and Output Files
    inputFile.close();
    outputFile.close();

    return 0;
}