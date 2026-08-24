// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct BusNode {
    string busNumber;
    string route;
    int capacity;
    int fare;
    BusNode* next;
};

class BusManagement {
private:
    BusNode* head;

public:
    BusManagement() {
        head = nullptr;
    }

    void addBus(string num, string route, int cap, int fare) {
        BusNode* newNode = new BusNode();
        newNode->busNumber = num;
        newNode->route = route;
        newNode->capacity = cap;
        newNode->fare = fare;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            BusNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Bus " << num << " added successfully." << endl;
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "No bus records found." << endl;
            return;
        }
        cout << "Current Bus Records:" << endl;
        BusNode* temp = head;
        while (temp != nullptr) {
            cout << "Bus No: " << temp->busNumber << " | Route: " << temp->route 
                 << " | Capacity: " << temp->capacity << " | Fare: " << temp->fare << endl;
            temp = temp->next;
        }
    }

    void deleteHighFare() {
        if (head == nullptr) return;

        while (head != nullptr && head->fare > 200) {
            BusNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr) {
            cout << "Buses with Fare > 200 removed successfully." << endl;
            return;
        }

        BusNode* current = head;
        while (current->next != nullptr) {
            if (current->next->fare > 200) {
                BusNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
        cout << "Buses with Fare > 200 removed successfully." << endl;
    }

    void searchBus(string num) {
        BusNode* temp = head;
        while (temp != nullptr) {
            if (temp->busNumber == num) {
                cout << "Search Result:" << endl;
                cout << "Bus No: " << temp->busNumber << " | Route: " << temp->route 
                     << " | Capacity: " << temp->capacity << " | Fare: " << temp->fare << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Search Result:\nBus not found." << endl;
    }
};

int main() {
    BusManagement bm;
    int choice;
    string num, route;
    int cap, fare;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Bus" << endl;
        cout << "2. Display All Buses" << endl;
        cout << "3. Delete Buses with Fare > 200" << endl;
        cout << "4. Search Bus by Number" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                cout << "Enter Bus Number: "; cin >> num;
                cout << "Enter Route: "; cin.ignore(); getline(cin, route);
                cout << "Enter Capacity: "; cin >> cap;
                cout << "Enter Fare: "; cin >> fare;
                bm.addBus(num, route, cap, fare);
                break;
            case 2:
                bm.displayAll();
                break;
            case 3:
                bm.deleteHighFare();
                break;
            case 4:
                cout << "Enter Bus Number to search: "; cin >> num;
                bm.searchBus(num);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
