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
    @Purpose - function recursively calculates change until the end of the money arrays are reached
    @param counter - Integer value tracks position in arrays
    @param diff - The current decimal change value (evaluated until it is 0)
    @return - integer value, either a call to the function or a return value 0
    @author - Kabir Samsi
**/

int calculateChange(int counter, double diff) {
    string moneyTypes[] = {"Dollars", "Quarters", "Dimes", "Nickels", "Pennies"}; //Array of money types
    int multipliers[] = {1, 4, 10, 25, 100}; //Array of multipliers (to multiply the integer remainder)
    double remainder = fmod(diff, (1.0/multipliers[counter])); //Calculate remainder based on reciprocal of multiplier

    if (counter == sizeof(moneyTypes)/sizeof(moneyTypes[0])) { //For pennies, don't convert to int (casting error)
        cout << moneyTypes[counter] << ": " << (diff * multipliers[counter]) << endl;
    } else {
        int intDiff = diff * multipliers[counter]; //Integer value of difference (outputs rounded answer, but evaluates with decimal remainder)
        cout << moneyTypes[counter] << ": " << intDiff << endl;
    }

    if (counter+1 == sizeof(moneyTypes)/sizeof(moneyTypes[0])) { //Repeat method until pennies are reached
        return 0;
    } else {
        return calculateChange(counter+1, remainder);
    }
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

    if ((received-due) < 0) {
        cout << "Error: Amount Received Must be Higher than Amount Due." << endl;
    } else {
        cout << "The change is:" << endl;
        calculateChange(0, (received-due));
    }
    return 0;
}
