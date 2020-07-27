#pragma once
#ifndef PRINT_COMMAND
#define PRINT_COMMAND
#include <iostream>
#include "AbstractCommands.h"

class PrintCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		if (std::find(infoLine.begin(), infoLine.end(), ' ') == infoLine.end())
		{
			for (auto el : cars_rentals)
			{
				std::cout << el.name() << " " << el.price() << "\n";
			}
		}
		else
		{
			std::cout << "not correct print command!\n";
		}
	}
};
#endif
