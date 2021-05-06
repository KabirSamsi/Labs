//Libraries and standard namesapce declaration
#include <iostream>
#include <string>
#include <ctime>
#include "printMeFirst.h"

using namespace std;

/**
  @Purpose - function prints programmer's name, program's name, and program compilation date
  @param name - Name of the Programmer
  @param courseInfo - Information about the Lab
  @return - none (void)
  @author - Kabir Samsi
**/

void printMeFirst(string name, string courseInfo) {
	cout << "Program written by: " << name << endl;
	cout << "Course Info: " << courseInfo << endl;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "Date: " << dt << endl;
}

