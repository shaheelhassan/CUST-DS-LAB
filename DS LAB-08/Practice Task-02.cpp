// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

struct BookNode {
    int bookID;
    string title;
    string author;
    string borrower;
    string dueDate;
    BookNode* prev;
    BookNode* next;

    BookNode(int id, string t, string a, string b, string d) {
        bookID = id;
        title = t;
        author = a;
        borrower = b;
        dueDate = d;
        prev = next = nullptr;
    }
};

class LibraryDLL {
private:
    BookNode* head;
    BookNode* tail;

public:
    LibraryDLL() {
        head = tail = nullptr;
    }

    void insertAtRear(int id, string t, string a, string b, string d) {
        BookNode* newNode = new BookNode(id, t, a, b, d);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Book inserted at rear successfully." << endl;
    }

    void insertAfter(int targetId, int id, string t, string a, string b, string d) {
        BookNode* temp = head;
        while (temp && temp->bookID != targetId) temp = temp->next;
        if (!temp) {
            cout << "Book ID " << targetId << " not found." << endl;
            return;
        }
        BookNode* newNode = new BookNode(id, t, a, b, d);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        else tail = newNode;
        temp->next = newNode;
        cout << "Book inserted after Book ID " << targetId << " successfully." << endl;
    }

    void deleteFromFront() {
        if (!head) {
            cout << "No books currently issued." << endl;
            return;
        }
        BookNode* temp = head;
        cout << "Book returned from front:" << endl;
        cout << "[" << temp->bookID << ", " << temp->title << ", " << temp->author << ", Borrower: " << temp->borrower << ", Due: " << temp->dueDate << "]" << endl;
        
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void searchByBorrower(string name) {
        if (!head) {
            cout << "No records." << endl;
            return;
        }
        cout << "Books borrowed by '" << name << "':" << endl;
        BookNode* temp = head;
        bool found = false;
        while (temp) {
            if (temp->borrower == name) {
                cout << "[" << temp->bookID << ", " << temp->title << ", " << temp->author << ", Due: " << temp->dueDate << "]" << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No books found for borrower: " << name << endl;
    }

    void countByAuthor(string author) {
        int count = 0;
        BookNode* temp = head;
        while (temp) {
            if (temp->author == author) count++;
            temp = temp->next;
        }
        cout << "Books issued by Author '" << author << "': " << count << endl;
    }
};

int main() {
    LibraryDLL lib;
    int choice, id, target;
    string t, a, b, d;

    while (true) {
        cout << "\n1. Insert at Rear\n2. Insert After Specific Book ID\n3. Delete from Front\n4. Search by Borrower Name\n5. Count Books by Author\n6. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Title: "; getline(cin, t);
                cout << "Enter Author: "; getline(cin, a);
                cout << "Enter Borrower: "; getline(cin, b);
                cout << "Enter Due Date: "; getline(cin, d);
                lib.insertAtRear(id, t, a, b, d);
                break;
            case 2:
                cout << "Enter Book ID after which to insert: "; cin >> target;
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Title: "; getline(cin, t);
                cout << "Enter Author: "; getline(cin, a);
                cout << "Enter Borrower: "; getline(cin, b);
                cout << "Enter Due Date: "; getline(cin, d);
                lib.insertAfter(target, id, t, a, b, d);
                break;
            case 3: lib.deleteFromFront(); break;
            case 4:
                cout << "Enter Borrower Name: "; cin.ignore(); getline(cin, b);
                lib.searchByBorrower(b);
                break;
            case 5:
                cout << "Enter Author Name: "; cin.ignore(); getline(cin, a);
                lib.countByAuthor(a);
                break;
        }
    }
    return 0;
}
