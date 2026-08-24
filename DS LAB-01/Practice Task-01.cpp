// Practice Task-01
#include <iostream>

using namespace std;

int main() {
    // Part (a)
    // Create two static integer arrays (size 5)
    int staticArray1[5];
    int staticArray2[5];

    // Take input for first static array
    cout << "Enter 5 elements of first array: ";
    for (int i = 0; i < 5; i++) {
        cin >> staticArray1[i];
    }

    // Take input for second static array
    cout << "Enter 5 elements of second array: ";
    for (int i = 0; i < 5; i++) {
        cin >> staticArray2[i];
    }

    // Create a dynamic array large enough to store both (size 10)
    int* dynamicArray = new int[10];

    // Copy elements from first static array
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = staticArray1[i];
    }

    // Copy elements from second static array
    for (int i = 0; i < 5; i++) {
        dynamicArray[i + 5] = staticArray2[i];
    }

    // Display the merged result
    cout << "Merged dynamic array elements: ";
    for (int i = 0; i < 10; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Free dynamic memory
    delete[] dynamicArray;

    return 0;
}
