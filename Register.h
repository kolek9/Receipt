// Kole Keeney
// Program 5
// Due 4/8/2018

#ifndef REGISTER_H
#define REGISTER_H

#include <fstream>
#include "Product.h"
using namespace std;

//declaration of all Register members
class Register{
private:
	Product *prod[50];
	int numProducts = 0;
public:
	Register();
	void addProduct(Product *p);
	void printReceipt(ostream & out);
	int getNumProducts();
	void setNumProducts(const int & num);
};

#endif
