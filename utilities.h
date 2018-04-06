#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

namespace util {
	static std::vector<char> readFile(const char *fileName) {
		std::ifstream file(fileName);
		if (file.fail()) {
			std::cerr << "error whilst opening file (" << fileName << ")\n";
			system("PAUSE");
			std::exit(1);
		};
		std::ostringstream content;

		if (file) {
			content << file.rdbuf();
			file.close();
		};
		std::vector<char> res;
		for (int i = 0; i < content.str().size(); i++) {
			res.push_back(content.str().at(i));
		};
		return res;
	}
}