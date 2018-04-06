#include "lexer.h"
#include "utilities.h"

int main() {
	std::vector<char> source = util::readFile("test.chtml");

	lexer lex(source);
	lex.lexFile();

	for (int i = 0; i < lex.textConcatted.size(); i++)
	{
		std::cout << lex.textConcatted.at(i) << "\n";
	};
	system("PAUSE");
};
