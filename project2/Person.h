#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;
class Person {
protected :
	string name;

public:
	void setName(string n);
	string getName();
};
#endif // !PERSON_H
