// Practice Task-03
#include <iostream>

using namespace std;

class BankQueue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;
    int count;

public:
    BankQueue(int size = 5) {
        capacity = size;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~BankQueue() {
        delete[] queue;
    }

    void enqueue(int id) {
        if (count == capacity) {
            cout << "Queue is full. Cannot add customer " << id << "." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = id;
        count++;
        cout << "Customer ID " << id << " added to the queue." << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty. No customer to serve." << endl;
            return;
        }
        int id = queue[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Serving Customer ID: " << id << endl;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current customers in queue: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Next customer to be served: " << queue[front] << endl;
    }
};

int main() {
    BankQueue bq(10);
    int choice, id;

    while (true) {
        cout << "\n--- Bank Teller Counter Menu ---" << endl;
        cout << "1. Enqueue (Add Customer)" << endl;
        cout << "2. Dequeue (Serve Customer)" << endl;
        cout << "3. Display All Waiting" << endl;
        cout << "4. Peek Next Customer" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting system..." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                bq.enqueue(id);
                break;
            case 2:
                bq.dequeue();
                break;
            case 3:
                bq.display();
                break;
            case 4:
                bq.peek();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
