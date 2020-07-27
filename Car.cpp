#include "Car.h"

Car::Car(std::string name, const double price)
	:name_(name),
	price_(price)
{

}

std::string Car::name() const
{
	return name_;
}

double Car::price() const
{
	return price_;
}
