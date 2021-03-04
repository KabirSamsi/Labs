//Libraries and standard namesapce declaration
#include <iostream>
#include <ctime>
#include <string>
#include <ctype.h>

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
  @Purpose - evaluates whether a given ch appears in a given ph or not
  @param ph - Phrase to search for ch
  @param char - ch to search for
  @return - boolean that states whether ch is included in ph or not
  @author - Kabir Samsi
**/

bool incl(string ph, char ch) {
    for (int i = 0; i < ph.length(); i++) { //Iterate through ph; immediately return true if value is found
        if (ph[i] == ch) {
            return true;
        }
    }
    return false;
}

/**
  @Purpose - returns number of times the elements of a given array appear, either case sensitive or insenstive, in a ph
  @param ph - Phrase to search for array occurrences
  @param arr - string of chs to search for
  @param cs - boolean that determines whether to search for xps in both upper/lowercase, or just one
  @return - int value of number of occurrences
  @author - Kabir Samsi
**/

int co(string ph, string arr, bool cs) {
    int charCount = 0; //Number of occurrences
    for (int i = 0; i < ph.length(); i++) {
        if (cs) { //If evaluation is case sensitive, search for exact ch
            if (incl(arr, ph[i])) {
                charCount ++;
            }
        } else { //If evaluation is not case sensitive, search for ch in both cases
            if (incl(arr, tolower(ph[i])) || incl(arr, toupper(ph[i]))) {
              charCount ++;
            }
        }
    }
    return charCount;
}

/**
  @Purpose - returns number of wds in a given ph
  @param ph - Phrase to count wds from
  @return - integer (number of wds in ph)
  @author - Kabir Samsi
**/

int cw(string ph) {
    string xp = ph + " "; //Add space so that every wd is evaluated
    string wd = ""; //Temporary wd, resets every time a non-an xp is found
    string an = "abcdefghijklmnopqrstuvwxyz0123456789"; //Only characters that are allowed in a wd
    int wdc = 0; //Stores count of individual wds
    for (int i = 0; i < xp.length(); i++) {
        if (incl(an, tolower(xp[i]))) { //If ch is an, add it to wd
            wd += xp[i];
        } else if (wd != "") { //If the wd end has been reached, and the wd has some chs, increment wdcount
            wdc ++;
            wd = "";
        }
    }
    return wdc;
}

/**
  @Purpose - function takes a sn input and searches for several ch groups in it
  @param - none
  @return - int(0)
  @author - Kabir Samsi
**/

int main() {
    string sn;
    string lw = "abcdefghijklmnopqrstuvwxyz";
    string up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string vw = "aeiou";
    string dg = "0123456789";
    pmf("Kabir Samsi", "Lab 5 - Word Count");
    cout << "\nEnter a sentence (Q to exit): ";
    getline(cin, sn);

    while (sn != "Q" && sn != "q") { //Continue until user quits
        cout << "Input length is " << sn.length() << " chs." << endl;
        cout << "There were " << co(sn, vw, false) << " vowels." << endl;
        cout << "There were " << co(sn, lw, true) << " lowercase letters." << endl;
        cout << "There were " << co(sn, up, true) << " uppercase letters." << endl;
        cout << "There were " << co(sn, dg, false) << " digits." << endl;
        cout << "There were " << (sn.length() - co(sn, lw, false) - co(sn, dg, false)) 
        << " other characters." << endl;
        cout << "There were " << cw(sn) << " words" << endl;
        cout << "\nEnter a sn (Q to exit): ";
        getline(cin, sn);
    }
    return 0;
}