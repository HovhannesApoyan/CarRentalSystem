#pragma once
#ifndef CAR_RENTAL_H
#define CAR_RENTAL_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "Car.h"
#include "FileManagement.h"
#include "AbstractCommands.h"
#include "AddCommand.h"
#include "DeleteCommand.h"
#include "PrintCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"

class CarRental
{
public:
	CarRental();
	std::string name()const;
	double price()const;
	void execute();
	virtual ~CarRental();
private:
	explicit CarRental(std::string name, const double price);
private:
	std::string name_;
	double price_;
	std::vector<Car> cars_rentals;
	std::map<std::string, AbstractCommands*> commands_map;
private:
	AbstractCommands* abstract_commands_ptr;
	AddCommand* add_command;
	DeleteCommand* delete_command;
	PrintCommand* print_command;
	HelpCommand* help_command;
	ExitCommand* exit_command;
};
#endif
