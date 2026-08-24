// Practice Task-03
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
    cout << "Enter number of students: ";
    cin >> N;
    cout << "Enter number of subjects: ";
    cin >> M;

    if (N < 1 || N > 10 || M < 1 || M > 5) {
        cout << "Invalid input constraints." << endl;
        return 0;
    }

    // Allocate 2D dynamic array
    int** marks = new int*[N];
    for (int i = 0; i < N; i++) {
        marks[i] = new int[M];
    }

    // Input marks
    for (int i = 0; i < N; i++) {
        cout << "Enter marks for Student " << (i + 1) << ": ";
        for (int j = 0; j < M; j++) {
            cin >> marks[i][j];
        }
    }

    // Calculate averages and display
    cout << "\nAverage marks of each student:" << endl;
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < M; j++) {
            sum += marks[i][j];
        }
        cout << "Student " << (i + 1) << ": " << fixed << setprecision(2) << (sum / M) << endl;
    }

    // Highest scorer in each subject
    cout << "\nHighest scorer in each subject:" << endl;
    for (int j = 0; j < M; j++) {
        int maxMarks = -1;
        int studentIdx = -1;
        for (int i = 0; i < N; i++) {
            if (marks[i][j] > maxMarks) {
                maxMarks = marks[i][j];
                studentIdx = i;
            }
        }
        cout << "Subject " << (j + 1) << ": Student " << (studentIdx + 1) << " (" << maxMarks << ")" << endl;
    }

    // Total marks in dynamic 1D array
    int* totals = new int[N];
    int topScorerIdx = 0;
    cout << "\nTotal marks (stored in dynamic array):" << endl;
    for (int i = 0; i < N; i++) {
        totals[i] = 0;
        for (int j = 0; j < M; j++) {
            totals[i] += marks[i][j];
        }
        cout << "Student " << (i + 1) << ": " << totals[i] << endl;
        if (totals[i] > totals[topScorerIdx]) {
            topScorerIdx = i;
        }
    }

    cout << "\nTop Scorer Overall: Student " << (topScorerIdx + 1) << " with " << totals[topScorerIdx] << " marks" << endl;

    // Free memory
    for (int i = 0; i < N; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] totals;

    return 0;
}
