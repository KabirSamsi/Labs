#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>

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
  @Purpose - function evaluates a car's total cost for driving 100 miles
  @param mileage - The miles per gallon on the given car
  @param price - The cost of gas per gallon
  @return - a maximum 2-floating-point double value that represents total cost of gas for traveling 100 miles
  @author - Kabir Samsi
**/

double calculateCost(double mileage, double price) {
    double cost = (100/mileage) * price;
    cost = round(cost*100)/100;
    return cost;
}

/**
  @Purpose - function evaluates a car's total distance covered with a full tank of gas
  @param capacity - The capacity of a tank
  @param mileage - The miles per gallon on the given car
  @return - a double value that represents total distance that can be covered
  @author - Kabir Samsi
**/

double calculateDistance(double capacity, double mileage) {
    return capacity*mileage;
}

/**
  @Purpose - function evaluates a car's total cost for driving 100 miles, as well as the distance per tank of gas.
  //Implements calculateCost() and calculateDistance() methods.
  @param - none
  @return - 0
  @author - Kabir Samsi
**/

int main() {
    printMeFirst("Kabir Samsi", "Lab 2 - Car Mileage");

    double capacity, mileage, price;

    cout << "Enter capacity of car's gas tank (in gallons): ";
    cin >> capacity;

    cout << "Enter mileage per gallon (in miles): ";
    cin >> mileage;

    cout << "Enter price per gallon (in dollars): ";
    cin >> price;

    cout << "\nCost for driving 100 miles is $ " << fixed << setprecision(2) << calculateCost(mileage, price) << endl;
    cout << "Distance on a tank of gas is  " << fixed << setprecision(2) << calculateDistance(capacity, mileage) << " miles" << endl;

    return 0;
}
