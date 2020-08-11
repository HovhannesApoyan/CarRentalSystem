#include "EditCommand.h"

void EditCommand::executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars)
{
	std::string name1;
	double price1;
	SearchCommand search;
	search.executeCommand(cars_rentals, info_line, cars);

	std::string commandLine;
	if (inputNameAndPrice(commandLine, name1, price1))
	{
		Car car(name1, price1);
		std::replace_if(cars_rentals.begin(), cars_rentals.end(), [=](const Car& c)
			{
				return c.name() == cars[0].name() && c.price() == cars[0].price();
			}
		, car);
		FileManagement fileManagement;
		fileManagement.writeFile(cars_rentals);
	}
}

bool EditCommand::inputNameAndPrice(std::string& commandLine, std::string& name1, double& price1)
{
	Parser parser;
	std::cout << "new name and price\n";
	if (!getline(std::cin, commandLine))
	{
		std::cout << "Not edit!\n";
		return false;
	}
	commandLine.insert(0, "add ");
	if (!parser.parsingNamePrice(commandLine, name1, price1))
	{
		std::cout << "not correct name or number!\n";
		return false;
	}
	return true;
}