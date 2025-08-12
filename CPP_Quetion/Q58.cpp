/*1.Write a C++ program to sort integer and float array elements in ascending order by using 
function overloading */

#include <iostream>
#include <algorithm>
using namespace std;

class SortArray {
public:
    void sortArray(int arr[], int size) {
        sort(arr, arr + size);
        cout << "Sorted Integer Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sortArray(float arr[], int size) {
        sort(arr, arr + size);
        cout << "Sorted Float Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SortArray sorter;
    
    int intArr[] = {5, 3, 8, 1, 2};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    sorter.sortArray(intArr, intSize);
    
    float floatArr[] = {2.5, 0.5, 3.3, 1.1, 4.7};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    sorter.sortArray(floatArr, floatSize);
    
    return 0;
}
