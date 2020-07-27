#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
public:
	Parser(std::string infoLine);
	bool parsingNamePrice(std::string& name, double& price);
private:
	std::string infoLine;
};
#endif
