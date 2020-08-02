#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
public:
	Parser() = default;
	bool parsingNamePrice(const std::string& info_line, std::string& name, double& price);
};
#endif
