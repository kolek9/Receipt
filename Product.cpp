// Kole Keeney
// Program 5
// Due 4/8/2018

#include "Product.h"

//Product constructors
Product::Product()
{
}

Product::Product(const double & prices, const int & quant, const string & descript)
{
	price = prices;
	quantity = quant;
}

//Getters and setters for price
double Product::getPrice()
{
	return price;
}

void Product::setPrice(const double & prices)
{
	price = prices;
}

//Getters and setters for quantity
const int Product::getQuantity()
{
	return quantity;
}
void Product::setQuantity(const int & quant)
{
	quantity = quant;
}

//Getters and setters for description
string Product::getDescription()
{
	return description;
}
void Product::setDescription(const string & descript)
{
	description = descript;
}

//Simple calculate total function which returns the price * number of items
double Product::calculateTotal()
{
	return (price * quantity);
}

