// Practice Task-01
#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    float price;
    int book_id;
};

class LibraryList {
private:
    Book books[20];
    int size;

public:
    LibraryList() {
        size = 0;
    }

    // 1. Sequential insert based on Book_id (maintained order)
    void insertByID(string title, string author, float price, int id) {
        if (size >= 20) {
            cout << "List is full." << endl;
            return;
        }

        int pos = size;
        for (int i = 0; i < size; i++) {
            if (books[i].book_id > id) {
                pos = i;
                break;
            }
        }

        // Shift elements to the right
        for (int i = size; i > pos; i--) {
            books[i] = books[i - 1];
        }

        books[pos].title = title;
        books[pos].author = author;
        books[pos].price = price;
        books[pos].book_id = id;
        size++;
        cout << "Book inserted successfully at sorted position." << endl;
    }

    // 2. Sequential delete based on Book_id
    void deleteByID(int id) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (books[i].book_id == id) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Book ID not found." << endl;
            return;
        }

        // Shift elements to the left
        for (int i = pos; i < size - 1; i++) {
            books[i] = books[i + 1];
        }
        size--;
        cout << "Book deleted successfully." << endl;
    }

    // 3. Insert value at specific index
    void insertAtIndex(int index, string title, string author, float price, int id) {
        if (size >= 20) {
            cout << "List is full." << endl;
            return;
        }
        if (index < 0 || index > size) {
            cout << "Invalid index." << endl;
            return;
        }

        // Shift elements right
        for (int i = size; i > index; i--) {
            books[i] = books[i - 1];
        }

        books[index].title = title;
        books[index].author = author;
        books[index].price = price;
        books[index].book_id = id;
        size++;
        cout << "Book inserted at index " << index << "." << endl;
    }

    // 4. Delete value at specific index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }

        // Shift elements left
        for (int i = index; i < size - 1; i++) {
            books[i] = books[i + 1];
        }
        size--;
        cout << "Book deleted at index " << index << "." << endl;
    }

    // 5. Show all values
    void showAll() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Library Records:" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " | ID: " << books[i].book_id << " | Title: " << books[i].title 
                 << " | Author: " << books[i].author << " | Price: " << books[i].price << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }

    int getSize() { return size; }
};

int main() {
    LibraryList lib;
    int choice, id, index;
    string title, author;
    float price;

    // Pre-populating some data to show functionality or just start empty
    // The user asked for "at least 10 books", let's provide a way to add them.

    while (true) {
        cout << "\nLibrary Management Menu:" << endl;
        cout << "1. Sequential Insert (by ID)" << endl;
        cout << "2. Sequential Delete (by ID)" << endl;
        cout << "3. Insert at Specific Index" << endl;
        cout << "4. Delete at Specific Index" << endl;
        cout << "5. Show All Values" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1:
                cout << "Enter Title: "; cin.ignore(); getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Price: "; cin >> price;
                cout << "Enter Book ID: "; cin >> id;
                lib.insertByID(title, author, price, id);
                break;
            case 2:
                cout << "Enter Book ID to delete: "; cin >> id;
                lib.deleteByID(id);
                break;
            case 3:
                cout << "Enter Index: "; cin >> index;
                cout << "Enter Title: "; cin.ignore(); getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Price: "; cin >> price;
                cout << "Enter Book ID: "; cin >> id;
                lib.insertAtIndex(index, title, author, price, id);
                break;
            case 4:
                cout << "Enter Index to delete: "; cin >> index;
                lib.deleteAtIndex(index);
                break;
            case 5:
                lib.showAll();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
