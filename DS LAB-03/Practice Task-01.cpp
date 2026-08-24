// Practice Task-01
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    T arr[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 19;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Error: Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Value " << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow! Cannot pop from empty stack." << endl;
            return;
        }
        cout << "Value " << arr[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    int size() {
        return top + 1;
    }

    void clear() {
        top = -1;
        cout << "Stack cleared." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

template <typename T>
void handleStack(Stack<T>& s) {
    string cmd;
    T val;
    while (true) {
        cout << "\nEnter command (PUSH, POP, PEEK, SIZE, CLEAR, DISPLAY, EXIT): ";
        cin >> cmd;

        if (cmd == "PUSH") {
            cin >> val;
            s.push(val);
        } else if (cmd == "POP") {
            s.pop();
        } else if (cmd == "PEEK") {
            s.peek();
        } else if (cmd == "SIZE") {
            cout << "Current stack size: " << s.size() << endl;
        } else if (cmd == "CLEAR") {
            s.clear();
        } else if (cmd == "DISPLAY") {
            s.display();
        } else if (cmd == "EXIT") {
            cout << "Returning to main menu..." << endl;
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
        if (cmd != "EXIT" && cmd != "DISPLAY" && cmd != "SIZE") {
             s.display();
        }
    }
}

int main() {
    int choice;
    Stack<int> intStack;
    Stack<double> doubleStack;

    while (true) {
        cout << "\nChoose Stack Type:" << endl;
        cout << "1. Integer Stack" << endl;
        cout << "2. Double Stack" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "--- Working with Integer Stack ---" << endl;
            handleStack(intStack);
        } else if (choice == 2) {
            cout << "--- Working with Double Stack ---" << endl;
            handleStack(doubleStack);
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
