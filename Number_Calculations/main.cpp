#include <iostream>
#include <fstream>   // Required for handling the input and output files
#include <vector>    // Required for using vectors
#include <algorithm> // Required for sorting the numbers in the list

using namespace std;

int main() {

    // File Setup
    // For reading the Input File (Input.txt)
    ifstream inputFile("Input.txt");
    // For the Output File (Results.txt)
    ofstream outputFile("Results.txt");

    int numLines = 0;
    if (inputFile.is_open()) {
        // Read the very first number in the file, which tells how many lists to process
        inputFile >> numLines;
    } else {
        // Print message if there is a problem/error in opening and reading the input file
        cout << " Error opening the file. Exiting program" << endl;
        return 1; // Exit the program if there is an error
    }

    // Main loop for the program
    // This loop runs once for every List found in the input file
    for (int i = 0; i < numLines; i++) {
        int numElements = 0;
        // Read how many numbers are in the current list
        inputFile >> numElements;

        vector<double> numbers; // A vector to store the list of numbers (using a vector instead of array because its size can be modified)
        double sum = 0;

        // Read each number from the file and add it to our vector
        for (int j = 0; j < numElements; j++) {
            double num;
            inputFile >> num;
            numbers.push_back(num); // Add the number to the end of the list
            sum += num;             // Keep track of the total sum for calculating the Mean
        }

        // Print the list to both the console and the output file
        cout << "List " << i + 1 << " values: " << endl;
        outputFile << "List " << i + 1 << " values: " << endl;
        for (int j = 0; j < (int)numbers.size(); j++) {
            cout << numbers[j] << " ";
            outputFile << numbers[j] << " ";
        }
        cout << endl;
        outputFile << endl;

        // Calculations
        // Calculating the Mean (Average)
        // Divide the total sum by the number of items
        double mean = sum / numElements;

        // Calculating the Median (Middle Number)
        // Sorting the list from smallest to largest numbers
        sort(numbers.begin(), numbers.end());
        double median = 0;

        // Case 1: If the list size is Even, the median is the average of the two middle numbers
        if (numbers.size() % 2 == 0) {
            median = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2;
        }
        // Case 2: If the list size is Odd, the median is the exact middle number
        else {
            median = numbers[numbers.size() / 2];
        }

        // Finding the Mode (Most Frequent Number)
        double mode = numbers[0];
        int maxCount = 0;

        // Nested Loop: For every number (x), count how many times it appears (y)
        for (int x = 0; x < numElements; x++) {
            int numFrequency = 0;
            for (int y = 0; y < numElements; y++) {
                if (numbers[x] == numbers[y]) {
                    numFrequency++; // Finding a match
                }
            }
            // If this number appears more often than our previous "max", it becomes the new mode
            if (numFrequency > maxCount) {
                maxCount = numFrequency;
                mode = numbers[x];
            }
        }

        // Output Results
        // Display results on the console
        cout << "The Mean is " << mean << endl;
        cout << "The Median is " << median << endl;
        cout << "The Mode is " << mode << endl << endl;

        // Save results into the Output file (Results.txt)
        outputFile << "The Mean is " << mean << endl;
        outputFile << "The Median is " << median << endl;
        outputFile << "The Mode is " << mode << endl << endl;
    }

    // Close the Input and Output Files
    inputFile.close();
    outputFile.close();

    return 0;
}