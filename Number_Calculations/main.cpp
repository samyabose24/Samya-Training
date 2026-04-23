#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Functions for calculating the mean, median and mode
// Function to calculate the mean
double getMean(vector<double> numbers) {
    double sum = 0;
    for (double n : numbers) sum += n;
    return sum / numbers.size(); //
}

// Function to find the Median
double getMedian(vector<double> numbers) {
    sort(numbers.begin(), numbers.end());
    int size = numbers.size();
    // Case 1: If the list size is even
    if (size % 2 == 0) {
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2;
    }
    // Case 2: If the list size is odd
    else return numbers[size / 2];
}

// Function to find the mode
double getMode(vector<double> numbers) {
    double mode = numbers[0];
    int maxCount = 0;

    // Nested Loop: For every number (x), count how many times it appears (y)
    for (int x = 0; x < numbers.size(); x++) {
        int count = 0;
        for (int y = 0; y < numbers.size(); y++) {
            if (numbers[x] == numbers[y]) count++; // Finding a match
        }
        // If this number appears more often than our previous "max", it becomes the new mode
        if (count > maxCount) {
            maxCount = count;
            mode = numbers[x];
        }
    }
    return mode;
}

// Main
int main() {
    // File Setup
    // For reading the Input File
    ifstream inputFile("Input.txt");
    // For the Output File
    ofstream outputFile("Results.txt");

    int numLines = 0;
    if (inputFile.is_open()) {
        inputFile >> numLines; // Reads the number at the very top of the list, which tells how many lists to process
    } else {
        // Print message if there is a problem/error in opening and reading the input file
        cout << " Error opening file. Exiting program..." << endl;
        return 1; // Exit the program if there is an error
    }

    for (int i = 0; i < numLines; i++) {
        vector<double> numbers; // Vector to store the list of numbers
        double val;

        // Reads numbers one by one until it hits the end of the line
        string line;
        getline(inputFile, line); // move to next line after numLines

        for (int i = 0; i < numLines; i++) {
            vector<double> numbers;

            getline(inputFile, line); // read full line

            stringstream ss(line);
            double val;

            // This automatically reads numbers separated by spaces
            while (ss >> val) {
                numbers.push_back(val);
            }

            // Print numbers in the list to both the console and the output file
            cout << "List " << i + 1 << " values: " << endl;
            outputFile << "List " << i + 1 << " values: " << endl;
            for (int j = 0; j < numbers.size(); j++) {
                cout << numbers[j] << " ";
                outputFile << numbers[j] << " ";
            }


            // Output results
            // Display results on the console
            cout << "\nThe Mean is " << getMean(numbers) << endl;
            cout << "The Median is " << getMedian(numbers) << endl;
            cout << "The Mode is " << getMode(numbers) << endl << endl;

            // Save Results to the Output File (Results.txt)
            outputFile << "\nThe Mean is " << getMean(numbers) << endl;
            outputFile << "The Median is " << getMedian(numbers) << endl;
            outputFile << "The Mode is " << getMode(numbers) << endl << endl;
        }

        // Close the input and output files
        inputFile.close();
        outputFile.close();

        return 0;
    }
}