#include <iostream>
#include <iomanip>
#include <vector>

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
    @Purpose - function merges two sorted vectors and then sorts them
    @param a - Sorted vector of integers
    @param b - Sorted vector of integers
    @return - Sorted vector of integers that combines the two vector parameters
    @author - Kabir Samsi
**/

vector<int> merge_sorted(vector<int>  a, vector<int> b) {
    vector<int> merged; //Vector stores the merged and sorted vector

    //Concatenate vectors
    for (int i = 0; i < a.size(); i++) {merged.push_back(a[i]);}
    for (int i = 0; i < b.size(); i++) {merged.push_back(b[i]);}

    //Selection sort algorithm sorts the two concatenated vectors
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
    return merged; //Return merged & sorted vector
}

/**
    @Purpose - function builds two sorted vectors and then merges them, implemnting the merge_sorted function
    @param - None
    @return - int (0)
    @author - Kabir Samsi
**/

int main() {
    vector<int> g1, g2;
    printMeFirst("Kabir Samsi", "Lab 8 - Vector Merge");

    //Test Case Vector 1
    cout << "Vector a: " << endl;
    for (int i = 0; i < 7; i ++) {
        cout << i*i << " ";
        g1.push_back(i * i);
    }

    //Test Case Vector 2
    cout << endl << "\nVector b: " << endl;
    for (int i = 0; i < 5; i ++) {
        cout << (i*i)+4 << " ";
        g2.push_back((i * i) + 4);
    }

    //Merge Vvctor and output result
    vector<int> merged = merge_sorted(g1, g2);
    cout << endl << "\nResult of interleaved merge of sorted a and b is\n";
    for (int i = 0; i < merged.size(); i++) cout << merged[i] << " ";
    cout << endl;

    return 0;
}