// Kole Keeney
// Program 5
// Due 4/8/2018

#ifndef OFFICESUPPLIES_H
#define OFFICESUPPLIES_H

#include <fstream>
#include "Product.h"
using namespace std;

//declarations of OfficeSupplies member variables and functions
class OfficeSupplies : public Product{

private:
	int count;
public:
	OfficeSupplies();
	OfficeSupplies(const string & descript, const int & counts, const int & quant, const double & prices);
	const int getCount();
	void setCount(int thecount);
	virtual void print(ostream & out) override;
};


#endif
