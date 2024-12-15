Assignment No:8
Title: To use map associative container.
Problem Statement: Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> state_population;
    state_population["Maharashtra"] = 123144223;
    state_population["Uttar Pradesh"] = 237882725;
    state_population["Bihar"] = 124799926;
    state_population["West Bengal"] = 100615330;
    state_population["Madhya Pradesh"] = 85358965;

    string state;
    cout << "Enter the name of the state: ";
    getline(cin, state);

    auto it = state_population.find(state);
    if (it != state_population.end()) {
        cout << "The population of " << state << " is " << it->second << "." << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;
}
