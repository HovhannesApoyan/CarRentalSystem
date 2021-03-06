#pragma once
#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H
#include "AbstractCommands.h"

class HelpCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override
	{
		if (std::find(info_line.begin(), info_line.end(), ' ') != info_line.end())
		{
			std::cout << "not correct print command!\n";
			return;
		}
		std::cout << "add [car_name, car_price]\n";
		std::cout << "delete [car_name, car_price]\n";
		std::cout << "print\n";
		std::cout << "exit Ctrl+Z\n";
	}
};
#endif
