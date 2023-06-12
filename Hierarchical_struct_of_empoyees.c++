#include<bits/stdc++.h>
using namespace std;

struct office {
    int id, age, reported_id;
    string name;
};

void printEmployees(const vector<office>& employees, int id, int level) {
    for (const auto& employee : employees) {
        if (employee.reported_id == id) {
            for (int i = 0; i < level; i++)
                cout << "\t";
            cout << employee.id << " - " << employee.name << endl;
            printEmployees(employees, employee.id, level + 1);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    vector<office> employees(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter the employee id no.: ";
        cin >> employees[i].id;
        cin.ignore();
        cout << "Enter the name of the employee: ";
        getline(cin, employees[i].name);
        cout << "Enter the employee age: ";
        cin >> employees[i].age;
        cout << "Enter the employee reported_id no.: ";
        cin >> employees[i].reported_id;
    }
    cout << "Hierarchical structure of employees:" << endl;
    printEmployees(employees, -1, 0);
    return 0;
}