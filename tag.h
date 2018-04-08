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

//base class for every tag
class tag {
	//definition e.g. <p>
	std::string m_definition;
	//colour of the characters on page
	colour m_fontColour = WHITE;
	//colour of the background of the characters
	colour m_backColour;
	//unsigned integer that states how many tags are nested within
	unsigned int m_howManyNested;
public:
	//getters
	colour getFontColour() {
		//returns the font colour
		return m_fontColour;
	};

	colour getBackColour() {
		//returns the background colour
		return m_backColour;
	};

	unsigned int getHowManyNested() {
		//returns how many tags are nested within
		return m_howManyNested;
	};

	//setters
	void setFontColour(colour input) {
		//sets the font colour
		m_fontColour = input;
	};

	void setBackColour(colour input) {
		//set the background colour
		m_backColour = input;
	};

	void setHowManyNested(unsigned int input) {
		//sets how many nested tags are within
		m_howManyNested = input;
	};
};

//a text tag is a tag that only contains text and font colours
class textTag : public tag {
	//the contents of the text in this case the text written between the two tags
	std::string m_contents;

	//constructor of the textTag
	textTag(colour fontColour, colour backColour)
	{
		setFontColour(fontColour);
		setBackColour(backColour);
	}
};

//link tag is a tag that contains text, a hyperlink and font colours
class linkTag : public tag {
	//hyperlink
	std::string m_link;
	//content contains the text between the two tags
	std::string m_content;
	//constructor of the linkTag
	linkTag(colour fontColour, colour backColour){
		setFontColour(fontColour);
		setBackColour(backColour);
	}
};
