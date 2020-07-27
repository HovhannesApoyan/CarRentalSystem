#pragma once
#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H
#include "AbstractCommands.h"

class HelpCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		if (std::find(infoLine.begin(), infoLine.end(), ' ') == infoLine.end())
		{
			std::cout << "add [car_name, car_price]\n";
			std::cout << "delete [car_name, car_price]\n";
			std::cout << "print\n";
			std::cout << "exit Ctrl+Z\n";
		}
		else
		{
			std::cout << "not correct print command!\n";
		}
	}
};
#endif
