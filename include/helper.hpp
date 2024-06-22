#ifndef HELPER_HPP
#define HELPER_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

std::string readFromFile(const std::string &filename);

std::string readFromStdin();

std::string applyNumberEffect(std::string &s);

std::string applyNonBlankNumberEffect(std::string &s);

#endif