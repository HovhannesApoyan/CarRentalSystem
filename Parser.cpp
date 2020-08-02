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
	/*size_t sz_d;//TODO
	double p_d = std::stod(strPrice, &sz_d);
	if (strPrice[0] != '-' && sz_d == strPrice.size())
		price = p_d;*/
	for (int i = 0; i < strPrice.size(); ++i)
	{
		if (strPrice[i] == '.')
			++count;
		else if (!isdigit(strPrice[i]))
			return false;
		if (count > 1)
			return false;
	}
	if (strPrice == ".")
	{
		return false;
	}
	price = std::stod(strPrice);
	return true;
}