/*.Create a base class Student (Roll_No, Name) which derives two classes Theory and Practical. 
Theory class contains marks of five Subjects and Practical class contains marks of two practical 
subjects. Class Result (Total_Marks, Class) inherits both Theory and Practical classes. (Use 
concept of Virtual Base Class) Write a menu driven program to perform the following functions: 
a. Build a master table. 
b. Display master table.*/

#include <iostream>
#include <vector>
#include <string>

class Student {
protected:
    int Roll_No;
    std::string Name;

public:
    Student(int roll = 0, std::string name = "") : Roll_No(roll), Name(name) {}

    virtual void input() {
        std::cout << "Enter Roll Number: ";
        std::cin >> Roll_No;
        std::cin.ignore(); // Ignore newline character

        std::cout << "Enter Name: ";
        std::getline(std::cin, Name);
    }

    virtual void display() const {
        std::cout << "Roll No: " << Roll_No << ", Name: " << Name << std::endl;
    }
};

// Virtual Inheritance
class Theory : virtual public Student {
protected:
    int theoryMarks[5];

public:
    void input() override {
        Student::input();
        std::cout << "Enter marks for 5 theory subjects: ";
        for (int &mark : theoryMarks) {
            std::cin >> mark;
        }
    }

    void display() const override {
        Student::display();
        std::cout << "Theory Marks: ";
        for (int mark : theoryMarks) {
            std::cout << mark << " ";
        }
        std::cout << std::endl;
    }

    int getTheoryTotal() const {
        int total = 0;
        for (int mark : theoryMarks) {
            total += mark;
        }
        return total;
    }
};

// Virtual Inheritance
class Practical : virtual public Student {
protected:
    int practicalMarks[2];

public:
    void input() override {
        std::cout << "Enter marks for 2 practical subjects: ";
        for (int &mark : practicalMarks) {
            std::cin >> mark;
        }
    }

    void display() const override {
        std::cout << "Practical Marks: ";
        for (int mark : practicalMarks) {
            std::cout << mark << " ";
        }
        std::cout << std::endl;
    }

    int getPracticalTotal() const {
        return practicalMarks[0] + practicalMarks[1];
    }
};

// Multiple Inheritance using Virtual Base Classes
class Result : public Theory, public Practical {
private:
    int Total_Marks;
    std::string Class;

public:
    void input() {
        Theory::input(); // Call input from Theory
        Practical::input(); // Call input from Practical
        computeResult();
    }

    void computeResult() {
        Total_Marks = getTheoryTotal() + getPracticalTotal();
        Class = (Total_Marks >= 200) ? "Pass" : "Fail"; // Example criterion
    }

    void display() const {
        Theory::display();
        Practical::display();
        std::cout << "Total Marks: " << Total_Marks << ", Class: " << Class << std::endl;
    }
};

int main() {
    std::vector<Result> students;
    int choice;

    do {
        std::cout << "\nMENU:\n";
        std::cout << "1. Build Master Table\n";
        std::cout << "2. Display Master Table\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                std::cout << "Enter number of students: ";
                std::cin >> n;
                for (int i = 0; i < n; ++i) {
                    std::cout << "\nEntering details for student " << i + 1 << ":\n";
                    Result student;
                    student.input();
                    students.push_back(student);
                }
                break;
            }

            case 2:
                if (students.empty()) {
                    std::cout << "No student records available.\n";
                } else {
                    std::cout << "\nMaster Table:\n";
                    for (const auto &student : students) {
                        student.display();
                        std::cout << "--------------------------\n";
                    }
                }
                break;

            case 3:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
