#include <iostream>
#include "student.h"

using namespace std;

/**
  @Purpose - function builds a Student struct instance, queries user for data, and populate the object
  @return - Student object with all data fields filled out by user input
  @author - Kabir Samsi
**/

Student getData() {
    Student studentInfo;
    cout << endl << "Enter the following student data:" << endl;
    cout << "Student name: ";
    getline(cin, studentInfo.name);
    cout << "Student ID Number: ";
    cin >> studentInfo.idNum;
    cout << "Student Hours Enrolled: ";
    cin >> studentInfo.creditHours;
    cout << "Student GPA: ";
    cin >> studentInfo.gpa;

    return studentInfo;
}

/**
  @Purpose - function outputs all data of a Student object
  @param student - Instance of Student object which contains that data that needs to be printed out
  @return - None (void)
  @author - Kabir Samsi
**/

void printStudentInfo(Student student) {
    cout << endl << "Here is the student data you entered:" << endl;
    cout << "Name: "<< student.name << endl;
    cout << "ID Number: "<< student.idNum << endl;
    cout << "Credit Hours: "<< student.creditHours << endl;
    cout << "GPA: "<< student.gpa << endl;
}