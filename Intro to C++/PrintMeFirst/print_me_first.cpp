/**
  Program: print_me_first.cpp
  Description:
    Program welcomes a user with an inputted username to an inputted course.
    Also executes the print_me_first function which outputs information about the programmer, program and date the program was written.
**/

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/**
  @Purpose - function prints out the name of the programmer, name of the program, and time the program was written
  @param name - Name of the Programmer
  @param courseInfo - Information about the Lab
  @return - none (void)
  @author - Kabir Samsi
**/

void printMeFirst(string name, string courseInfo) {
  cout << "Program written by " << name << endl;
  cout << "Course Info: " << courseInfo << endl;
  time_t now = time(0);
  cout << "Date: " << ctime(&now) << endl;
}

/**
  @Purpose - Executes function that prints out user's name and course
    - Calls the printMeFirst function to print out the programmer's name, lab name, and time the programmer was written at
    - Stores variables firstName (user first name) and courseName (name of course)
    - Outputs a welcome message using the two variables

  @param - None
  @return - 0
  @author - Kabir Samsi
**/

int main() {
  printMeFirst("Kabir Samsi", "Lab 1 - Print Me First");

  string firstName, courseName;

  cout << "\nWhat is your first name? ";
  cin >> firstName;
  cin.ignore(1024, '\n');

  cout << "What is the name of this course? ";
  getline(cin, courseName);
  cout << endl;

  cout << "Hello " << firstName << ", welcome to " << courseName << " class." << endl;
  return 0;
}
