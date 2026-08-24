// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int id;
    string role;
    int battingTime;
};

class PracticeQueue {
private:
    Player* arr;
    int front, rear, count, capacity;

public:
    PracticeQueue(int c) {
        capacity = c;
        arr = new Player[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~PracticeQueue() {
        delete[] arr;
    }

    void addPlayer(string n, int id, string r, int t) {
        if (count == capacity) {
            cout << "Practice area full. Cannot add player." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear].name = n;
        arr[rear].id = id;
        arr[rear].role = r;
        arr[rear].battingTime = t;
        count++;
        cout << "Player " << n << " with ID " << id << " added to queue." << endl;
    }

    void playNext() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        Player p = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Player " << p.name << " (Role: " << p.role << ") batted for " << p.battingTime << " minutes and left the queue." << endl;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Players in Queue:" << endl;
        for (int i = 0; i < count; i++) {
            Player p = arr[(front + i) % capacity];
            cout << (i + 1) << ". " << p.name << " (ID: " << p.id << ", Role: " << p.role << ", BattingTime: " << p.battingTime << ")" << endl;
        }
    }

    void longestPlayer() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        int maxTime = -1;
        int maxIdx = -1;
        for (int i = 0; i < count; i++) {
            int currentIdx = (front + i) % capacity;
            if (arr[currentIdx].battingTime > maxTime) {
                maxTime = arr[currentIdx].battingTime;
                maxIdx = currentIdx;
            }
        }
        cout << "Player " << arr[maxIdx].name << " has the longest batting time: " << maxTime << " minutes." << endl;
    }
};

int main() {
    int C;
    cout << "Enter capacity of practice area: ";
    cin >> C;

    PracticeQueue pq(C);
    int choice;
    string name, role;
    int id, time;

    while (true) {
        cout << "\n------ Cricket Practice Menu ------" << endl;
        cout << "1. ADD Player" << endl;
        cout << "2. PLAY Next Player" << endl;
        cout << "3. DISPLAY Queue" << endl;
        cout << "4. LONGEST_PLAYER" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Program Ended." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter Name, PlayerID, Role, BattingTime: ";
                cin >> name >> id >> role >> time;
                pq.addPlayer(name, id, role, time);
                break;
            case 2:
                pq.playNext();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                pq.longestPlayer();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
