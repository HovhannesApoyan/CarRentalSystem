#pragma once
#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H
#include <iostream>
#include "AbstractCommands.h"
#include "FileManagement.h"
#include "Parser.h"

class AddCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		Parser parser(infoLine);
		std::string name;
		double price;
		if (parser.parsingNamePrice(name, price))
		{
			Car car(name, price);
			cars_rentals.push_back(car);
			FileManagement fileManagement;
			fileManagement.writeFile(name, price);
		}
		else
		{
			std::cout << "not correct name or number!\n";
		}
	}
};
#endif
