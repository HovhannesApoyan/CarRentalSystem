#include "FileManagement.h"

FileManagement::FileManagement()
{
}

void FileManagement::writeFile(const std::vector<Car>& cars_rentals)
{
	myfile.open("data.txt", std::ifstream::out | std::ifstream::trunc);
	myfile.clear();
	for (auto it = cars_rentals.begin(); it != cars_rentals.end(); ++it)
	{
		myfile << it->name() << "/" << it->price() << "\n";
	}
	myfile.close();
}

void FileManagement::writeFile(const std::string& name, const double price)
{
	myfile.open("data.txt", std::ios::in | std::ios::app | std::ios::binary);
	myfile << name << "/";
	myfile << price << "\n";
	myfile.close();
}

std::vector<Car> FileManagement::readFile(std::ifstream& myfile)
{
	std::vector<Car> cars_rentals;
	std::string str;
	while (myfile >> str)
	{
		auto it = std::find(str.begin(), str.end(), '/');
		std::string old_name(str.begin(), it);
		double old_price = std::stod(std::string(std::next(it), str.end()));
		Car car(old_name, old_price);
		cars_rentals.push_back(car);
	}
	return cars_rentals;
}