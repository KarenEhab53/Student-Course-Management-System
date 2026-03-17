#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <vector>
#include <string>
using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    vector<string> courses;

public:
    Student(int i, string n, double g);

    int getId();
    double getGpa();
    void display();
    void addCourse(string course); 
    void showCourses();
};

#endif // STUDENT_H


