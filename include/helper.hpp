#ifndef HELPER_HPP
#define HELPER_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string readFromFile(const std::string &filename);

std::string readFromStdin();

// int countLines(std::string &s);

// int countWords(std::string &s);

// int countBytes(std::string &s);

// int countMultiBytes(const std::string &s);

#endif