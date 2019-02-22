// Kole Keeney
// Program 5
// Due 4/8/2018

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


//Declarations of all product class member variables and functions 
class Product {
protected:
	
	double price;
	int quantity;
	string description;

public:
	Product();
	Product(const double & prices, const int & quant, const string & descript);
	void setPrice(const double & prices);
	void setQuantity(const int & quant);
	void setDescription(const string & descript);
	double getPrice();
	const int getQuantity();
	string getDescription();
	virtual void print(ostream & out) = 0; //pure virtual function that is overwritten in child classes
	virtual double calculateTotal(); 
	

};


#endif