#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

int findStudentIndex(vector<Student>& students, int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "-----MENU-----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Enroll Student in Course" << endl;
        cout << "6. Show Student Courses" << endl;
        cout << "7. Sort Students by GPA" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double gpa;
            cout << "Enter ID: ";
            cin >> id;

            if (findStudentIndex(students, id) != -1) {
                cout << "ID already exists" << endl;
                continue;
            }
            cin.ignore(); // عشان نتجنب مشكلة newline
            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            if (gpa < 0 || gpa > 4) {
                cout << "Invalid GPA" << endl;
                continue;
            }

            students.push_back(Student(id, name, gpa));
            cout << "Student added successfully" << endl;
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            int index = findStudentIndex(students, id);
            if (index != -1) {
                students.erase(students.begin() + index);
                cout << "Student removed" << endl;
            }
            else {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            int index = findStudentIndex(students, id);
            if (index != -1) {
                students[index].display();
            }
            else {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 4) {
            if (students.empty()) {
                cout << "No students available" << endl;
            }
            else {
                for (int i = 0; i < students.size(); i++) {
                    students[i].display();
                }
            }
        }
        else if (choice == 5) {
            int id;
            string course;
            cout << "Enter Student ID: ";
            cin >> id;
            int index = findStudentIndex(students, id);
            if (index != -1) {
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, course);
                students[index].addCourse(course);
            }
            else {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 6) {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            int index = findStudentIndex(students, id);
            if (index != -1) {
                students[index].showCourses();
            }
            else {
                cout << "Student not found." << endl;
            }
        }
        else if (choice == 7) {
            sort(students.begin(), students.end(), [](Student a, Student b) {
                return a.getGpa() > b.getGpa();
                });
            cout << "Students sorted by GPA" << endl;
        }

    } while (choice != 8);

    return 0;
}