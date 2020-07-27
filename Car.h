#pragma once
#ifndef CAR_H
#define CAR_H
#include <string>

class Car
{
public:
	Car(std::string name, const double price);
	std::string name()const;
	double price()const;
	void setName(const std::string& new_name);
	void setPrice(const double new_price);
	bool operator==(const Car& car);
private:
	std::string name_;
	double price_;
};
#endif
