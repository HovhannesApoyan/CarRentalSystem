#pragma once
#ifndef DELETE_COMMAND_H
#define DELETE_COMMAND_H
#include "AbstractCommands.h"
#include "FileManagement.h"

class DeleteCommand : public AbstractCommands
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
		cars_rentals.erase(std::remove_if(cars_rentals.begin(), cars_rentals.end(), [=](const Car& c1)
			{
				return c1.name() == name && c1.price() == price;
			}
		), cars_rentals.end());

		FileManagement fileManagement;
		fileManagement.writeFile(cars_rentals);
	}
};
#endif
