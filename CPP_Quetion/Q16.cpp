/*.Create a class Book containing Book_name, author and Price as a data member and write 
necessary member functions for the following (use function overloading). 
a. To Accept and display the Book Information. 
b. Display book details of a given author 
c. Display book details of specific price */
#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string Book_name;
    std::string Author;
    double Price;

public:
    // Default constructor
    Book() : Book_name(""), Author(""), Price(0.0) {}

    // Parameterized constructor
    Book(const std::string& name, const std::string& author, double price)
        : Book_name(name), Author(author), Price(price) {}

    // Function to accept book information
    void Accept() {
        std::cout << "Enter Book Name: ";
        std::getline(std::cin, Book_name);
        std::cout << "Enter Author Name: ";
        std::getline(std::cin, Author);
        std::cout << "Enter Price: ";
        std::cin >> Price;
        std::cin.ignore(); // To consume the newline character left by std::cin
    }

    // Function to display book information
    void Display() const {
        std::cout << "Book Name: " << Book_name << "\n"
                  << "Author: " << Author << "\n"
                  << "Price: $" << Price << "\n";
    }

    // Getter for Author
    std::string getAuthor() const {
        return Author;
    }

    // Getter for Price
    double getPrice() const {
        return Price;
    }
};

// Function to display books by a specific author
void Display(const std::vector<Book>& books, const std::string& author) {
    bool found = false;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            book.Display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found by author: " << author << "\n";
    }
}

// Function to display books by a specific price
void Display(const std::vector<Book>& books, double price) {
    bool found = false;
    for (const auto& book : books) {
        if (book.getPrice() == price) {
            book.Display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found with price: $" << price << "\n";
    }
}

int main() {
    std::vector<Book> library;
    int choice;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Add a Book\n"
                  << "2. Display All Books\n"
                  << "3. Search Books by Author\n"
                  << "4. Search Books by Price\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To consume the newline character left by std::cin

        switch (choice) {
            case 1: {
                Book newBook;
                newBook.Accept();
                library.push_back(newBook);
                break;
            }
            case 2: {
                for (const auto& book : library) {
                    book.Display();
                    std::cout << "-------------------\n";
                }
                break;
            }
            case 3: {
                std::string author;
                std::cout << "Enter Author Name to search: ";
                std::getline(std::cin, author);
                Display(library, author);
                break;
            }
            case 4: {
                double price;
                std::cout << "Enter Price to search: ";
                std::cin >> price;
                std::cin.ignore(); // To consume the newline character left by std::cin
                Display(library, price);
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
