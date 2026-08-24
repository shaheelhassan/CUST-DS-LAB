// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct Passenger {
    int ticketId;
    string name;
    string destination;
    string seatClass;
    int age;
    Passenger* prev;
    Passenger* next;

    Passenger(int id, string n, string d, string s, int a) {
        ticketId = id;
        name = n;
        destination = d;
        seatClass = s;
        age = a;
        prev = next = nullptr;
    }
};

class AirlineDLL {
private:
    Passenger* head;
    Passenger* tail;

public:
    AirlineDLL() {
        head = tail = nullptr;
    }

    void addAtFront(int id, string n, string d, string s, int a) {
        Passenger* newP = new Passenger(id, n, d, s, a);
        if (!head) {
            head = tail = newP;
        } else {
            newP->next = head;
            head->prev = newP;
            head = newP;
        }
        if (a > 60) cout << "Passenger added at front due to age > 60." << endl;
        else cout << "Passenger added at front successfully." << endl;
    }

    void addAtRear(int id, string n, string d, string s, int a) {
        if (a > 60) {
            addAtFront(id, n, d, s, a);
            return;
        }
        Passenger* newP = new Passenger(id, n, d, s, a);
        if (!tail) {
            head = tail = newP;
        } else {
            tail->next = newP;
            newP->prev = tail;
            tail = newP;
        }
        cout << "Passenger added at rear successfully." << endl;
    }

    void insertAfter(int targetId, int id, string n, string d, string s, int a) {
        Passenger* temp = head;
        while (temp && temp->ticketId != targetId) temp = temp->next;
        if (!temp) {
            cout << "Ticket ID " << targetId << " not found." << endl;
            return;
        }
        Passenger* newP = new Passenger(id, n, d, s, a);
        newP->next = temp->next;
        newP->prev = temp;
        if (temp->next) temp->next->prev = newP;
        else tail = newP;
        temp->next = newP;
        cout << "Passenger inserted after Ticket ID " << targetId << " successfully." << endl;
    }

    void deleteById(int id) {
        Passenger* temp = head;
        while (temp && temp->ticketId != id) temp = temp->next;
        if (!temp) {
            cout << "Passenger not found." << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Passenger " << id << " removed." << endl;
    }

    void searchByDestination(string dest) {
        Passenger* temp = head;
        bool found = false;
        cout << "Search Results for " << dest << ":" << endl;
        while (temp) {
            if (temp->destination == dest) {
                cout << "Ticket ID: " << temp->ticketId << ", Name: " << temp->name << ", Class: " << temp->seatClass << ", Age: " << temp->age << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No passengers found for destination " << dest << endl;
    }

    void display() {
        if (!head) {
            cout << "Waiting list empty." << endl;
            return;
        }
        cout << "Current Waiting List:" << endl;
        Passenger* temp = head;
        while (temp) {
            cout << "Ticket ID: " << temp->ticketId << ", Name: " << temp->name << ", Destination: " << temp->destination << ", Seat Class: " << temp->seatClass << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main() {
    AirlineDLL airline;
    int choice, id, age, target;
    string n, d, s;

    while (true) {
        cout << "\nChoose operation:\n1. Add at Front\n2. Add at Rear\n3. Insert After Ticket ID\n4. Delete by Ticket ID\n5. Search by Destination\n6. Display Waiting List\n7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
            case 1:
                cout << "Enter Ticket ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, n);
                cout << "Enter Destination: "; getline(cin, d);
                cout << "Enter Seat Class: "; getline(cin, s);
                cout << "Enter Age: "; cin >> age;
                airline.addAtFront(id, n, d, s, age);
                break;
            case 2:
                cout << "Enter Ticket ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, n);
                cout << "Enter Destination: "; getline(cin, d);
                cout << "Enter Seat Class: "; getline(cin, s);
                cout << "Enter Age: "; cin >> age;
                airline.addAtRear(id, n, d, s, age);
                break;
            case 3:
                cout << "Enter Ticket ID after which to insert: "; cin >> target;
                cout << "Enter new Ticket ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, n);
                cout << "Enter Destination: "; getline(cin, d);
                cout << "Enter Seat Class: "; getline(cin, s);
                cout << "Enter Age: "; cin >> age;
                airline.insertAfter(target, id, n, d, s, age);
                break;
            case 4:
                cout << "Enter Ticket ID to delete: "; cin >> id;
                airline.deleteById(id);
                break;
            case 5:
                cout << "Enter Destination: "; cin.ignore(); getline(cin, d);
                airline.searchByDestination(d);
                break;
            case 6: airline.display(); break;
        }
    }
    return 0;
}
