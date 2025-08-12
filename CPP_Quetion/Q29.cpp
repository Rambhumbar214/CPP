/*Design a base class Product(Product _Id, Product _Name, Price). Derive a class Discount 
(Discount_In_Percentage) from Product. A customer buys n Products. Calculate total price, 
total discount and display bill using appropriate manipulators. */


#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Product {
protected:
    int Product_Id;
    string Product_Name;
    double Price;

public:
    Product(int id, string name, double price) : Product_Id(id), Product_Name(name), Price(price) {}
    virtual void displayProduct() const {
        cout << left << setw(10) << Product_Id << setw(20) << Product_Name << setw(10) << fixed << setprecision(2) << Price;
    }
    double getPrice() const { return Price; }
};

class Discount : public Product {
private:
    double Discount_In_Percentage;

public:
    Discount(int id, string name, double price, double discount) : Product(id, name, price), Discount_In_Percentage(discount) {}

    double getDiscountAmount() const {
        return (Price * Discount_In_Percentage) / 100.0;
    }

    double getFinalPrice() const {
        return Price - getDiscountAmount();
    }

    void displayProduct() const override {
        Product::displayProduct();
        cout << setw(10) << Discount_In_Percentage << setw(10) << getFinalPrice() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    
    vector<Discount> products;
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        double price, discount;
        
        cout << "Enter Product ID, Name, Price, Discount Percentage: ";
        cin >> id >> name >> price >> discount;
        
        products.emplace_back(id, name, price, discount);
    }
    
    double totalPrice = 0, totalDiscount = 0;
    
    cout << "\nInvoice:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Discount%" << setw(10) << "Final Price" << endl;
    cout << string(60, '-') << endl;
    
    for (const auto& product : products) {
        product.displayProduct();
        totalPrice += product.getPrice();
        totalDiscount += product.getDiscountAmount();
    }
    
    cout << string(60, '-') << endl;
    cout << "Total Price: " << fixed << setprecision(2) << totalPrice << endl;
    cout << "Total Discount: " << fixed << setprecision(2) << totalDiscount << endl;
    cout << "Final Amount to Pay: " << fixed << setprecision(2) << (totalPrice - totalDiscount) << endl;
    
    return 0;
}