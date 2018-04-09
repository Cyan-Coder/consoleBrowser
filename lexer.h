#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "tag.h"
#include "token.h"

//the class of the lexer
class lexer {
	//public members
public:
	//definition of the constructor
	lexer(std::vector<char> source);

	//definitions of the members
	int pointer = 0;
	int line = 0;
	std::vector<char> source;
	std::vector<token> lexer::lexFile();
private:
	char readChar();
	bool ignore(char c);
	std::string readTag();
	std::string readText();
};
