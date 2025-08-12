/*Create a base class Media. Derive two different classes Book (Book_id, Book_name, 
Publication, Author, Book_price) and CD (CD_title, CD_price) from Media. Write a program 
to accept and display information of both Book and CD. (Use pure virtual function)*/

#include <iostream>
#include <string>
using namespace std;

class Media {
public:
    virtual void accept() = 0;
    virtual void display() = 0;
    virtual ~Media() {}
};

class Book : public Media {
private:
    int Book_id;
    string Book_name, Publication, Author;
    double Book_price;

public:
    void accept() override {
        cout << "Enter Book ID: ";
        cin >> Book_id;
        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, Book_name);
        cout << "Enter Publication: ";
        getline(cin, Publication);
        cout << "Enter Author: ";
        getline(cin, Author);
        cout << "Enter Book Price: ";
        cin >> Book_price;
    }

    void display() override {
        cout << "\nBook Details:\n";
        cout << "ID: " << Book_id << "\nName: " << Book_name
             << "\nPublication: " << Publication << "\nAuthor: " << Author
             << "\nPrice: " << Book_price << "\n";
    }
};

class CD : public Media {
private:
    string CD_title;
    double CD_price;

public:
    void accept() override {
        cin.ignore();
        cout << "Enter CD Title: ";
        getline(cin, CD_title);
        cout << "Enter CD Price: ";
        cin >> CD_price;
    }

    void display() override {
        cout << "\nCD Details:\n";
        cout << "Title: " << CD_title << "\nPrice: " << CD_price << "\n";
    }
};

int main() {
    Media* media[2];
    media[0] = new Book();
    media[1] = new CD();
    
    cout << "Enter Book details:\n";
    media[0]->accept();
    cout << "Enter CD details:\n";
    media[1]->accept();
    
    cout << "\nDisplaying Book and CD details:\n";
    media[0]->display();
    media[1]->display();
    
    delete media[0];
    delete media[1];
    
    return 0;
}
