/*.Create a class Matrix and Write a C++ program to perform following functions: 
a. To accept a Matrix 
b. To display a Matrix 
c. Overload unary minus ‘–‘ operator to calculate transpose of a Matrix 
d. Overload binary multiplication '*’ operator to calculate multiplication of two matrices */
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10];

public:
    // Constructor to initialize matrix
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {}

    // Function to accept matrix elements
    void acceptMatrix() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void displayMatrix() const {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overloading unary minus (-) operator to compute transpose
    Matrix operator-() {
        Matrix trans(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                trans.mat[j][i] = mat[i][j];
            }
        }
        return trans;
    }

    // Overloading binary multiplication (*) operator to multiply two matrices
    Matrix operator*(const Matrix &m) {
        if (cols != m.rows) {
            cout << "Matrix multiplication not possible. Incompatible dimensions.\n";
            return Matrix();
        }
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix mat1, mat2, result;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Accept Matrix\n";
        cout << "2. Display Matrix\n";
        cout << "3. Transpose Matrix\n";
        cout << "4. Multiply Matrices\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter first matrix:\n";
                mat1.acceptMatrix();
                break;
            case 2:
                mat1.displayMatrix();
                break;
            case 3:
                result = -mat1;
                cout << "Transpose of the matrix:\n";
                result.displayMatrix();
                break;
            case 4:
                cout << "Enter second matrix for multiplication:\n";
                mat2.acceptMatrix();
                result = mat1 * mat2;
                cout << "Resultant matrix after multiplication:\n";
                result.displayMatrix();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}