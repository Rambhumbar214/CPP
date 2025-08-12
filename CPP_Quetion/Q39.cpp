/*Write a C++ program to read the contents of a text file. Count and display number of characters, 
words and lines from a file. Find the number of occurrences of a given word present in a file*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string filename, word, line, searchWord;
    int charCount = 0, wordCount = 0, lineCount = 0, wordOccurrences = 0;
    
    cout << "Enter filename: ";
    cin >> filename;
    ifstream file(filename);
    
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    cout << "Enter word to search: ";
    cin >> searchWord;
    
    while (getline(file, line)) {
        lineCount++;
        charCount += line.length();
        
        stringstream ss(line);
        while (ss >> word) {
            wordCount++;
            if (word == searchWord) {
                wordOccurrences++;
            }
        }
    }
    
    file.close();
    
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    cout << "Occurrences of word '" << searchWord << "': " << wordOccurrences << endl;
    
    return 0;
}
