#include <iostream>
#include "student.h"

using namespace std;

Student getData() {
    Student studentInfo;
    cout << endl << "Enter the following student data:" << endl << "Student name: ";
    getline(cin, studentInfo.name);
    cout << "Student ID Number: ";
    cin >> studentInfo.idNum;
    cout << "Student Hours Enrolled: ";
    cin >> studentInfo.creditHours;
    cout << "Student GPA: ";
    cin >> studentInfo.gpa;

    return studentInfo;
}

void printStudentInfo(Student student) {
    cout << endl << "Here is the student data you entered:" << endl << "Name: "<< student.name << endl;
    cout << "ID Number: "<< student.idNum << endl;
    cout << "Credit Hours: "<< student.creditHours << endl;
    cout << "GPA: "<< student.gpa << endl;
}