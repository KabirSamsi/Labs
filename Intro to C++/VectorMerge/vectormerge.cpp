#include <iostream>
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
    @Purpose - function merges two sorted vectors in sorted order using a different version of insertion sort
    @param a - Sorted vector of integers
    @param b - Sorted vector of integers
    @return - Sorted vector of integers that combines the two vector parameters
    @author - Kabir Samsi
**/

vector<int> merge_sorted(vector<int>  a, vector<int> b) {
    vector<int> smallest, largest, merged; //Smallest and largest store a and b based on size; merged stores the merged vector
    if (a.size() >= b.size()) largest = a, smallest = b; else largest = b, smallest = a;
    largest.push_back(smallest[smallest.size()-1]+1); //Put largest element in larger vector; all smaller array elements get iterated over

    while (largest.size() > 1) { //Build merged vector until larger vector has only final (redundant) element
        while (smallest.size() > 0) { //Iterate until larger value is reached, or smaller vector is empty
            if (smallest[0] <= largest[0]) { //Add element if it is smaller than large vector value
                merged.push_back(smallest[0]);
                smallest.erase(smallest.begin());
            } else break; //Otherwise break loop
        }
        merged.push_back(largest[0]); //After adding all the smaller b-values, add the smaller a-value and remove it from original vector
        largest.erase(largest.begin());
    }
    return merged;
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
    cout << endl;

    //Merge Vector and output result
    vector<int> merged = merge_sorted(g1, g2);
    cout << endl << "Result of interleaved merge of sorted a and b is" << endl;
    for (int i = 0; i < merged.size(); i++) cout << merged[i] << " ";
    cout << endl;

    return 0;
}