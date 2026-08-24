// Practice Task-01
#include <iostream>

using namespace std;

struct Node {
    int id;
    Node* next;
};

class PatientList {
private:
    Node* head;
    int count;

public:
    PatientList() {
        head = nullptr;
        count = 0;
    }

    void insertAtFront(int id) {
        if (count >= 10) {
            cout << "Patient list full!" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->id = id;
        newNode->next = head;
        head = newNode;
        count++;
    }

    void insertAtEnd(int id) {
        if (count >= 10) {
            cout << "Patient list full!" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->id = id;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void insertAfter(int targetId, int newId) {
        if (count >= 10) {
            cout << "Patient list full!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->id != targetId) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Patient ID " << targetId << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->id = newId;
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }

    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        count--;
    }

    void deleteSpecific(int id) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->id == id) {
            deleteFront();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Patient ID " << id << " not found." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        count--;
    }

    void display() {
        if (head == nullptr) {
            cout << "No patients in list." << endl;
            return;
        }
        cout << "Patient IDs: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PatientList list;
    int choice, id, targetId;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Patient" << endl;
        cout << "4. Delete Front" << endl;
        cout << "5. Delete End" << endl;
        cout << "6. Delete Specific Patient" << endl;
        cout << "7. Display Patients" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8) break;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID to insert at front: ";
                cin >> id;
                list.insertAtFront(id);
                break;
            case 2:
                cout << "Enter Patient ID to insert at end: ";
                cin >> id;
                list.insertAtEnd(id);
                break;
            case 3:
                cout << "Enter patient ID after which new patient should be inserted: ";
                cin >> targetId;
                cout << "Enter new patient ID: ";
                cin >> id;
                list.insertAfter(targetId, id);
                break;
            case 4:
                list.deleteFront();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                list.deleteSpecific(id);
                break;
            case 7:
                list.display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
