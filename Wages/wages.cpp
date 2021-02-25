//LIBRARIES
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

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
  @Purpose - function evaluates a user's pay rate and hours worked, and then calculates their overtime hours, bonus pay and total pay.
  @param - none
  @return - 0
  @author - Kabir Samsi
**/

int main() {
    printMeFirst("Kabir Samsi", "Lab 4 - Wages");

    string name;
    double rate, regularPay, overtimePay, bonusPay, totalPay, hoursWorked, overtimeHours;

    cout << "Enter your first and last name: ";
    getline(cin, name);

    cout << "Enter your hourly rate: ";
    cin >> rate;

    cout << "Enter the number of hours you worked last week: ";
    cin >> hoursWorked;

    if (hoursWorked <= 0) {
        cout << "\nDidn't work this week. Number of hours must be > 0" << endl;

    } else {

        if (hoursWorked > 40.0) {
            regularPay = 40*rate;
            overtimeHours =  hoursWorked-40.0;
        } else {
            regularPay = rate*hoursWorked;
            overtimeHours =  0.0;
        }
        overtimePay = (overtimeHours * 1.5 * rate);

        if (hoursWorked > 60.0) {
            bonusPay = rate;
        } else {
            bonusPay = 0.0;
        }

        totalPay = regularPay + overtimePay + bonusPay;

        cout << "\n**************************\n\nPay Information for " << name << "\n\n**************************\n" << endl;
        cout << "   Regular Pay: $" << fixed << setprecision(2) << ((regularPay*100)/100) << endl;
        cout << "Overtime hours: " << fixed << setprecision(2) << overtimeHours << endl;
        cout << "  Overtime Pay: $" << fixed << setprecision(2) << (round(overtimePay*100)/100) << endl;
        cout << "     Bonus Pay: $" << fixed << setprecision(2) << (round(bonusPay*100)/100) << endl;
        cout << "     Total Pay: $" << fixed << setprecision(2) << (round(totalPay*100)/100) << endl;
    }
    return 0;
}
