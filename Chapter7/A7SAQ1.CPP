#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
class Product {
	public:
		int pid;         // Product ID
		char pname[10];    // Product name
		float price;     // Price of the product

	public:
		// Constructor to initialize product details
		Product(int id, char name[10], float p)
		{
		pid = id;
		pname[10] = name[10];
		price = p;
		}

		// Function to get the price of the product
		float getPrice()
		{
		return price;
		}
	};

// Derived class: Discount
class Discount : public Product
	{
	public:
	float d;  // Discount in percentage

	public:
	// Constructor to initialize product and discount details
	 Discount(int id, char name [10], float p, float discount): Product(id, name, p)
	 {
	d = discount;
	}

    // Function to calculate the discount amount
    float calculateDiscount() {
	return (price * d) / 100;
    }

    // Function to calculate the final price after discount
    float finalPrice() {
	return price - calculateDiscount();
    }

    // Display product details, discount, and final price
    void displayDetails() {
	cout << setw(10) << pid
	     << setw(20) << pname
	     << setw(10) << setprecision(2) << price
	     << setw(15) << d
	     << setw(15) << calculateDiscount()
	     << setw(15) << finalPrice() << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    float totalPrice = 0, totalDiscount = 0, totalFinalPrice = 0;

    // Create an array of Discount objects
    for (int i = 0; i < n; i++) {
	int id;
	char name [10];
	float price, discount;

	cout << "\nEnter details for product " << i + 1 << ":\n";
	cout << "Product ID: ";
	cin >> id;
	cout << "Product Name: ";
	cin>>name;
	cout << "Product Price: ";
	cin >> price;
	cout << "Discount Percentage: ";
	cin >> discount;

	Discount prod(id, name, price, discount);

	// Display the product details
	prod.displayDetails();

	// Update totals
	totalPrice += prod.getPrice();
	totalDiscount += prod.calculateDiscount();
	totalFinalPrice += prod.finalPrice();
    }

    // Display totals
    cout << "\nTotal Price: "  << setprecision(2) << totalPrice << endl;
    cout << "Total Discount: "  << setprecision(2) << totalDiscount << endl;
    cout << "Total Final Price: " << setprecision(2) << totalFinalPrice << endl;
    getch();
    return 0;
}
