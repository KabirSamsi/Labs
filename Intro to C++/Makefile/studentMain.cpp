#include <iostream>
#include "printMeFirst.cpp"
#include "student.cpp"

using namespace std;

int main() {
    printMeFirst("Kabir Samsi", "Lab 9 - Makefile");
    printStudentInfo(getData());
    return 0;
}