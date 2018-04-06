#include "preprocessor.h"

preprocessor::preprocessor(std::vector<char> source)
	: source(source)
{
}

void preprocessor::run()
{
	while (readPointer < source.size())
	{
		char c = readChar();
		if (c == '@')
		{
			std::string name = readName();
			std::string content = readLine();
			directive dir(name, content);
			directives.push_back(dir);
		}
	}
}

char preprocessor::readChar()
{
	return source[readPointer++];
}

std::string preprocessor::readName()
{
	std::string res;
	char c;
	while ((c = readChar()) != ' ')
	{
		res += c;
	}
	return res;
}

std::string preprocessor::readLine()
{
	std::string res;
	char c;
	while ((c = readChar()) != '\n')
	{
		res += c;
	}
	return res;
	return std::string();
}

directive::directive(std::string name, std::string content)
	: name(name), content(content)
{
}
