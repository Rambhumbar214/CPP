/*.Write a C++ program to create a class which contains single dimensional integer array of 
given size. Define member function to display median of a given array. (Use Dynamic 
Constructor to allocate and Destructor to free memory of an object).*/

#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    Array(int n) {
        size = n;
        arr = new int[size];
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    
    void displayMedian() {
        sort(arr, arr + size);
        double median;
        if (size % 2 == 0)
            median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        else
            median = arr[size / 2];
        cout << "Median of the array: " << median << endl;
    }
    
    ~Array() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    Array obj(n);
    obj.displayMedian();
    
    return 0;
}