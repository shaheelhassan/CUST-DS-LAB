// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

struct Candidate {
    string name;
    string qualification;
    int experience;
    int marks;
};

class PriorityQueue {
private:
    Candidate queue[20];
    int size;

    bool isHigherPriority(Candidate a, Candidate b) {
        bool a_meets = (a.qualification == "MS" && a.experience > 3);
        bool b_meets = (b.qualification == "MS" && b.experience > 3);

        if (a_meets && !b_meets) return true;
        if (!a_meets && b_meets) return false;

        // If both meet criteria or both don't, compare marks
        return a.marks > b.marks;
    }

public:
    PriorityQueue() { size = 0; }

    void insert(string n, string q, int e, int m) {
        if (size >= 20) {
            cout << "Queue is full!" << endl;
            return;
        }

        Candidate newC = {n, q, e, m};
        int pos = size;

        // Find position to maintain priority order
        for (int i = 0; i < size; i++) {
            if (isHigherPriority(newC, queue[i])) {
                pos = i;
                break;
            }
        }

        // Shift elements
        for (int i = size; i > pos; i--) {
            queue[i] = queue[i - 1];
        }

        queue[pos] = newC;
        size++;
        cout << "Candidate " << n << " inserted successfully." << endl;
    }

    void callForInterview() {
        if (size == 0) {
            cout << "No candidates in the queue." << endl;
            return;
        }

        Candidate c = queue[0];
        cout << "Candidate called for interview:" << endl;
        cout << "Name: " << c.name << endl;
        cout << "Qualification: " << c.qualification << endl;
        cout << "Experience: " << c.experience << " years" << endl;
        cout << "Marks: " << c.marks << endl;

        // Shift elements left
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "No candidates in the queue." << endl;
            return;
        }
        cout << "Current Candidates in Queue:" << endl;
        for (int i = 0; i < size; i++) {
            cout << (i + 1) << ". " << queue[i].name << " | Qualification: " << queue[i].qualification 
                 << " | Experience: " << queue[i].experience << " years | Marks: " << queue[i].marks << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, exp, marks;
    string name, qual;
    char cont;

    do {
        cout << "\n------------ Candidate Selection Menu------------" << endl;
        cout << "1. Insert Candidate" << endl;
        cout << "2. Call for Interview" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Candidate Name: "; cin >> name;
                cout << "Enter Qualification (BS/MS): "; cin >> qual;
                cout << "Enter Years of Experience: "; cin >> exp;
                cout << "Enter Written Test Marks (out of 50): "; cin >> marks;
                pq.insert(name, qual, exp, marks);
                break;
            case 2:
                pq.callForInterview();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Program Ended." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');

    cout << "Program Ended." << endl;
    return 0;
}
