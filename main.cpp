#include "preprocessor.h"
#include "lexer.h"
#include "utilities.h"

int main() {
	std::vector<char> source = util::readFile("test.chtml");

	preprocessor pre(source);
	pre.run();

	for (directive d : pre.getDirectives())
	{
		std::cout << d.name << " : " << d.content << "\n";
	};

	lexer lex(source);
	lex.lexFile();
	for (std::string s : lex.getStructeredFile()) {
		std::cout << s << "\n";
	};
	system("PAUSE");
};
