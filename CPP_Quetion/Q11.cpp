/*Write a C++ program to create a class which contains two dimensional integer array of size m*n 
Write a member function to display transpose of entered matrix.(Use Dynamic Constructor for 
allocating memory and Destructor to free memory of an object).*/
#include <iostream>

class Matrix {
private:
    int** data;   // Pointer to the 2D array
    int rows;     // Number of rows
    int cols;     // Number of columns

public:
    // Dynamic constructor to allocate memory
    Matrix(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Member function to input matrix elements
    void input() {
        std::cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Member function to display the matrix
    void display() const {
        std::cout << "Matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Member function to display the transpose of the matrix
    void displayTranspose() const {
        std::cout << "Transpose of the matrix:\n";
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        std::cout << "Matrix memory deallocated successfully.\n";
    }
};

int main() {
    int m, n;
    std::cout << "Enter the number of rows: ";
    std::cin >> m;
    std::cout << "Enter the number of columns: ";
    std::cin >> n;

    Matrix mat(m, n);
    mat.input();
    mat.display();
    mat.displayTranspose();

    return 0;
}
