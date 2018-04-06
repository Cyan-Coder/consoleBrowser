#pragma once
#include <string>

enum colour {
	BLACK = 0x0000,
	DARK_BLUE = 0x0001,
	DARK_GREEN = 0x0002,
	DARK_CYAN = 0x0003,
	DARK_RED = 0x0004,
	DARK_MAGENTA = 0x0005,
	DARK_YELLOW = 0x0006,
	GREY = 0x0007,
	DARK_GREY = 0x0008,
	BLUE = 0x0009,
	GREEN = 0x000A,
	CYAN = 0x000B,
	RED = 0x000C,
	MAGENTA = 0x000D,
	YELLOW = 0x000E,
	WHITE = 0x000F,
};	

class tag {
	std::string m_definition;
	colour m_fontColour = WHITE;
	colour m_backColour = BLACK;
};

class textTag : public tag {
	std::string contents;
};

class linkTag : public tag {
	std::string link;
	std::string name;
};