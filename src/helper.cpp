#include "helper.hpp"

std::string readFromFile(const std::string &filename) {
	std::ifstream ifs(filename);
	std::ostringstream oss;
	oss << ifs.rdbuf();
	return oss.str();
}

std::string readFromStdin() {
	std::ostringstream oss;
	oss << std::cin.rdbuf();
	return oss.str();
}

std::string applyNumberEffect(std::string &s) {
	std::istringstream input(s);
	std::ostringstream oss;
	std::string line = "";
	int lineNumber = 1;
	for(int i = 0; i < ssize(s); i++) {
		while(i < ssize(s) && s[i] != '\n') line += s[i++];
		oss << std::setw(6) << lineNumber++ << "\t" << line;
		if(i < ssize(s) && s[i] == '\n') oss << s[i];
		line = "";
	}
	return oss.str();
}

std::string applyNonBlankNumberEffect(std::string &s) {
	std::istringstream input(s);
	std::ostringstream oss;
	std::string line = "";
	int lineNumber = 1;
	for(int i = 0; i < ssize(s); i++) {
		while(i < ssize(s) && s[i] != '\n') line += s[i++];
		if(ssize(line)) oss << std::setw(6) << lineNumber++ << "\t" << line;
		if(i < ssize(s) && s[i] == '\n') oss << s[i];
		line = "";
	}
	return oss.str();
}