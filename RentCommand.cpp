#include "RentCommand.h"

void RentCommand::executeCommand(std::vector<Car>& cars_rentals, std::string& info_line, std::vector<Car>& cars)
{
	std::string name1;
	double price1;
	SearchCommand search;
	search.executeCommand(cars_rentals, info_line, cars);

	cars_rentals.erase(std::remove_if(cars_rentals.begin(), cars_rentals.end(),
		[=](const Car& car) {return car.name() == cars[0].name() && car.price() == cars[0].price(); }),
		cars_rentals.end());

	FileManagement fileManagement;
	fileManagement.writeFile(cars_rentals);
	fileManagement.addToFile("rented_cars.txt", cars);
}