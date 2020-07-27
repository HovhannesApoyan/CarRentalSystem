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
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		Parser parser(infoLine);
		std::string name;
		double price;
		if (parser.parsingNamePrice(name, price))
		{
			Car car(name, price);
			auto find_it = std::find(cars_rentals.begin(), cars_rentals.end(), car);
			if (find_it != cars_rentals.end())
			{
				std::string commandLine;
				std::cout << "new name and price\n";
				if (getline(std::cin, commandLine))
				{
					commandLine.insert(0, "add ");
					parser.setInfoLine(commandLine);
					if (parser.parsingNamePrice(name, price))
					{
						find_it->setName(name);
						find_it->setPrice(price);
						FileManagement fileManagement;
						fileManagement.writeFile(cars_rentals);
					}
					else
					{
						std::cout << "not correct name or number!\n";
					}
				}
				else
				{
					std::cout << "Not edit!\n";
				}
			}
			else
			{
				std::cout << "Not found!\n";
			}
		}
		else
		{
			std::cout << "not correct name or number!\n";
		}
	}
};
#endif
