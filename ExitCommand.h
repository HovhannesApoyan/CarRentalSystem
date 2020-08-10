#pragma once
#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H
#include "AbstractCommands.h"

class ExitCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override
	{
		if (std::find(info_line.begin(), info_line.end(), ' ') == info_line.end())
		{
			exit(1);
		}
		else
		{
			std::cout << "not correct print command!\n";
		}
	}
};
#endif
