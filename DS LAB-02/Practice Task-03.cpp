// Practice Task-03
#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int id;
    int age;
    int score;
};

class PlayerManager {
private:
    Player list[100];
    int size;

public:
    PlayerManager() { size = 0; }

    void insert(string n, int id, int a, int s) {
        if (size >= 100) return;

        // Find position to maintain sorted order by ID
        int pos = size;
        for (int i = 0; i < size; i++) {
            if (list[i].id > id) {
                pos = i;
                break;
            }
        }

        // Shift elements
        for (int i = size; i > pos; i--) {
            list[i] = list[i - 1];
        }

        list[pos].name = n;
        list[pos].id = id;
        list[pos].age = a;
        list[pos].score = s;
        size++;
    }

    void remove(int id) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (list[i].id == id) {
                pos = i;
                break;
            }
        }

        if (pos == -1) return;

        for (int i = pos; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
    }

    void updateScore(int id, int newScore) {
        for (int i = 0; i < size; i++) {
            if (list[i].id == id) {
                list[i].score = newScore;
                return;
            }
        }
    }

    void displayTop3() {
        if (size == 0) return;

        // Create a copy to sort by score without messing up alphabetical/ID order
        Player sorted[100];
        for (int i = 0; i < size; i++) sorted[i] = list[i];

        // Bubble sort by score descending
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (sorted[j].score < sorted[j + 1].score) {
                    Player temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        cout << "Top " << (size < 3 ? size : 3) << " Players:" << endl;
        int limit = (size < 3 ? size : 3);
        for (int i = 0; i < limit; i++) {
            cout << sorted[i].name << " " << sorted[i].id 
                 << " Age:" << sorted[i].age << " Score:" << sorted[i].score << endl;
        }
    }
};

int main() {
    PlayerManager pm;
    int n, id, age, score;
    string name;

    cout << "Enter number of players: ";
    cin >> n;

    cout << "Enter details (Name PlayerID Age Score):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> age >> score;
        pm.insert(name, id, age, score);
    }

    int updateId, newScore;
    cout << "Updating score for PlayerID "; cin >> updateId;
    cout << " -> New score = "; cin >> newScore;
    pm.updateScore(updateId, newScore);

    int deleteId;
    cout << "Deleting PlayerID "; cin >> deleteId;
    cout << "..." << endl;
    pm.remove(deleteId);

    pm.displayTop3();

    return 0;
}
