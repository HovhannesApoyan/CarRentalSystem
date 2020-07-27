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
private:
	std::string name_;
	double price_;
};
#endif
