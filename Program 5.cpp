// Kole Keeney
// Program 5
// Due 4/8/2018

/*	Input: Text file with items
	Output: Receipt with items and totals

	This program goes through a text file and creates a receipt for various supplies and clothing. The supplies will include the count, item
	description, amount purchased, and price. Clothing includes amount purchased, item description, size, and price. Finally, the program
	will output the total and number of items purchased.

*/


#include "Product.h"
#include "Shirt.h"
#include "Register.h"
#include "OfficeSupplies.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	//fstream declarations to read and write files
	ifstream fin("products.txt");
	ofstream fout("output.txt");

	//magic formula
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//If file won't open, display an error message
	if (!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}

	//Declarations and itializatins of various class pointers and objects
	OfficeSupplies os;
	Shirt *Shirtp = new Shirt;
	Register p;
	OfficeSupplies *Officep = new OfficeSupplies;

	//variable declarations and implementations
	string type, description, size;
	int quantity, count;
	double price;
	int line = 0;

	//read until the end of the file
	while (fin.peek() != EOF) {
		fin >> type;

		//checks if type is shirt, if so,it creates a new pointer of type Shirt and begins reading in values
		if (type == "SHIRT") {
			Shirt *s = new Shirt;
			fin.ignore();
			getline(fin, description);
			fin >> size >> quantity >> price;
			if (quantity < 1 || price <= 0.0) { //if variables are negative throw an error message
				cout << "File error! File contains incorrect number.\n";
			}
			Shirt hold(description, size, quantity, price); //constructor for new temporary shirt object
			//assigns temporary shirt to a pointer of type shirt
			*Shirtp = hold;
			*s = hold;
			//adds shirt pointer to the array of products
			p.addProduct(s);
			s = NULL; //resets the pointer
			line++; //increments the line /number of items
		}

		//checks if type is supply, if so,it creates a new pointer of type OfficeSupplies and begins reading in values
		else if (type == "SUPPLIES") {
			OfficeSupplies *os = new OfficeSupplies; //new OfficeSupplies object
			fin.ignore();
			getline(fin, description);
			fin >> count >> quantity >> price;
			if (count < 1 || quantity < 1 || price <= 0.0) {//if variables are negative throw an error message
				cout << "File error! File contains incorrect number.\n";
			}
			OfficeSupplies temp(description, count, quantity, price); //temporary object with constructor
			
			//assigns the pointers to the temporary object
			*Officep = temp;
			*os = temp;
			p.addProduct(os); //adds pointer to the array of Products
			os = NULL; //resets pointer
			line++;
		}

		else { //if item was not supply or shirt then throw an error
			cout << "Item type not recognized!\n";
		}

		p.setNumProducts(line); //essentially adds one more product
	}
	p.printReceipt(fout); //prints out the receipt after getting all the information


	system("pause");
    return 0;
}

