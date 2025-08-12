/*. A book (ISBN) and CD (data capacity) are both types of media (id, title) objects. A person buys 
10 media items each of which can be either book or CD. Display the list of all books and CD’s 
bought. Define the classes and appropriate member functions to accept and display data. Use 
pointers and concept of polymorphism (Virtual Function)*/

#include <iostream>
#include <vector>
#include <memory>

// Base class
class Media {
protected:
    int id;
    std::string title;

public:
    Media(int id, const std::string& title) : id(id), title(title) {}

    virtual void display() const = 0; // Pure virtual function

    virtual ~Media() = default; // Virtual destructor
};

// Derived class for Book
class Book : public Media {
private:
    std::string ISBN;

public:
    Book(int id, const std::string& title, const std::string& ISBN)
        : Media(id, title), ISBN(ISBN) {}

    void display() const override {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nISBN: " << ISBN << std::endl;
    }
};

// Derived class for CD
class CD : public Media {
private:
    double dataCapacity; // in MB

public:
    CD(int id, const std::string& title, double dataCapacity)
        : Media(id, title), dataCapacity(dataCapacity) {}

    void display() const override {
        std::cout << "CD ID: " << id << "\nTitle: " << title << "\nData Capacity: " << dataCapacity << " MB" << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Media>> mediaCollection;

    // Adding books and CDs to the collection
    mediaCollection.push_back(std::make_unique<Book>(1, "The Great Gatsby", "978-0743273565"));
    mediaCollection.push_back(std::make_unique<CD>(2, "Thriller", 700.0));
    mediaCollection.push_back(std::make_unique<Book>(3, "1984", "978-0451524935"));
    mediaCollection.push_back(std::make_unique<CD>(4, "Back in Black", 650.0));
    mediaCollection.push_back(std::make_unique<Book>(5, "To Kill a Mockingbird", "978-0061120084"));
    mediaCollection.push_back(std::make_unique<CD>(6, "The Dark Side of the Moon", 500.0));
    mediaCollection.push_back(std::make_unique<Book>(7, "Pride and Prejudice", "978-1503290563"));
    mediaCollection.push_back(std::make_unique<CD>(8, "The Wall", 800.0));
    mediaCollection.push_back(std::make_unique<Book>(9, "The Catcher in the Rye", "978-0316769488"));
    mediaCollection.push_back(std::make_unique<CD>(10, "Abbey Road", 600.0));

    // Displaying all media items
    for (const auto& media : mediaCollection) {
        media->display();
        std::cout << std::endl;
    }

    return 0;
}
