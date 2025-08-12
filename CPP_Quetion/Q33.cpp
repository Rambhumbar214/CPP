/*2. Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram), 
Volume (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program 
to perform read, convert and display operations. (Use Pure virtual function)*/

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
    void read() override {
        cout << "Enter weight in grams: ";
        cin >> gram;
    }
    void convert() override {
        kilogram = gram / 1000.0;
    }
    void display() override {
        cout << "Weight: " << gram << " grams = " << kilogram << " kilograms" << endl;
    }
};

class Volume : public Conversion {
private:
    float milliliter, liter;
public:
    void read() override {
        cout << "Enter volume in milliliters: ";
        cin >> milliliter;
    }
    void convert() override {
        liter = milliliter / 1000.0;
    }
    void display() override {
        cout << "Volume: " << milliliter << " mL = " << liter << " L" << endl;
    }
};

class Currency : public Conversion {
private:
    float rupees, paise;
public:
    void read() override {
        cout << "Enter amount in rupees: ";
        cin >> rupees;
    }
    void convert() override {
        paise = rupees * 100;
    }
    void display() override {
        cout << "Currency: " << rupees << " rupees = " << paise << " paise" << endl;
    }
};

int main() {
    Conversion* conversions[3];
    conversions[0] = new Weight();
    conversions[1] = new Volume();
    conversions[2] = new Currency();
    
    for (int i = 0; i < 3; i++) {
        conversions[i]->read();
        conversions[i]->convert();
        conversions[i]->display();
    }
    
    for (int i = 0; i < 3; i++) {
        delete conversions[i];
    }
    
    return 0;
}
