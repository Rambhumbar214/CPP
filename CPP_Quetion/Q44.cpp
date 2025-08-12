/*Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram), Volume 
(Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program to perform 
read, convert and display operations. (Use Pure virtual function)*/

#include <iostream>
using namespace std;

class Conversion {
public:
    virtual void read() = 0;
    virtual void convert() = 0;
    virtual void display() = 0;
    virtual ~Conversion() {}
};

class Weight : public Conversion {
private:
    float gram, kilogram;
public:
    void read() {
        cout << "Enter weight in grams: ";
        cin >> gram;
    }
    void convert() {
        kilogram = gram / 1000.0;
    }
    void display() {
        cout << "Weight: " << gram << " g = " << kilogram << " kg" << endl;
    }
};

class Volume : public Conversion {
private:
    float milliliter, liter;
public:
    void read() {
        cout << "Enter volume in milliliters: ";
        cin >> milliliter;
    }
    void convert() {
        liter = milliliter / 1000.0;
    }
    void display() {
        cout << "Volume: " << milliliter << " ml = " << liter << " L" << endl;
    }
};

class Currency : public Conversion {
private:
    int rupees, paise;
public:
    void read() {
        cout << "Enter amount in rupees: ";
        cin >> rupees;
    }
    void convert() {
        paise = rupees * 100;
    }
    void display() {
        cout << "Currency: Rs. " << rupees << " = " << paise << " paise" << endl;
    }
};

int main() {
    Conversion *c;
    int choice;
    do {
        cout << "\nConversion Menu:\n1. Weight\n2. Volume\n3. Currency\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                c = new Weight();
                break;
            case 2:
                c = new Volume();
                break;
            case 3:
                c = new Currency();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
                continue;
        }
        c->read();
        c->convert();
        c->display();
        delete c;
    } while (choice != 4);
    
    return 0;
}