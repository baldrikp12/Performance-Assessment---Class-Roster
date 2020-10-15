#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

/*
Kenneth Baldridge
Course
10/13/2020
Performance Assessment:
Submission 1
*/

const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kenneth,Baldridge,kbaldr2@wgu.edu,32,16,17,18,SOFTWARE"
};

int main() {

	int numOfStudents = *(&studentData + 1) - studentData;  //Find number of students in studentData[]
	std::vector<string> aStudent(numOfStudents);
	Roster classRoster;

	for (int i = 0; i < numOfStudents; i++) { //loops through studentData[]

		aStudent = classRoster.parseStudent(studentData[i]); //Single students data
		int daysInCourse[3] = { std::stoi(aStudent[5]), std::stoi(aStudent[6]), std::stoi(aStudent[7]) }; //Singles out days in course

		classRoster.add(aStudent[0], aStudent[1], aStudent[2], aStudent[3], std::stoi(aStudent[4]), 
			std::stoi(aStudent[5]), std::stoi(aStudent[6]), std::stoi(aStudent[7]), (DegreeProgram)std::stoi(aStudent[8])); //Yes... I did cast to my enum...
	}

	cout << "Course | C++ | Student ID | Kenneth Baldridge" << endl;

	cout << "\n" << endl;

	classRoster.printAll();

	cout << "\n" << endl;

	classRoster.printInvalidEmails();

	cout << "\n" << endl;

	//loop through classRosterArray and for each element:
	cout << "Student's average number of days in three courses:\n";
	for (int i = 0; i < numOfStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
	}

	cout << "\n" << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "\n" << endl;

	classRoster.remove("A3");

	cout << "\n" << endl;

	classRoster.printAll();

	cout << "\n" << endl;

	classRoster.remove("A3");

	//expected: the above line should print a message saying such a student with this ID was not found.

	return 0;
}