// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string rollNo;
    string name;
    string book;
    Node* next;
};

class RequestStack {
private:
    Node* top;

public:
    RequestStack() {
        top = nullptr;
    }

    void push(string roll, string name, string book) {
        Node* newNode = new Node();
        newNode->rollNo = roll;
        newNode->name = name;
        newNode->book = book;
        newNode->next = top;
        top = newNode;
        cout << "Request added successfully!" << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "No requests to process." << endl;
            return;
        }
        Node* temp = top;
        cout << "Processed request of " << temp->name << " for " << temp->book << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "No current requests." << endl;
            return;
        }
        cout << "--- Current Requests ---" << endl;
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->rollNo << " " << temp->name << " " << temp->book << endl;
            temp = temp->next;
        }
    }
};

int main() {
    RequestStack s;
    int choice;
    string roll, name, book;

    while (true) {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: "; cin >> roll;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Book Requested: "; getline(cin, book);
                s.push(roll, name, book);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
