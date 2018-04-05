#include "lexer.h"

int main() {
	lexer lex;
	lex.readFile("test.chtml");
	lex.stringToVectorArray();
	lex.lexFile();

	for (int i = 0; i < lex.textConcatted.size(); i++)
	{
		std::cout << lex.textConcatted.at(i) << "\n";
	};
	system("PAUSE");
};