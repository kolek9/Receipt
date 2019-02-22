// Kole Keeney
// Program 5
// Due 4/8/2018

#include "Register.h"
#include <iomanip>
#include <iostream>
using namespace std;

//default constructor
Register::Register()
{
}

//takes product pointer and adds it to the array of products
void Register::addProduct(Product * p)
{
	prod[numProducts] = p;
}

//getter and setter for number of producter
int Register::getNumProducts()
{
	return numProducts;
}
void Register::setNumProducts(const int & num)
{
	numProducts = num;
}

//outputs the receipt
void Register::printReceipt(ostream & out)
{
	out << "****************************************\n";
	out << "*   CS 201 Super Selling Stuff Store   *" << endl;
	out << "****************************************\n\n";
	out << "Qty " << setw(28) << left << "Description" << "Total" << endl;
	out << "--- --------------------------- --------\n";
	
	//calculates the grand total
	double total = 0;
	for (int i = 0; i < numProducts; i++) {
		prod[i]->print(out);
		total += prod[i]->calculateTotal();
		out << endl;
	}
	
	//final outputs
	out << "\nGrand total: $" <<total << endl;
	out << "Items sold: " << numProducts << endl << endl;
	out << "* Thank you for shopping at our store! *";


}

