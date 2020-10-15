#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include<vector>
#include "degree.h"
#include "student.h"
using namespace std;

//Represents a single Roster.
class Roster {

	//Private variables.
private:
	Student* classRosterArray[5];
	int index;

	//Public methods.
public:
	//Constructor and destructor.
	Roster();
	~Roster();

	//Accessors.
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	std::vector<string> parseStudent(string theStudentList);
	void printAll();
	Student* getStudent(int theStudent); //Helper method.
	string stringToEnumstringInt(string degreeString);//Helper method.

	//Mutators
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void setRosterSize(int theSize);//Helper method.

};
#endif