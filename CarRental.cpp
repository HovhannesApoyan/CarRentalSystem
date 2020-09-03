#include "CarRental.h"

CarRental::CarRental()
	:abstract_commands_ptr(nullptr)
	, add_command(new AddCommand)
	, rent_command(new RentCommand)
	, delete_command(new DeleteCommand)
	, print_command(new PrintCommand)
	, help_command(new HelpCommand)
	, exit_command(new ExitCommand)
	, search_command(new SearchCommand)
	, edit_command(new EditCommand)
{
	commands_map.insert(std::make_pair("add", add_command));
	commands_map.insert(std::make_pair("rent", rent_command));
	commands_map.insert(std::make_pair("delete", delete_command));
	commands_map.insert(std::make_pair("print", print_command));
	commands_map.insert(std::make_pair("help", help_command));
	commands_map.insert(std::make_pair("exit", exit_command));
	commands_map.insert(std::make_pair("search", search_command));
	commands_map.insert(std::make_pair("edit", edit_command));

	FileManagement fileManagement;
	std::ifstream myfile("data.txt");
	cars_rentals = fileManagement.readFile(myfile);
}

void CarRental::execute()
{
	std::string commandLine;
	std::cout << "command: ";
	while (getline(std::cin, commandLine))
	{
		std::vector<Car> car;
		auto it_command = std::find(commandLine.begin(), commandLine.end(), ' ');
		std::string command(commandLine.begin(), it_command);
		std::map<std::string, AbstractCommands*>::iterator it_map = commands_map.find(command);
		if (it_map != commands_map.end())
		{
			abstract_commands_ptr = it_map->second;
			abstract_commands_ptr->executeCommand(cars_rentals, commandLine, car);
		}
		else
		{
			std::cout << "not correct command!\n";
		}
		std::cout << "command: ";
	}
}

std::string CarRental::name()const
{
	return name_;
}

double CarRental::price()const
{
	return price_;
}

CarRental::~CarRental()
{
	delete abstract_commands_ptr;
	delete add_command;
	delete delete_command;
	delete print_command;
	delete help_command;
	delete search_command;
	delete edit_command;
	delete exit_command;
}