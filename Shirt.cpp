// Kole Keeney
// Program 5
// Due 4/8/2018

#include "Shirt.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Shirt Constructors
Shirt::Shirt()
{
}

Shirt::Shirt(const string & descript, const string & sizes, const int & quant, const double & prices) : Product(prices, quant, descript)
{
	description = descript;
	size = sizes;
	quantity = quant;
	price = prices;
}

//getters and setters for the size
const string Shirt::getSize()
{
	return size;
}

void Shirt::setSize(string thesize)
{
	size = thesize;
}

//overwritten virtual print member function
 void Shirt::print(ostream & out)
{
	out << setw(3) << right<< getQuantity() << " " << setw(28) << left << (getSize() + " " + getDescription()) << "$" << setw(7) << right << calculateTotal();
}
 
 //overwritten virtual calculate total member function
double Shirt::calculateTotal()
{	
	//if the item is 2XL or 3XL add a dollar per item
	double p = getPrice() * getQuantity();
	if (getSize() == "2XL" || getSize() == "3XL") {
		p = p + getQuantity();
	}

	return p;
}
