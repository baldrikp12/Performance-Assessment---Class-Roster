#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

//Represents a single student object.

//constructors
Student::Student() {
	Student::setStudentID("");
	Student::setFirstName("");
	Student::setLastName("");
	Student::setLastName("");
	Student::setAge(0);
	Student::setNumOfDays(0, 0, 0);
	Student::setDegree(NONE);
}
Student::Student(string theStudentID, string theFirstName, string theLastName, string theEmail, int theAge, int daysInCourse[], DegreeProgram theDegree) {
	Student::setStudentID(theStudentID);
	Student::setFirstName(theFirstName);
	Student::setLastName(theLastName);
	Student::setEmail(theEmail);
	Student::setAge(theAge);
	int day1 = daysInCourse[0];
	int day2 = daysInCourse[1];
	int day3 = daysInCourse[2];
	Student::setNumOfDays(day1, day2, day3);
	Student::setDegree(theDegree);
}

//accessors
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this->email;
}
int Student::getAge() {
	return this->age;
}
int* Student::getNumOfDays() {
	return this->numOfDays;
}
DegreeProgram Student::getDegree() {
	return this->degree;
}
string Student::programEnumToString() {
	return DEGREEPROGRAM[(int)getDegree()];
}

//mutators
void Student::setStudentID(string theStudentID) {
	this->studentID = theStudentID;
}
void Student::setFirstName(string theFirstName) {

	this->firstName = theFirstName;

}
void Student::setLastName(string theLastName) {

	this->lastName = theLastName;

}
void Student::setEmail(string theEmail) {

	this->email = theEmail;
}
void Student::setAge(int theAge) {
	this->age = theAge;

}
void Student::setNumOfDays(int theDaysInCourse1, int theDaysInCourse2, int theDaysInCourse3) {

	this->numOfDays[0] = theDaysInCourse1;
	this->numOfDays[1] = theDaysInCourse2;
	this->numOfDays[2] = theDaysInCourse3;

}
void Student::setDegree(DegreeProgram theDegree) {

	this->degree = theDegree;
}

void Student::print() {
	int* day = getNumOfDays();
	cout << getStudentID() << "\t" << "First Name : " << getFirstName() << "\t" << "Last Name : " << getLastName() << "\t";
	cout << "Age : " << getAge() << "\t" << "daysInCourse : {";
	cout << day[0] << ", " << day[1] << ", " << day[2] << "}\t";
	cout << "Degree Program : " << programEnumToString() << endl;

}

Student::~Student() { }