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

void Car::setName(const std::string& new_name)
{
	name_ = new_name;
}

void Car::setPrice(const double new_price)
{
	price_ = new_price;
}

bool Car::operator==(const Car& car)
{
	return this->name() == car.name() && this->price() == car.price();
}
