#pragma once
#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H
#include "AbstractCommands.h"
#include "FileManagement.h"
#include "Parser.h"

class AddCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line)override
	{
		Parser parser;
		std::string name;
		double price;
		if (!parser.parsingNamePrice(info_line, name, price))
		{
			std::cout << "not correct name or number!\n";
			return;
		}
		Car car(name, price);
		cars_rentals.push_back(car);
		FileManagement fileManagement;
		fileManagement.writeFile(name, price);
	}
};
#endif