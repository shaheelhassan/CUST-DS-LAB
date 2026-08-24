// Practice Task-02
#include <iostream>

using namespace std;

struct Node {
    int productId;
    Node* next;
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    void insert(int id) {
        Node* newNode = new Node();
        newNode->productId = id;
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
        cout << "Product " << id << " added to cart." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Products in Cart: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->productId << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeDuplicates() {
        if (head == nullptr) return;

        Node* current = head;
        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (runner->next->productId == current->productId) {
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
        cout << "Duplicates removed successfully." << endl;
    }

    void countProducts() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total Products in Cart: " << count << endl;
    }
};

int main() {
    ShoppingCart cart;
    int choice, id;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Remove Duplicates" << endl;
        cout << "4. Count Products" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                cout << "Enter Product ID to insert: ";
                cin >> id;
                cart.insert(id);
                break;
            case 2:
                cart.display();
                break;
            case 3:
                cart.removeDuplicates();
                break;
            case 4:
                cart.countProducts();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
