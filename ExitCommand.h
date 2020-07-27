#pragma once
#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H
#include "AbstractCommands.h"

class ExitCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine)override
	{
		if (std::find(infoLine.begin(), infoLine.end(), ' ') == infoLine.end())
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
