#include "preprocessor.h"
#include "lexer.h"
#include "utilities.h"

int main() {
	std::vector<char> source = util::readFile("test.chtml");

	preprocessor pre(source);
	pre.run();

	//for (directive d : pre.getDirectives())
	//{
	//	std::cout << d.name << " : " << d.content << "\n";
	//};

	lexer lex(source);
	std::vector<token> tokens = lex.lexFile();

	for (token t : tokens) {
		std::cout << t.type << " (" << t.value << ")\n";
	};

	system("PAUSE");
};
