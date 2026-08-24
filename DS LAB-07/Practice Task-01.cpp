// Practice Task-01
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int id;
    string name;
    string disease;
    Node* next;
};

class PatientStack {
private:
    Node* top;

public:
    PatientStack() {
        top = nullptr;
    }

    void push(int id, string name, string disease) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->name = name;
        newNode->disease = disease;
        newNode->next = top;
        top = newNode;
        cout << "Patient record added successfully!" << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. No patient to remove." << endl;
            return;
        }
        Node* temp = top;
        cout << "Removed patient with ID " << temp->id << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "--- Patient Records in Stack ---" << endl;
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->id << " " << temp->name << " " << temp->disease << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PatientStack s;
    int choice, id;
    string name, disease;

    while (true) {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Disease: "; getline(cin, disease);
                s.push(id, name, disease);
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
