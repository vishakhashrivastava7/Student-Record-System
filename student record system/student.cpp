#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int rollNo;
    string name;
};

int main() {
    vector<Student> records;
    int choice;

    do {
        cout << "\n===== Student Record System =====" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Delete Student by Roll Number" << endl;
        cout << "5. Update Student by Roll Number" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter roll number: ";
            cin >> s.rollNo;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, s.name);
            records.push_back(s);
            cout << "Record added successfully!" << endl;
        } 
        else if (choice == 2) {
            cout << "\nAll Student Records:\n";
            for (const auto& s : records) {
                cout << "Roll No: " << s.rollNo << ", Name: " << s.name << endl;
            }
            if (records.empty()) {
                cout << "No records found!" << endl;
            }
        }
        else if (choice == 3) {
            int searchRoll;
            bool found = false;
            cout << "Enter roll number to search: ";
            cin >> searchRoll;

            for (const auto& s : records) {
                if (s.rollNo == searchRoll) {
                    cout << "Record Found: Roll No: " << s.rollNo
                         << ", Name: " << s.name << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Record not found!" << endl;
            }
        }
        else if (choice == 4) {
            int delRoll;
            bool deleted = false;
            cout << "Enter roll number to delete: ";
            cin >> delRoll;

            for (auto it = records.begin(); it != records.end(); ++it) {
                if (it->rollNo == delRoll) {
                    records.erase(it);
                    cout << "Record deleted successfully!" << endl;
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << "Record not found!" << endl;
            }
        }
        else if (choice == 5) {
            int updRoll;
            bool updated = false;
            cout << "Enter roll number to update: ";
            cin >> updRoll;

            for (auto& s : records) {
                if (s.rollNo == updRoll) {
                    cout << "Current name: " << s.name << endl;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, s.name);
                    cout << "Record updated successfully!" << endl;
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                cout << "Record not found!" << endl;
            }
        }

    } while (choice != 6);

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
