#pragma once
#ifndef ABSTRACT_COMMANDS_H
#define ABSTRACT_COMMANDS_H
#include <vector>
#include "Car.h"

class AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& infoLine) = 0;
	virtual ~AbstractCommands()
	{

	}
};
#endif
