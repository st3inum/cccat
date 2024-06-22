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