#pragma once
#ifndef SEARCH_COMMAND_H
#define SEARCH_COMMAND_H
#include <iostream>
#include <vector>
#include "AbstractCommands.h"
#include "Parser.h"

class SearchCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override
	{
		Parser parser;
		std::string name;
		double price;
		if (!parser.parsingNamePrice(info_line, name, price))
		{
			std::cout << "not correct name or number!\n";
			return;
		}
		//std::vector<std::vector<Car>::iterator> cars_;
		Car car(name, price);
		auto find_it = std::find(cars_rentals.begin(), cars_rentals.end(), car);
		if (find_it == cars_rentals.end())
		{
			std::cout << "Not found!\n";
			return;
		}
		while (find_it != cars_rentals.end())
		{
			cars.push_back(*find_it);
			//std::cout << find_it->name() << " " << find_it->price() << "\n";
			//Car car1(find_it->name(), find_it->price());
			//cars_.push_back(find_it);
			find_it = std::find(find_it + 1, cars_rentals.end(), car);
		}
	}
};
#endif
