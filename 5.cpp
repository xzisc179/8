Assignment No: 5 
Title: Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array. 
Problem Statement: Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array
#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intSize, floatSize;

    // User input for integer array
    cout << "Enter the number of integers: ";
    cin >> intSize;
    int intArr[intSize];
    cout << "Enter the integers: ";
    for (int i = 0; i < intSize; i++) {
        cin >> intArr[i];
    }

    // User input for float array
    cout << "Enter the number of floats: ";
    cin >> floatSize;
    float floatArr[floatSize];
    cout << "Enter the floats: ";
    for (int i = 0; i < floatSize; i++) {
        cin >> floatArr[i];
    }

    // Display original arrays
    cout << "Original integer array: ";
    displayArray(intArr, intSize);
    cout << "Original float array: ";
    displayArray(floatArr, floatSize);

    // Sorting the integer array
    selectionSort(intArr, intSize);
    cout << "Sorted integer array: ";
    displayArray(intArr, intSize);

    // Sorting the float array
    selectionSort(floatArr, floatSize);
    cout << "Sorted float array: ";
    displayArray(floatArr, floatSize);

    return 0;
}
