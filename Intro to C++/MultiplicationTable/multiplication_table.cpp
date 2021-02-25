//Libraries and standard namesapce declaration
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

/**
  @Purpose - function prints programmer's name, program's name, and program compilation date
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
  @Purpose - function prints out an evenly spaced multiplication table based on a given number
  @param number - Which number to build table on
  @return - none (void)
  @author - Kabir Samsi
**/

void printTable(int number) {
    int rows = 1; //Tracks number of table rows
    int cols = 1;  //Tracks number of table columns
    int highestValue = pow(number, 2);
    int highestLength = to_string(highestValue).length() + 2; //Takes largest number in table and calculates max space length
    int spaceCount = 0; //Tracks spaces to keep even spacing later

    cout << "Multiplication table for " << number << " is:" << endl;

    while (rows <= number) { //Build each row
        cols = 1; //Reset column count at each iteration
        while (cols <= number) { //Build each column in row
            spaceCount = 0;
            while (spaceCount < (highestLength-to_string(rows*cols).length())) { //Increment spaces based on number length
                cout << " ";
                spaceCount ++;
            }
            cout << rows*cols; //Product
            cols ++;
        }
        cout << endl; //End row
        rows ++;
    }
}

/**
  @Purpose - User inputs number until quit command is called. Calls the printTable() method to build multiplication table
  @param - None
  @return - int (0)
  @author - Kabir Samsi
**/

int main() {
    string input;

    printMeFirst("Kabir Samsi", "Lab 6 - Multiplication Table");

    cout << "\nEnter a positive number for multiplication table (Q to quit): ";
    cin >> input;
    while (input != "Q" && input != "q") { //Continue building table until user quits program
        try { //Call table method, unless number is not an integer
            if (stoi(input) > 0) {
                printTable(stoi(input));
            } else {
                cout << "Number must be greater than 0" << endl;
            }
        } catch (exception& e) {
            cout << "Input must be an integer." << endl;
        }

        cout << "\nEnter a positive number for multiplication table (Q to quit): "; //Iterate loop again
        cin >> input;
    }

    cout << "Have a nice day" << endl; //Once loop terminates, send goodbye message
    return 0;
}