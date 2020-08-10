#pragma once
#ifndef PRINT_COMMAND
#define PRINT_COMMAND
#include <iostream>
#include "AbstractCommands.h"

class PrintCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override
	{
		if (std::find(info_line.begin(), info_line.end(), ' ') != info_line.end())
		{
			std::cout << "not correct print command!\n";
			return;
		}
		if (cars_rentals.empty())
			std::cout << "cars_rentals is empty\n";
		for (auto el : cars_rentals)
		{
			std::cout << el.name() << " " << el.price() << "\n";
		}
	}
};
#endif
