// Practice Task-02
#include <iostream>

using namespace std;

// Function to convert case
char swapCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    } else if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Function to get lowercase version for comparison
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    if (N < 1 || N > 15) {
        cout << "Invalid size." << endl;
        return 0;
    }

    char* arr = new char[N];
    cout << "Enter characters: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    char query;
    cout << "Enter character to search: ";
    cin >> query;

    // Perform case conversion and display modified array
    char* modifiedArr = new char[N];
    cout << "Modified array: ";
    for (int i = 0; i < N; i++) {
        modifiedArr[i] = swapCase(arr[i]);
        cout << modifiedArr[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    // Search for next largest character in alphabetical order
    // Based on the sample, we search within the original input characters
    char result = 0;
    char queryLower = toLower(query);

    for (int i = 0; i < N; i++) {
        char currentLower = toLower(arr[i]);
        if (currentLower > queryLower) {
            if (result == 0 || currentLower < toLower(result)) {
                result = arr[i];
            }
        }
    }

    if (result != 0) {
        cout << "Next largest character: " << result << endl;
    } else {
        cout << "No larger character found." << endl;
    }

    // Free memory
    delete[] arr;
    delete[] modifiedArr;

    return 0;
}
