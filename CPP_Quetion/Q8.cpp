/*2.Write a C++ program with Student as abstract class and create derive classes Engineering, 
Medicine and Science having data member rollno and name from base class Student. Create 
objects of the derived classes and access them using array of pointer of base class Student. */
#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Student {
protected:
    int rollno;
    std::string name;

public:
    Student(int r, const std::string& n) : rollno(r), name(n) {}

    // Pure virtual function to display student details
    virtual void display() const = 0;

    // Virtual destructor
    virtual ~Student() = default;
};

// Derived class for Engineering students
class Engineering : public Student {
public:
    Engineering(int r, const std::string& n) : Student(r, n) {}

    void display() const override {
        std::cout << "Engineering Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

// Derived class for Medicine students
class Medicine : public Student {
public:
    Medicine(int r, const std::string& n) : Student(r, n) {}

    void display() const override {
        std::cout << "Medicine Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

// Derived class for Science students
class Science : public Student {
public:
    Science(int r, const std::string& n) : Student(r, n) {}

    void display() const override {
        std::cout << "Science Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

int main() {
    // Array of pointers to Student
    std::vector<Student*> students;

    // Creating objects of derived classes
    students.push_back(new Engineering(101, "Alice"));
    students.push_back(new Medicine(102, "Bob"));
    students.push_back(new Science(103, "Charlie"));

    // Accessing objects using base class pointers
    for (const auto& student : students) {
        student->display();
    }

    // Cleaning up allocated memory
    for (auto& student : students) {
        delete student;
    }

    return 0;
}
