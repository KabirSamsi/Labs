#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

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

vector<int> merge_sorted(vector<int>  a, vector<int> b) {
    vector<int> merged;
    for (int i = 0; i < a.size(); i++) {merged.push_back(a[i]);}
    for (int i = 0; i < b.size(); i++) {merged.push_back(b[i]);}

    int temp;
    for (int i = 0; i < merged.size(); i++) {
        for (int j = 0; j < merged.size()-1; j++) {
            if (merged[j] > merged[j+1]) {
                temp = merged[j];
                merged[j] = merged[j+1];
                merged[j+1] = temp;
            }
        }
    }   
    return merged;
}

int main() {
    string input1, input2;
    int number;
    vector<int> g1, g2;

    printMeFirst("Kabir Samsi", "Lab 8 - Vector Merge");

    cout << "Vector A:" << endl;
    getline(cin, input1);
    std::stringstream iss(input1);
    while (iss >> number) { g1.push_back( number );}

    cout << "\nVector B:" << endl;
    getline(cin, input2);
    std::stringstream iss2(input2);
    while (iss2 >> number) { g2.push_back( number);}

    vector<int> merged = merge_sorted(g1, g2);
    cout << "\nResult of interleaved merge of sorted a and b is\n";
    for (int i = 0; i < merged.size(); i++) {cout << merged[i] << " ";}
    cout << endl;

    return 0;
}