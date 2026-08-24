// Practice Task-01
#include <iostream>
#include <string>

using namespace std;

class ParkingQueue {
private:
    string arr[101];
    int front, rear, count;
    int maxSize;

public:
    ParkingQueue() {
        front = 0;
        rear = -1;
        count = 0;
        maxSize = 101;
    }

    void arrive(string id) {
        if (count == maxSize) {
            cout << "Parking area is full." << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = id;
        count++;
        cout << "Vehicle " << id << " has arrived." << endl;
    }

    void depart() {
        if (count == 0) {
            cout << "Parking area is empty." << endl;
            return;
        }
        string id = arr[front];
        front = (front + 1) % maxSize;
        count--;
        cout << "Vehicle " << id << " has departed." << endl;
    }

    void display() {
        if (count == 0) {
            cout << "Parking area is empty." << endl;
            return;
        }
        cout << "Parked vehicles: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % maxSize] << (i == count - 1 ? "" : ", ");
        }
        cout << endl;
    }

    void size() {
        cout << "Total vehicles: " << count << endl;
    }
};

int main() {
    int N;
    if (!(cin >> N)) return 0;

    ParkingQueue pq;
    string cmd, id;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "ARRIVE") {
            cin >> id;
            pq.arrive(id);
        } else if (cmd == "DEPART") {
            pq.depart();
        } else if (cmd == "DISPLAY") {
            pq.display();
        } else if (cmd == "SIZE") {
            pq.size();
        }
    }

    return 0;
}
