#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "tag.h"

//the class of the lexer
class lexer {
	//public members
public:
	//definition of the constructor
	lexer(std::vector<char> source);
	
	//definitions of the members
	int offset;
	std::string current;
	std::string buffer;
	std::vector<char> source;
	std::vector<std::string> structuredFile;
	bool isInTag = false;
	bool skipLine = false;
	void lexFile();
	std::vector<std::string> getStructeredFile();
};
