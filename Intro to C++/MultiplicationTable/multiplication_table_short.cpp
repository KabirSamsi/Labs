//Libraries and standard namesapce declaration
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

/**
  @Purpose - function prints programmer's name, program's name, and program compilation date
  @param name - Name of the Programmer
  @param ci - Information about the Lab
  @return - none (void)
  @author - Kabir Samsi
**/

void pmf(string name, string ci) {
  cout << "Program written by " << name << endl;
  cout << "Course Info: " << ci << endl;
  time_t now = time(0);
  cout << "Date: " << ctime(&now) << endl;
}

/**
  @Purpose - function prints out an evenly spaced multiplication table based on a given n
  @param n - Which n to build table on
  @return - none (void)
  @author - Kabir Samsi
**/

void ptbl(int n) {
    int rws = 1; //Tracks n of table rws
    int cls = 1;  //Tracks n of table clumns
    int hv = pow(n, 2);
    int hl = to_string(hv).length() + 2; //Takes largest n in table and calculates max space length
    int spc = 0; //Tracks spaces to keep even spacing later

    cout << "Multiplication table for " << n << " is:" << endl;
    while (rws <= n) { //Build each rw
        cls = 1; //Reset clumn count at each iteration
        while (cls <= n) { //Build each clumn in rw
            spc = 0;
            while (spc < (hl-to_string(rws*cls).length())) { //Increment spaces based on n length
                cout << " ";
                spc ++;
            }
            cout << rws*cls; //Product
            cls ++;
        }
        cout << endl; //End rw
        rws ++;
    }
}

/**
  @Purpose - User ins n until quit command is called. Calls the ptbl() method to build multiplication table
  @param - None
  @return - int (0)
  @author - Kabir Samsi
**/

int main() {
    string in;
    pmf("Kabir Samsi", "Lab 6 - Multiplication Table");

    cout << "\nEnter a positive n for multiplication table (Q to quit): ";
    cin >> in;
    while (in != "Q" && in != "q") { //Continue building table until user quits program
        try { //Call table method, unless n is not an integer
            if (stoi(in) > 0) {
                ptbl(stoi(in));
            } else {
                cout << "Number must be greater than 0" << endl;
            }
        } catch (exception& e) {
            cout << "Input must be an integer." << endl;
        }
        cout << "\nEnter a positive n for multiplication table (Q to quit): "; //Iterate loop again
        cin >> in;
    }
    cout << "Have a nice day" << endl; //Once loop terminates, send goodbye message
    return 0;
}