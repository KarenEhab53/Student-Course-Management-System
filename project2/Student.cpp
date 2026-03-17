#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int i, string n, double g) {
    id = i;
    name = n;
    gpa = g;
}

int Student::getId() {
    return id;
}

double Student::getGpa() {
    return gpa;
}

void Student::display() {
    cout << "ID: " << id << " |Name: " << name << " |GPA: " << gpa << endl;
}

void Student::addCourse(string course) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            cout << "Course already exists" << endl;
            return;
        }
    }
    courses.push_back(course);
    cout << "Course added successfully" << endl;
}

void Student::showCourses() {
    if (courses.empty()) {
        cout << "No courses enrolled yet" << endl;
        return;
    }
    cout << "Courses: " << endl;
    for (int i = 0; i < courses.size(); i++) {
        cout << courses[i] << endl;
    }
}