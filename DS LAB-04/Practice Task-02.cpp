// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

struct Customer {
    string name;
    int id;
    int bill;
};

class CheckoutQueue {
private:
    Customer* arr;
    int front, rear, count, maxSize;
    int servedCount;

public:
    CheckoutQueue(int size) {
        maxSize = size;
        arr = new Customer[maxSize];
        front = 0;
        rear = -1;
        count = 0;
        servedCount = 0;
    }

    ~CheckoutQueue() {
        delete[] arr;
    }

    void addCustomer(string n, int id, int b) {
        if (count == maxSize) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear].name = n;
        arr[rear].id = id;
        arr[rear].bill = b;
        count++;
        cout << "Customer " << n << " with ID " << id << " and Bill " << b << " added to queue." << endl;
    }

    void serveCustomer() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        Customer c = arr[front];
        front = (front + 1) % maxSize;
        count--;
        servedCount++;
        cout << "Customer " << c.name << " with ID " << c.id << " has been served." << endl;
    }

    void displayServed() {
        cout << "Total customers served: " << servedCount << endl;
    }

    void timeRemaining() {
        cout << "Total time required: " << (count * 5) << " minutes" << endl;
    }

    void displayQueue() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue:" << endl;
        for (int i = 0; i < count; i++) {
            Customer c = arr[(front + i) % maxSize];
            cout << c.name << " (ID: " << c.id << ", Bill: " << c.bill << ")" << endl;
        }
    }
};

int main() {
    int S;
    cout << "Enter size of queue: ";
    cin >> S;

    CheckoutQueue q(S);
    int choice;
    string name;
    int id, bill;

    while (true) {
        cout << "\n------ MENU ------" << endl;
        cout << "1. ADDCustomer" << endl;
        cout << "2. DELETE Customer" << endl;
        cout << "3. SERVED Customers" << endl;
        cout << "4. TIME for Remaining" << endl;
        cout << "5. DISPLAY Queue" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1:
                cout << "Enter Name, Customer_ID, Bill: ";
                cin >> name >> id >> bill;
                q.addCustomer(name, id, bill);
                break;
            case 2:
                q.serveCustomer();
                break;
            case 3:
                q.displayServed();
                break;
            case 4:
                q.timeRemaining();
                break;
            case 5:
                q.displayQueue();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
