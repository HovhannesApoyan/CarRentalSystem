#pragma once
#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H
#include <vector>
#include <fstream>
#include "Car.h"

class FileManagement
{
public:
	FileManagement();
	void writeFile(const std::vector<Car>& cars_rentals);
	void addToFile(const std::string& path, const std::vector<Car>& cars_rentals);
	void writeFile(const std::string& name, const double price);
	std::vector<Car> readFile(std::ifstream& myfile);
private:
	std::ofstream myfile;
};
#endif
