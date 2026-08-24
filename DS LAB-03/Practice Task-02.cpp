// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

class BracketStack {
private:
    char arr[100];
    int top;

public:
    BracketStack() {
        top = -1;
    }

    void push(char c) {
        if (top < 99) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
};

bool isBalanced(string expr) {
    BracketStack s;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            char topChar = s.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    cout << "Expression: " << expr << endl;
    if (isBalanced(expr)) {
        cout << "Result: Balanced" << endl;
    } else {
        cout << "Result: Not Balanced" << endl;
    }

    return 0;
}
