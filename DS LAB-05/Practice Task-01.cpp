// Practice Task-01
#include <iostream>
#include <iomanip>

using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, count, maxSize;

public:
    CircularQueue(int size = 10) {
        maxSize = size;
        arr = new int[maxSize];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (count == maxSize) {
            cout << "Queue is Full! Cannot enqueue " << val << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = val;
        count++;
        cout << "Value " << val << " inserted successfully." << endl;
    }

    void dequeue(int k) {
        if (count == 0) {
            cout << "Queue is Empty. Nothing to dequeue." << endl;
            return;
        }

        double sum = 0;
        int actualRemoved = 0;

        for (int i = 0; i < k; i++) {
            if (count > 0) {
                int val = arr[front];
                front = (front + 1) % maxSize;
                count--;
                sum += val;
                actualRemoved++;
                cout << "Removed Element: " << val << endl;
            } else {
                break;
            }
        }

        if (actualRemoved > 0) {
            cout << "Average of removed elements = " << fixed << setprecision(1) << (sum / actualRemoved) << endl;
        }
    }

    void display() {
        if (count == 0) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << "Circular Queue Elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % maxSize] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (count == 0) {
            cout << "Queue is Empty. Nothing to Peek." << endl;
            return;
        }
        cout << "Front Element: " << arr[front] << endl;
    }
};

void showMenu() {
    cout << "\n------------ Circular Queue Menu------------" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Peek" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    CircularQueue cq(10);
    int choice, val, m;
    char cont;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cq.enqueue(val);
                break;
            case 2:
                cout << "Enter number of elements to dequeue: ";
                cin >> m;
                cq.dequeue(m);
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cq.peek();
                break;
            case 5:
                cout << "Program Ended" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');

    cout << "Program Ended" << endl;
    return 0;
}
