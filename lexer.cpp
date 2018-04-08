#include "lexer.h"

//constructor of the lexer class
lexer::lexer(std::vector<char> source)
	: source(source)
{
};

std::vector<std::string> lexer::getStructeredFile() {
	//returns the structured file vector
	return structuredFile;
};

//function that lexes the file
void lexer::lexFile() {
	//check the intire content of the file
	for (int i = 0; i < source.size(); i++) {
		//check for preprocessor statements
		//pps starts with @
		if (source.at(i) == '@')
		{
			skipLine = true;
		};
		if (skipLine)
		{
			if (source.at(i) == '\n')
			{
				skipLine = false;
			};
			continue;
		};
		//search for a tag
		if (source.at(i) == '<') {
			offset = 0;
			current = "";
			while (source.at(i + offset) != '>') {
				current += source.at(i + offset);
				offset++;
			};
			current += '>';
			structuredFile.push_back(current);
			i += offset;
		}
		else if (source.at(i) == '\n') {
			continue;
		}//it is a character
		else {
			offset = 0;
			current = "";
			while (source.at(i + offset) != '<') {
				current += source.at(i + offset);
				offset++;
			};
			structuredFile.push_back(current);
			i += offset - 1;
		};
	};
};
