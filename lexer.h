#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

class lexer {
public:
	lexer(std::vector<char> source);

	std::string buffer;
	std::vector<char> source;
	std::vector<int> lexedFile;
	std::vector<char> lexedText;
	std::vector<std::string> textConcatted;
	bool wasChar = false;
	void readFile(const char *fileName);
	void stringToVectorArray();
	void lexFile();
};
