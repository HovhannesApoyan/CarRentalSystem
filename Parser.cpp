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
	for (int i = 0; i < strPrice.size(); ++i)
	{
		if (strPrice[i] == '.')
		{
			++count;
			is_integer = false;
			if (count == 1)
				continue;
		}
		else if (!isdigit(strPrice[i]))
			return false;

		if (count > 1)
			return false;
		if (is_integer)
			price = price * 10 + static_cast<double>(strPrice[i]) - '0';
		else
		{
			price = price + (static_cast<double>(strPrice[i]) - '0') * q;
			q /= 10;
		}
	}
	if (strPrice == ".")
		return false;
	return true;
}