#include "lexer.h"

lexer::lexer(std::vector<char> source)
	: source(source)
{
}

void lexer::lexFile() {
	for (int i = 0; i < source.size(); i++) {
		//check for <p>, </p>, <a>, </a> or character
		if (source.at(i) == '@')
		{
			skipLine = true;
		}
		if (skipLine)
		{
			if (source.at(i) == '\n')
			{
				skipLine = false;
			}
			continue;
		}
		if (source.at(i) == '<') {
			//<p>
			if ((source.at(i + 1) == 'p' || source.at(i + 1) == 'P') && source.at(i + 2) == '>') {
				this->lexedFile.push_back(1);
				i += 2;
				wasChar = false;
			}//</p>
			else if ((source.at(i + 1) == '/') && (source.at(i + 2) == 'p' || source.at(i + 2) == 'P') && source.at(i + 3) == '>') {
				this->lexedFile.push_back(2);
				i += 3;
				wasChar = false;
			}//<a>
			else if ((source.at(i + 1) == 'a' || source.at(i + 1) == 'A') && source.at(i + 2) == '>') {
				this->lexedFile.push_back(3);
				i += 2;
				wasChar = false;
			}//</a>
			else if (source.at(i + 1) == '/' && (source.at(i + 2) == 'a' || source.at(i + 2) == 'A') && source.at(i + 3) == '>') {
				this->lexedFile.push_back(4);
				i += 3;
				wasChar = false;
			};
		}
		else {//character
				//this is used so the array isn't filled with lots of 0's but just one 0
			if (!wasChar) {
				//put a dummy character '~' between the different pieces of text
				this->lexedText.push_back('~');
				this->lexedText.push_back(source.at(i));
				this->lexedFile.push_back(0);
				wasChar = true;
			}
			else {
				this->lexedText.push_back(source.at(i));
			};
		};
	};
	std::string text = "";
	//making the strings complete again
	for (int i = 0; i < lexedText.size(); i++) {
		if (lexedText.at(i) == '~') {
			textConcatted.push_back(text);
			text = "";
		}
		else {
			text += lexedText.at(i);
		};
	};
	textConcatted.push_back(text);
	//remove the empty string at the start and the index' filled with "\n"
	//moving backwards through the array because we are deleting elements
	for (int i = textConcatted.size() - 1; i >= 0; i--) {
		if (textConcatted.at(i) == "" || textConcatted.at(i) == "\n") {
			textConcatted.erase(textConcatted.begin() + i);
		};
	};
};

