#pragma once
#ifndef DELETE_COMMAND_H
#define DELETE_COMMAND_H
#include <iostream>
#include "AbstractCommands.h"
#include "FileManagement.h"
#include "Parser.h"

class DeleteCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		Parser parser(infoLine);
		std::string name;
		double price;
		if (parser.parsingNamePrice(name, price))
		{
			cars_rentals.erase(std::remove_if(cars_rentals.begin(), cars_rentals.end(), [=](const Car& c1)
				{
					return c1.name() == name && c1.price() == price;
				}), cars_rentals.end());

			FileManagement fileManagement;
			fileManagement.writeFile(cars_rentals);
		}
		else
		{
			std::cout << "not correct name or number!\n";
		}
	}
};
#endif