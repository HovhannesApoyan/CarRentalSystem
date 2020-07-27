#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
public:
	Parser(std::string infoLine);
	void setInfoLine(const std::string& new_info_line);
	bool parsingNamePrice(std::string& name, double& price);
private:
	std::string infoLine;
};
#endif
