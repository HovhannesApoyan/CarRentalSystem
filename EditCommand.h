#pragma once
#ifndef EDIT_COMMAND_H
#define EDIT_COMMAND_H
#include "AbstractCommands.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "FileManagement.h"
#include "Parser.h"
#include "SearchCommand.h"

class EditCommand : public AbstractCommands
{
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override;
	bool inputNameAndPrice(std::string& commandLine, std::string& name1, double& price1);
};
#endif
