#include "Parser.h"

bool Parser::parsingNamePrice(const std::string& info_line, std::string& name, double& price)
{
	auto it = std::find(info_line.begin(), info_line.end(), ' ');
	if (it == info_line.end())
	{
		return false;
	}
	auto it_name = std::find(it + 1, info_line.end(), ' ');
	if (it_name == info_line.end())
	{
		return false;
	}
	name = std::string(it + 1, it_name);
	std::string strPrice(std::next(it_name), info_line.end());

	int count = 0;
	bool is_integer = true;
	double q = 0.1;
	price = 0;
	try {
		price = boost::lexical_cast<double>(strPrice);
	}
	catch (const boost::bad_lexical_cast& e) 
	{
		std::cout << "Exception caught : " << e.what() << "\n";
		return false;
	}
	return true;
}