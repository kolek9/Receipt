// Kole Keeney
// Program 5
// Due 4/8/2018

#ifndef SHIRT_H
#define SHIRT_H

#include <string>
#include <fstream>
#include "Product.h"
using namespace std;


//Shirt class member variable and function declarations
class Shirt : public Product {
private:
	string size;
public:
	Shirt();
	Shirt(const string & descript, const string & sizes, const int & quant, const double & prices);
	const string getSize();
	void setSize(string thesize);
	void print(ostream & out) override;
	double calculateTotal() override;

};



#endif
