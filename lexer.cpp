#include "lexer.h"

//constructor of the lexer class
lexer::lexer(std::vector<char> source)
	: source(source)
{
};

//function that lexes the file
std::vector<token> lexer::lexFile() {
	std::vector<token> res;

	// Keep reading until we reach the end of the file.
	while (pointer < source.size()) {
		char c = readChar();
		if (ignore(c)) continue;
		// Found a tag.
		if (c == '<') {
			if (readChar() == '/') {
				// Found end tag.
				// We subtract 2 from the pointer because we read 2 characters before
				// and we want to make sure that these appear in the output.
				pointer -= 2;
				std::string tag = readTag();
				token token = {
					END_TAG,
					tag
				};
				res.push_back(token);
			}
			else {
				// Found a start tag.
				// We subtract 2 from the pointer because we read 2 characters before
				// and we want to make sure that these appear in the output.
				pointer -= 2;
				std::string tag = readTag();
				token token = {
					START_TAG,
					tag
				};
				res.push_back(token);
			};
		}
		else {
			// We found some text that the user wants to display.
			// Subtract 1 from the pointer so that we include the one character
			// that we read at the top of this function.
			pointer--;
			std::string text = readText();
			token token = {
				TEXT,
				text
			};
			res.push_back(token);
		};
	};

	return res;
};

std::string lexer::readTag() {
	std::string res;
	char c;
	while ((c = readChar()) != '>') {
		res += c;
	}
	res += '>';
	return res;
};

std::string lexer::readText() {
	std::string res;
	char c;
	bool loop = true;
	while (loop) {
		c = readChar();
		// This symbol could either be included in the text, or signal
		// the start of a tag and therefore the end of the text.
		if (c == '<') {
			// If there is no space after the < symbol we will assume
			// that this is the start of a tag.
			if (readChar() != ' ') {
				loop = false;
			}
			else {
				// If there is a space, the user wants to output this
				// symbol to the screen, so add it to the text.
				res += c;
			};
			// Subtract one from the pointer to compensate reading a char
			// in the if statement above.
			pointer--;
		}
		else {
			res += c;
		};
	};
	pointer--;
	return res;
};

char lexer::readChar() {
	char c = source[pointer++];
	if (c == '\n') {
		line++;
	};
	return c;
};

bool lexer::ignore(char c) {
	return c == '\n' || c == '\t' || c == ' ' || c == '\r';
};
