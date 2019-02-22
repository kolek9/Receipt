// Kole Keeney
// Program 5
// Due 4/8/2018

#include "OfficeSupplies.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

//OfficeSupplies constructors
OfficeSupplies::OfficeSupplies()
{
}

OfficeSupplies::OfficeSupplies(const string & descript, const int & counts, const int & quant, const double & prices) : Product(prices, quant, descript)
{
	description = descript;
	count = counts;
	quantity = quant;
	price = prices;
}

//getters and setters for the count
const int OfficeSupplies::getCount()
{
	return count;
}
void OfficeSupplies::setCount(int thecount)
{
	count = thecount;
}

//overwritten virtual print function 
void OfficeSupplies::print(ostream & out)
{
	string d = getDescription() + " (" + to_string(getCount()) + " count)";
	out << setw(3) << getQuantity() << " " << setw(28) << left << d << "$" << setw(7) << right << calculateTotal();
}


