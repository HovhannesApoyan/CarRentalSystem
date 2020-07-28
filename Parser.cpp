#include "Parser.h"

Parser::Parser(std::string infoLine)
	:infoLine(infoLine)
{
}

void Parser::setInfoLine(const std::string& new_info_line)
{
	infoLine = new_info_line;
}

bool Parser::parsingNamePrice(std::string& name, double& price)
{
	auto it = std::find(infoLine.begin(), infoLine.end(), ' ');
	if (it != infoLine.end())
	{
		auto it_name = std::find(it + 1, infoLine.end(), ' ');
		if (it_name != infoLine.end())
		{
			name = std::string(it + 1, it_name);
			std::string strPrice(std::next(it_name), infoLine.end());
			int count = 0;
			for (int i = 0; i < strPrice.size(); ++i)
			{
				if (strPrice[i] == '.')
				{
					++count;
				}
				else if (!isdigit(strPrice[i]))
				{
					return false;
				}
			}
			if (count <= 1 && strPrice != ".")
			{
				price = std::stod(strPrice);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}