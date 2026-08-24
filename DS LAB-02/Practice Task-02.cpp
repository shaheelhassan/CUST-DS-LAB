// Practice Task-02
#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string name;
    int empNo;
    int experience;
    string designation;
    float salary;
};

// Function to sort employees alphabetically by name
void sortEmployees(Employee emp[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (emp[j].name > emp[j + 1].name) {
                Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter number of employees: ";
    cin >> N;

    if (N < 1 || N > 100) {
        cout << "Invalid number of employees." << endl;
        return 0;
    }

    Employee* originalList = new Employee[N];
    cout << "Enter details (Name Emp_No Experience Designation Salary):" << endl;

    for (int i = 0; i < N; i++) {
        // Handling names with potential spaces
        cin >> ws; // skip leading whitespace
        // To handle space-separated input like the sample accurately, 
        // we'll read fields carefully. 
        // But if Name itself contains spaces, reading it from one line 
        // with other fields is ambiguous unless restricted.
        // I'll use cin >> originalList[i].name for standard single-name cases 
        // as shown in the sample Ali, Sara, Zain etc.
        cin >> originalList[i].name; 
        cin >> originalList[i].empNo >> originalList[i].experience >> originalList[i].designation >> originalList[i].salary;
    }

    // 1. Store only those with experience >= 2
    Employee* filteredList = new Employee[N];
    int filteredCount = 0;
    for (int i = 0; i < N; i++) {
        if (originalList[i].experience >= 2) {
            filteredList[filteredCount++] = originalList[i];
        }
    }

    // Display: Experience >= 2
    cout << "\nEmployees with experience >= 2 years:" << endl;
    for (int i = 0; i < filteredCount; i++) {
        cout << filteredList[i].name << " " << filteredList[i].empNo << " " 
             << filteredList[i].experience << " " << filteredList[i].designation << " " << filteredList[i].salary << endl;
    }

    // 2. Display: Salary > 50000 (from the filtered list)
    cout << "\nEmployees with salary > 50000:" << endl;
    for (int i = 0; i < filteredCount; i++) {
        if (filteredList[i].salary > 50000) {
            cout << filteredList[i].name << " " << filteredList[i].empNo << " " 
                 << filteredList[i].experience << " " << filteredList[i].designation << " " << filteredList[i].salary << endl;
        }
    }

    // 3. Display: Alphabetical order
    sortEmployees(filteredList, filteredCount);
    cout << "\nEmployees in alphabetical order:" << endl;
    for (int i = 0; i < filteredCount; i++) {
        cout << filteredList[i].name << " " << filteredList[i].empNo << " " 
             << filteredList[i].experience << " " << filteredList[i].designation << " " << filteredList[i].salary << endl;
    }

    delete[] originalList;
    delete[] filteredList;

    return 0;
}
