#include <iostream>
#include <string>
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
  @Purpose - outputs a prompt for a double value, evaluates it, and then returns a parsed double
  @param prompt - The prompt to send the user
  @return - a double representing the converted value
  @author - Kabir Samsi
**/

double getNumber(string prompt) {
    double result;
    cout << prompt;
    cin >> result;
    while (cin.fail()) { //While inputted value is not of double type, clear all input history and re-prompt user
        cin.clear();
        cin.ignore(1024, '\n');
        cout << prompt;
        cin >> result;
    }
    return result; //Once value fits double type, return it
}

/**
  @Purpose - converts a Fahrenheit double value into a Celsius double value
  @param f - The initial Fahrenheit value
  @return - a double representing the converted Celsius value
  @author - Kabir Samsi
**/

double FtoC(double f) {
    return ((f - 32.0) * (5.0/9.0)); //Arithmetic operations
}

/**
  @Purpose - converts a Celsius double value into a Fahrenheit double value
  @param c - The initial Celsius value
  @return - a double representing the converted Fahrenheit value
  @author - Kabir Samsi
**/

double CtoF(double c) {
    return (c * (9.0/5.0)) + 32.0; //Arithmetic operations
}

/**
  @Purpose - Takes commands for conversion from Celsius to Fahrenheit and vice versa, until a command to quit is received.
  @return - int (0)
  @author - Kabir Samsi
**/

int main() {
    int selection;
    double value;
    printMeFirst("Kabir Samsi", "Lab 7 - Conversion");

    do {
        selection = 0;
        cout << "Choose a selection below:\n   1 - Fahrenheit to Celsius\n   2 - Celsius to Fahrenheit\n   3 - Quit" << endl; //List of prompts
        cin >> selection;
        while (cin.fail()) { //While the entered prompt is not an integer, clear previous inputs and keep reprompting
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Choose a selection below:\n   1 - Fahrenheit to Celsius\n   2 - Celsius to Fahrenheit\n   3 - Quit" << endl;
            cin >> selection;
        }

        //Perform function based on which input is entered
        if (selection == 1) {
            value = getNumber("Enter a Fahrenheit value: ");
            cout << fixed << setprecision(2) << value << " F is equal to " << fixed << setprecision(2) << FtoC(value) << " C\n" << endl;
            
        } else if (selection == 2) {
            value = getNumber("Enter a Celsius value: ");
            cout << fixed << setprecision(2) << value << " C is equal to " << fixed << setprecision(2) << CtoF(value) << " F\n" << endl;

        } else if (selection != 3) cout << "Invalid Command\n" << endl; //If input has no matching command

    } while (selection != 3); //Selection 3 signals a loop break

    return 0;
}