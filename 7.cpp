Assignment No:7
Title: Personnel information system using sorting and searching for STL and vector container. 
Problem Statement: Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    string name;
    string dob; // Date of birth
    string phone;

    // Display a person's details
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone << endl;
    }
};

// Function to compare two Person objects by name for sorting
bool compareByName(const Person &a, const Person &b) {
    return a.name < b.name;
}

int main() {
    vector<Person> records;
    int choice;

    do {
        cout << "\nPersonnel Information System\n";
        cout << "1. Add Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record by Name\n";
        cout << "4. Sort Records by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Person p;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, p.name);
                cout << "Enter DOB (YYYY-MM-DD): ";
                getline(cin, p.dob);
                cout << "Enter Phone Number: ";
                getline(cin, p.phone);
                records.push_back(p);
                break;
            }
            case 2: {
                cout << "\nAll Records:\n";
                for (const auto &p : records) {
                    p.display();
                }
                break;
            }
            case 3: {
                string searchName;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, searchName);

                auto it = find_if(records.begin(), records.end(), [&](const Person &p) {
                    return p.name == searchName;
                });

                if (it != records.end()) {
                    cout << "Record found:\n";
                    it->display();
                } else {
                    cout << "Record not found.\n";
                }
                break;
            }
            case 4: {
                sort(records.begin(), records.end(), compareByName);
                cout << "Records sorted by name.\n";
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 5);

    return 0;
}
