#pragma once
#ifndef EDIT_COMMAND_H
#define EDIT_COMMAND_H
#include <iostream>
#include <vector>
#include "AbstractCommands.h"
#include "FileManagement.h"
#include "Parser.h"

class EditCommand : public AbstractCommands
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
		auto find_it = std::find(cars_rentals.begin(), cars_rentals.end(), car);
		if (find_it == cars_rentals.end())
		{
			std::cout << "Not found!\n";
			return;
		}
		std::string commandLine;
		std::cout << "new name and price\n";
		if (!getline(std::cin, commandLine))
		{
			std::cout << "Not edit!\n";
			return;
		}
		commandLine.insert(0, "add ");
		if (!parser.parsingNamePrice(commandLine, name, price))
		{
			std::cout << "not correct name or number!\n";
			return;
		}
		find_it->setName(name);
		find_it->setPrice(price);
		FileManagement fileManagement;
		fileManagement.writeFile(cars_rentals);
	}
};
#endif
