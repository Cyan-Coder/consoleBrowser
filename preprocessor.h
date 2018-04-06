#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

class directive
{
public:
	directive(std::string name, std::string content);
public:
	const std::string name;
	const std::string content;
};


class preprocessor
{
public:
	preprocessor(std::vector<char> source);

	void run();

	std::vector<directive> getDirectives() {
		return directives;
	}
private:
	std::vector<directive> directives;

	std::vector<char> source;
	int readPointer = 0;

	char readChar();
	std::string readName();
	std::string readLine();
};
