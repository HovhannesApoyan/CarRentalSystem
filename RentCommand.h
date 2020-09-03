#pragma once
#include "AbstractCommands.h"
#include "SearchCommand.h"
#include "FileManagement.h"

class  RentCommand : public AbstractCommands {
public:
	virtual void executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars) override;
};