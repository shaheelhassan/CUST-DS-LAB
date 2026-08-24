// Practice Task-01
#include <iostream>
#include <string>

using namespace std;

class Patient {
public:
    int id;
    string name;
    string disease;
    string city;
    int age;
    Patient* prev;
    Patient* next;

    Patient(int id, string n, string d, string c, int a) {
        this->id = id;
        this->name = n;
        this->disease = d;
        this->city = c;
        this->age = a;
        prev = next = nullptr;
    }
};

class HospitalDLL {
private:
    Patient* head;
    Patient* tail;

public:
    HospitalDLL() {
        head = tail = nullptr;
    }

    void insertAtFront(int id, string n, string d, string c, int a) {
        Patient* newP = new Patient(id, n, d, c, a);
        if (!head) {
            head = tail = newP;
        } else {
            newP->next = head;
            head->prev = newP;
            head = newP;
        }
        cout << "Patient inserted successfully." << endl;
    }

    void insertAtEnd(int id, string n, string d, string c, int a) {
        Patient* newP = new Patient(id, n, d, c, a);
        if (!tail) {
            head = tail = newP;
        } else {
            tail->next = newP;
            newP->prev = tail;
            tail = newP;
        }
        cout << "Patient inserted successfully." << endl;
    }

    void insertAfter(int targetId, int id, string n, string d, string c, int a) {
        Patient* temp = head;
        while (temp && temp->id != targetId) temp = temp->next;
        if (!temp) {
            cout << "Patient ID " << targetId << " not found." << endl;
            return;
        }
        Patient* newP = new Patient(id, n, d, c, a);
        newP->next = temp->next;
        newP->prev = temp;
        if (temp->next) temp->next->prev = newP;
        else tail = newP;
        temp->next = newP;
        cout << "Patient inserted successfully." << endl;
    }

    void deleteFront() {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }
        Patient* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        cout << "Patient deleted successfully." << endl;
    }

    void deleteEnd() {
        if (!tail) {
            cout << "List empty." << endl;
            return;
        }
        Patient* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        cout << "Patient deleted successfully." << endl;
    }

    void deleteSpecific(int id) {
        Patient* temp = head;
        while (temp && temp->id != id) temp = temp->next;
        if (!temp) {
            cout << "Not found." << endl;
            return;
        }
        if (temp == head) deleteFront();
        else if (temp == tail) deleteEnd();
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            cout << "Patient deleted successfully." << endl;
        }
    }

    void display() {
        if (!head) {
            cout << "No patients." << endl;
            return;
        }
        Patient* temp = head;
        while (temp) {
            cout << temp->id << " " << temp->name << " " << temp->disease << " " << temp->city << " " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main() {
    HospitalDLL h;
    int choice, id, age, target;
    string n, d, c;

    while (true) {
        cout << "\nMenu:\n1. Insert at Front\n2. Insert at End\n3. Insert After Patient\n4. Delete Front\n5. Delete End\n6. Delete Specific Patient\n7. Display All Patients\n8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 8) break;

        switch (choice) {
            case 1:
                cout << "Enter Patient (ID Name Disease City Age): ";
                cin >> id >> n >> d >> c >> age;
                h.insertAtFront(id, n, d, c, age);
                break;
            case 2:
                cout << "Enter Patient (ID Name Disease City Age): ";
                cin >> id >> n >> d >> c >> age;
                h.insertAtEnd(id, n, d, c, age);
                break;
            case 3:
                cout << "Enter Patient ID after which to insert: "; cin >> target;
                cout << "Enter Patient (ID Name Disease City Age): ";
                cin >> id >> n >> d >> c >> age;
                h.insertAfter(target, id, n, d, c, age);
                break;
            case 4: h.deleteFront(); break;
            case 5: h.deleteEnd(); break;
            case 6:
                cout << "Enter ID: "; cin >> target;
                h.deleteSpecific(target);
                break;
            case 7: h.display(); break;
        }
    }
    return 0;
}
