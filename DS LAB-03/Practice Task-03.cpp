// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct Artist {
    string name;
    string genre;
    int performanceTime;
};

class ConcertStack {
private:
    Artist* arr;
    int maxSize;
    int top;

public:
    ConcertStack(int size) {
        maxSize = size;
        arr = new Artist[maxSize];
        top = -1;
    }

    ~ConcertStack() {
        delete[] arr;
    }

    void addArtist() {
        if (top == maxSize - 1) {
            cout << "Concert list is full." << endl;
            return;
        }
        top++;
        cout << "Enter Artist Name: "; cin.ignore(); getline(cin, arr[top].name);
        cout << "Enter Genre: "; getline(cin, arr[top].genre);
        cout << "Enter Performance Time (mins): "; cin >> arr[top].performanceTime;
        cout << "Artist " << arr[top].name << " added to the concert list." << endl;
    }

    void nextPerformance() {
        if (top == -1) {
            cout << "No artist left to perform." << endl;
            return;
        }
        cout << "Now performing: " << arr[top].name << " (" << arr[top].genre << "), Time: " << arr[top].performanceTime << " mins" << endl;
        top--;
    }

    void showNextArtist() {
        if (top == -1) {
            cout << "No upcoming artist." << endl;
            return;
        }
        cout << "Next artist: " << arr[top].name << " (" << arr[top].genre << "), Time: " << arr[top].performanceTime << " mins" << endl;
    }

    void totalPerformanceTime() {
        int total = 0;
        for (int i = 0; i <= top; i++) {
            total += arr[i].performanceTime;
        }
        cout << "Total performance time left: " << total << " mins" << endl;
    }
};

int main() {
    int N;
    cout << "Enter concert list size: ";
    cin >> N;

    ConcertStack concert(N);
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. ADDARTIST" << endl;
        cout << "2. NEXTPERFORMANCE" << endl;
        cout << "3. SHOWNEXTARTIST" << endl;
        cout << "4. TOTALPERFORMANCETIME" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                concert.addArtist();
                break;
            case 2:
                concert.nextPerformance();
                break;
            case 3:
                concert.showNextArtist();
                break;
            case 4:
                concert.totalPerformanceTime();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
