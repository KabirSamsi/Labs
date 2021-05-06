#include <iostream>
#include "printMeFirst.cpp"
#include "student.cpp"

using namespace std;

/**
  @Purpose - function executes the student-related functions to query user input, and then output it
  @return - None (void)
  @author - Kabir Samsi
**/

int main() {
    printMeFirst("Kabir Samsi", "Lab 9 - Makefile");
    printStudentInfo(getData());
    return 0;
}