#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "roster.h"
#include "degree.h"
using namespace std;


Roster::Roster() {
	this->setRosterSize(0);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInClassArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	this->classRosterArray[this->index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInClassArray, degreeprogram);
	this->index++;
}

void Roster::remove(string studentID) {
	bool matchFound = false;
	int i;
	for (i = 0; i < this->index; i++) {

		if (this->classRosterArray[i]->getStudentID() == studentID) {
			matchFound = true;
			for (i = i; i < this->index - 1; i++) {

				this->classRosterArray[i] = this->classRosterArray[i + 1];

			}
		}

	}
	if (matchFound) {
		cout << "Student " << studentID << " was removed from the roster." << endl;
		this->index--;
	}
	else {
		cout << "Such a student with ID " << studentID << " was not found" << endl;
	}

}

void Roster::printAll() {
	cout << "Full Roster: " << endl;
	for (int i = 0; i < this->index; i++) {
		this->classRosterArray[i]->print();
	}

}

void Roster::printAverageDaysInCourse(string studentID) {
	int daysAveraged = 0;

	for (int i = 0; i < this->index; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			daysAveraged = (this->classRosterArray[i]->getNumOfDays()[0] + this->classRosterArray[i]->getNumOfDays()[1] + this->classRosterArray[i]->getNumOfDays()[2]) / 3;
			break;
		}
	}
	cout << "Student " << studentID << " average number of days: " << daysAveraged << endl;

}

void Roster::printInvalidEmails() {
	string badEmail = "The invalid email Addresses are:\n";

	for (int i = 0; i < this->index; i++) {
		if (this->classRosterArray[i]->getEmail().find("@") == std::string::npos || this->classRosterArray[i]->getEmail().find(".") == std::string::npos || this->classRosterArray[i]->getEmail().find(" ") != std::string::npos) {
			badEmail.append(this->classRosterArray[i]->getEmail().append("\n"));
		}
	}

	cout << badEmail;

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	cout << "The students in the " << DEGREEPROGRAM[(int)degreeProgram] << " program are: \n";

	for (int i = 0; i < this->index; i++) {
		if (this->classRosterArray[i]->getDegree() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

Student* Roster::getStudent(int theStudent) {
	return this->classRosterArray[theStudent];
}

std::vector<string> Roster::parseStudent(string theStudentDataTableEntry) {

	std::vector<string> aStudent;
	stringstream wholeStudentDataString(theStudentDataTableEntry);
	int index = 0;

	while (wholeStudentDataString.good()) {
		string studentData;
		getline(wholeStudentDataString, studentData, ',');
		if (index == 8) {
			studentData = stringToEnumstringInt(studentData);
		}
		aStudent.push_back(studentData);
		index++;
	}

	return aStudent;
}


void Roster::setRosterSize(int theSize) {
	this->index = theSize;
}

string Roster::stringToEnumstringInt(string degreeString) {

	string enumstringInt = "0";
	if (degreeString == "SECURITY") {
		enumstringInt = "0";
	}
	if (degreeString == "NETWORK") {
		enumstringInt = "1";
	}
	if (degreeString == "SOFTWARE") {
		enumstringInt = "2";
	}
	return enumstringInt;

}

Roster::~Roster() { }