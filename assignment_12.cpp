/*
  Implementation of a direct access file -Insertion and deletion of a record
from a direct access file
*/




#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


const int SIZE = 100; // Max records allowed


class Student {
public:
    int roll_no;
    char name[20];
    char division;
    char address[30];


    Student() {
        roll_no = -1; // -1 means empty slot (deleted or unused)
    }


    void accept() {
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 30);
    }


    void display() {
        cout << left << setw(10) << roll_no
             << setw(20) << name
             << setw(10) << division
             << setw(30) << address << endl;
    }
};


// Function to insert a record (direct access using roll number as key)
void insertRecord() {
    fstream file("direct.dat", ios::in | ios::out | ios::binary);


    if (!file) {
        // File doesn't exist yet, so create it and fill with dummy data
        file.open("direct.dat", ios::out | ios::binary);
        Student s;
        for (int i = 0; i < SIZE; i++)
            file.write((char*)&s, sizeof(s));
        file.close();
        file.open("direct.dat", ios::in | ios::out | ios::binary);
    }


    Student s;
    s.accept();
    int pos = s.roll_no;


    if (pos >= SIZE) {
        cout << "Roll number exceeds file size limit.\n";
        return;
    }


    file.seekp(pos * sizeof(Student));
    file.write((char*)&s, sizeof(s));
    cout << "Record inserted at position " << pos << endl;
    file.close();
}


// Function to display all records
void displayAll() {
    ifstream file("direct.dat", ios::in | ios::binary);
    Student s;
    cout << "\n--- All Records ---\n";
    cout << left << setw(10) << "Roll No" << setw(20) << "Name"
         << setw(10) << "Div" << setw(30) << "Address" << endl;


    for (int i = 0; i < SIZE; i++) {
        file.read((char*)&s, sizeof(s));
        if (s.roll_no != -1) {
            s.display();
        }
    }
    file.close();
}


// Function to delete a record (logical deletion)
void deleteRecord() {
    fstream file("direct.dat", ios::in | ios::out | ios::binary);
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;


    if (roll >= SIZE) {
        cout << "Invalid Roll No.\n";
        return;
    }


    Student s;
    file.seekg(roll * sizeof(Student));
    file.read((char*)&s, sizeof(s));


    if (s.roll_no == -1) {
        cout << "Record already empty.\n";
    } else {
        s.roll_no = -1;
        file.seekp(roll * sizeof(Student));
        file.write((char*)&s, sizeof(s));
        cout << "Record deleted.\n";
    }
    file.close();
}


// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- Direct Access File System ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Delete Record\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;


        switch (choice) {
        case 1:
            insertRecord();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            deleteRecord();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);


    return 0;
}



