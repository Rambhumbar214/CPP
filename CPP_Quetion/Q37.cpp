/*.Write a C++ program to implement a class ‘student’ to overload following functions as follows: 
a. int maximum(int, int) – returns the maximum score of two students 
b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’*/

#include <iostream>
using namespace std;

class Student {
public:
    int maximum(int a, int b) {
        return (a > b) ? a : b;
    }
    
    int maximum(int *arr, int arrayLength) {
        int maxVal = arr[0];
        for (int i = 1; i < arrayLength; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
};

int main() {
    Student student;
    
    int score1, score2;
    cout << "Enter two student scores: ";
    cin >> score1 >> score2;
    cout << "Maximum score between two students: " << student.maximum(score1, score2) << endl;
    
    int n;
    cout << "Enter the number of student scores: ";
    cin >> n;
    int *scores = new int[n];
    cout << "Enter " << n << " student scores: ";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    cout << "Maximum score from the array: " << student.maximum(scores, n) << endl;
    
    delete[] scores;
    return 0;
}
