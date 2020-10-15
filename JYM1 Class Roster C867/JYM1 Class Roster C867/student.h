#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using namespace std;

//Represents a single student object.
class Student {

//Private variables.
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numOfDays[3];
	DegreeProgram degree;

	//Public methods.
public:
	//Constructors and destructor.
	Student(); //Default
	Student(string theStudentID, string theFirstName, string theLastName, string theEmail, int theAge, int daysInCourse[3], DegreeProgram theDegree); //Overloaded
	~Student();//destrcutor

	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	string programEnumToString();
	int getAge();
	int* getNumOfDays();
	DegreeProgram getDegree();
	void print(); //prints all student data

	//Mutators
	void setStudentID(string theStudentID);
	void setFirstName(string theFirstName);
	void setLastName(string theLastName);
	void setEmail(string theEmail);
	void setAge(int theAge);
	void setNumOfDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegree(DegreeProgram theDegree);

};
#endif