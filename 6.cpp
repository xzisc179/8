6]Title: File handing 
Problem Statement: Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open file for writing
    fstream fs;
    fs.open("file.txt", ios::out);

    if (!fs) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;  // Exit the program with an error code
    }

    // Write data to the file
    fs << "Hello Everyone." << endl;
    fs << "How are you all?" << endl;

    fs.close();  // Close the file after writing

    // Open file for reading
    fs.open("file.txt", ios::in);
    if (!fs) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;  // Exit the program with an error code
    }

    // Read data from the file and display it
    string line;
    while (getline(fs, line)) {
        cout << line << endl;
    }

    fs.close();  // Close the file after reading
    return 0;
}
