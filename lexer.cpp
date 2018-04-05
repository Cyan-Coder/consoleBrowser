#include "lexer.h"

std::ostringstream content;
std::string buffer;
std::vector<char> lexArray;
std::vector<int> lexedFile;
std::vector<char> lexedText;
std::vector<std::string> textConcatted;

bool wasChar = false;

//read the file
void lexer::readFile(const char *fileName) {
	std::ifstream file(fileName);
	if (file.fail()) {
		std::cerr << "error whilst opening file\n";
		system("PAUSE");
		std::exit(1);
	};

	if (file) {
		content << file.rdbuf();
		file.close();
	};
};

//change the sting into an vector array
void lexer::stringToVectorArray() {
	for (int i = 0; i < content.str().size(); i++) {
		this->lexArray.push_back(content.str().at(i));
	};
};

void lexer::lexFile() {
	for (int i = 0; i < lexArray.size(); i++) {
		//check for <p>, </p>, <a>, </a> or character
		if (lexArray.at(i) == '<') {
			//<p>
			if ((lexArray.at(i + 1) == 'p' || lexArray.at(i + 1) == 'P') && lexArray.at(i + 2) == '>') {
				this->lexedFile.push_back(1);
				i += 2;
				wasChar = false;
			}//</p>
			else if ((lexArray.at(i + 1) == '/') && (lexArray.at(i + 2) == 'p' || lexArray.at(i + 2) == 'P') && lexArray.at(i + 3) == '>') {
				this->lexedFile.push_back(2);
				i += 3;
				wasChar = false;
			}//<a>
			else if ((lexArray.at(i + 1) == 'a' || lexArray.at(i + 1) == 'A') && lexArray.at(i + 2) == '>') {
				this->lexedFile.push_back(3);
				i += 2;
				wasChar = false;
			}//</a>
			else if (lexArray.at(i + 1) == '/' && (lexArray.at(i + 2) == 'a' || lexArray.at(i + 2) == 'A') && lexArray.at(i + 3) == '>') {
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
				this->lexedText.push_back(lexArray.at(i));
				this->lexedFile.push_back(0);
				wasChar = true;
			}
			else {
				this->lexedText.push_back(lexArray.at(i));
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