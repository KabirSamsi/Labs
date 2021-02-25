#include <iostream>
#include <string>
#include <cmath>

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
    @Purpose - function calculates change in dollars/quarters/dimes/nickels/pennies
    @param diff - The starting difference between paid money and owed money
    @return - none (void)
    @author - Kabir Samsi
**/

void calculateChange(double diff) {

    //Variable stores integer value of difference (program outputs rounded answer, but evaluates with the floating remainder)
    int intVal = diff;
    cout << "The change is:" << endl;

    cout << "Dollars: " << intVal << endl; //Dollars
    diff = fmod(diff, 1);

    //Calculate the integer remaining quantity, after turning change into remainder
    intVal = (diff*4);
    cout << "Quarters: " << intVal << endl; //Quarters
    diff = fmod(diff, 0.25);

    intVal = diff*10;
    cout << "Dimes: " << intVal << endl; //Dimes
    diff = fmod(diff, 0.1);

    intVal = diff*20;
    cout << "Nickels: " << intVal << endl; //Nickels
    diff = fmod(diff, 0.05);

    //Don't convert pennies to ints (casting error)
    diff *= 100;
    cout << "Pennies: " << diff << endl; //Pennies
}

/**
    @Purpose - function evaluates the total change based on the amount of money due and the amount paid.
    @param - none
    @return - 0
    @author - Kabir Samsi
**/

int main() {
    printMeFirst("Kabir Samsi", "Lab 3 - Money Change");

    double due, received;
    cout << "Enter the amount due: ";
    cin >> due;
    cout << "Enter the amount received: ";
    cin >> received;

    if (received-due < 0) {
        cout << "Error: amount paid must be higher than amount owed" << endl;
    } else {
        calculateChange(received-due);
    }
    return 0;
}
