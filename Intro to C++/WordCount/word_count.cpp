//Libraries and standard namesapce declaration
#include <iostream>
#include <ctime>
#include <string>
#include <ctype.h>

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
  @Purpose - evaluates whether a given character appears in a given phrase or not
  @param phrase - Phrase to search for character
  @param char - character to search for
  @return - boolean that states whether character is included in phrase or not
  @author - Kabir Samsi
**/

bool isIncluded(string phrase, char character) {
    for (int i = 0; i < phrase.length(); i++) { //Iterate through phrase; immediately return true if value is found
        if (phrase[i] == character) {
            return true;
        }
    }
    return false;
}

/**
  @Purpose - returns number of times the elements of a given array appear, either case sensitive or insenstive, in a phrase
  @param phrase - Phrase to search for array occurrences
  @param arr - string of characters to search for
  @param caseSensitive - boolean that determines whether to search for expressions in both upper/lowercase, or just one
  @return - int value of number of occurrences
  @author - Kabir Samsi
**/

int countOccurrences(string phrase, string arr, bool caseSensitive) {
    int charCount = 0; //Number of occurrences
    for (int i = 0; i < phrase.length(); i++) {
        if (caseSensitive) { //If evaluation is case sensitive, search for exact character
            if (isIncluded(arr, phrase[i])) {
                charCount ++;
            }
        } else { //If evaluation is not case sensitive, search for character in both cases
            if (isIncluded(arr, tolower(phrase[i])) || isIncluded(arr, toupper(phrase[i]))) {
              charCount ++;
            }
        }
    }
    return charCount;
}

/**
  @Purpose - returns number of words in a given phrase
  @param phrase - Phrase to count words from
  @return - integer (number of words in phrase)
  @author - Kabir Samsi
**/

int countWords(string phrase) {
    string expression = phrase + " "; //Add space so that every word is evaluated
    string word = ""; //Temporary word, resets every time a non-alphanumeric expression is found
    string alphanumeric = "abcdefghijklmnopqrstuvwxyz0123456789"; //Only character that are allowed in a word
    int wordCount = 0; //Stores count of individual words
    for (int i = 0; i < expression.length(); i++) {
        if (isIncluded(alphanumeric, tolower(expression[i]))) { //If character is alphanumeric, add it to word
            word += expression[i];
        } else if (word != "") { //If the word end has been reached, and the word has some characters, increment wordcount
            wordCount ++;
            word = "";
        }
    }
    return wordCount;
}

/**
  @Purpose - function takes a sentence input and searches for several character groups in it
  @param - none
  @return - int(0)
  @author - Kabir Samsi
**/

int main() {
    string sentence;

    //ALL CHARACTER STRINGS/ARRAYS
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string vowels = "aeiou";
    string digits = "0123456789";

    printMeFirst("Kabir Samsi", "Lab 5 - Word Count");
    cout << "\nEnter a sentence (Q to exit): ";
    getline(cin, sentence);

    while (sentence != "Q" && sentence != "q") { //Continue until user quits
        cout << "Input length is " << sentence.length() << " characters." << endl;
        cout << "There were " << countOccurrences(sentence, vowels, false) << " vowels." << endl;
        cout << "There were " << countOccurrences(sentence, lower, true) << " lowercase letters." << endl;
        cout << "There were " << countOccurrences(sentence, upper, true) << " uppercase letters." << endl;
        cout << "There were " << countOccurrences(sentence, digits, false) << " digits." << endl;
        cout << "There were " << 
            (sentence.length() - countOccurrences(sentence, lower, false) - countOccurrences(sentence, digits, false)) 
        << " other characters." << endl;
        cout << "There were " << countWords(sentence) << " words." << endl;
        cout << "\nEnter a sentence (Q to exit): ";
        getline(cin, sentence);
    }
    return 0;
}
