/*Department maintains a student information. The file contains roll
number, name, division and address. Allow user to add, delete
information of student. Display information of particular employee. If
record of student does not exist an appropriate message is displayed. If it
is, then the system displays the student details. Use sequential file to main
the data.*/





#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;


class Student {
public:
    int roll_no;
    string name;
    char division;
    string address;


    // Accept student details
    void accept() {
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
    }


    // Display student details
    void display() {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
    }
};


// Add student record
void addStudent() {
    ofstream fout("students.txt", ios::app);
    Student s;
    s.accept();
    fout << s.roll_no << "," << s.name << "," << s.division << "," << s.address << endl;
    fout.close();
    cout << "Student record added successfully.\n";
}


// Display specific student
void displayStudent() {
    ifstream fin("students.txt");
    int roll;
    bool found = false;
    cout << "Enter Roll No to search: ";
    cin >> roll;


    Student s;
    string line;


    while (getline(fin, line)) {
        stringstream ss(line); 
        string roll_str;
        getline(ss, roll_str, ',');
        int r = stoi(roll_str);


        if (r == roll) {
            s.roll_no = r;
            getline(ss, s.name, ',');
            string div;
            getline(ss, div, ',');
            s.division = div[0];
            getline(ss, s.address);


            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }


    if (!found) {
        cout << "Student with Roll No " << roll << " not found.\n";
    }


    fin.close();
}


// Delete student record
void deleteStudent() {
    ifstream fin("students.txt");
    ofstream temp("temp.txt");


    int roll;
    bool found = false;
    cout << "Enter Roll No to delete: ";
    cin >> roll;


    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string roll_str;
        getline(ss, roll_str, ',');
        int r = stoi(roll_str);


        if (r != roll) {
            temp << line << endl;
        } else {
            found = true;
        }
    }


    fin.close();
    temp.close();


    remove("students.txt");
    rename("temp.txt", "students.txt");


    if (found)
        cout << "Student record deleted successfully.\n";
    else
        cout << "Student with Roll No " << roll << " not found.\n";
}


// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- Student Information System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);


    return 0;
}



