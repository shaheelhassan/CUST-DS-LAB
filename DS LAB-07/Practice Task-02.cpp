// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int orderID;
    string title;
    string name;
    Node* next;
};

class OrderQueue {
private:
    Node* front;
    Node* rear;
    int nextID;

public:
    OrderQueue() {
        front = rear = nullptr;
        nextID = 1;
    }

    void enqueue(string title, string name) {
        Node* newNode = new Node();
        newNode->orderID = nextID++;
        newNode->title = title;
        newNode->name = name;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order placed successfully! Order ID: " << newNode->orderID << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. No orders to process." << endl;
            return;
        }
        Node* temp = front;
        cout << "Processing Order ID " << temp->orderID << " (Book: " << temp->title << " for " << temp->name << ")" << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "No pending orders." << endl;
            return;
        }
        cout << "--- Pending Orders ---" << endl;
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->orderID << " " << temp->title << " " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    OrderQueue q;
    int choice;
    string title, name;

    while (true) {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Enter Book Title: "; cin.ignore(); getline(cin, title);
                cout << "Enter Customer Name: "; getline(cin, name);
                q.enqueue(title, name);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
