#pragma once

#include <string>

// This represents the type of the token.
// This can be used to check for syntactic accuracy.
enum tokentype
{
	START_TAG,
	END_TAG,
	TEXT
};

struct token
{
	tokentype type;
	std::string value;
};
