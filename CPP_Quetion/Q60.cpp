/*. Write a C++ program to read the contents of a “Sample.txt” file. Store all the uppercase 
characters in ”Upper.txt”, lowercase characters in ”Lower.txt” and digits in “Digit.txt” files. 
Change the case of each character from “Sample.txt” and store it in “Convert.txt” file. 
*/


#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void processFile() {
    ifstream inputFile("Sample.txt");
    ofstream upperFile("Upper.txt");
    ofstream lowerFile("Lower.txt");
    ofstream digitFile("Digit.txt");
    ofstream convertFile("Convert.txt");
    
    if (!inputFile) {
        cout << "Error opening Sample.txt!" << endl;
        return;
    }
    
    char ch;
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            upperFile << ch;
        } else if (islower(ch)) {
            lowerFile << ch;
        } else if (isdigit(ch)) {
            digitFile << ch;
        }
        
        // Change case and write to Convert.txt
        if (isupper(ch)) {
            convertFile << (char)tolower(ch);
        } else if (islower(ch)) {
            convertFile << (char)toupper(ch);
        } else {
            convertFile << ch;
        }
    }
    
    inputFile.close();
    upperFile.close();
    lowerFile.close();
    digitFile.close();
    convertFile.close();
    
    cout << "Processing complete. Check output files." << endl;
}

int main() {
    processFile();
    return 0;
}
