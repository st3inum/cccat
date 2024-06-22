#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "helper.hpp"

namespace po = boost::program_options;

int main(int argc, char *argv[]) {
	try {
		po::options_description desc("Allowed options");
		desc.add_options()
			("help,h", "produce help message")
			("number-nonblank,b", "number nonempty output lines, overrides -n")
			("number,n", "number all output lines")
			("file", po::value<std::vector<std::string>>()->multitoken(), "input file(s)");

		po::positional_options_description p;
		p.add("file", -1);

		po::variables_map vm;
		po::store(
			po::command_line_parser(argc, argv).options(desc).positional(p).run(),
			vm);
		po::notify(vm);

		if (vm.count("help")) {
			std::cout << desc << "\n";
			return 1;
		}
		bool showNumber = vm.count("number");
		bool showNonBlankNumber = vm.count("number-nonblank");
		// if (vm.count("number-nonblank")) {
		// 	std::cout << "-b (number nonempty output lines) was set.\n";
		// }
		// if (vm.count("number")) {
		// 	std::cout << "-n (number all output lines) was set.\n";
		// }

		std::string file_string = "";
		if (vm.count("file")) {
			std::vector<std::string> files = vm["file"].as<std::vector<std::string>>();
			for (const auto &file : files) {
				// std::cout << "file name: " << file << '\n';
				if(file == "-") {
					file_string += readFromStdin();
				} else {
					file_string += readFromFile(file);
				}
			}
		} else {
			file_string += readFromStdin();
		}

		if(showNonBlankNumber) {
			std::cout << applyNonBlankNumberEffect(file_string);
		} else if(showNumber) {
			std::cout << applyNumberEffect(file_string);
		} else {
			std::cout << file_string;
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	} catch (...) {
		std::cerr << "Exception of unknown type!\n";
		return 1;
	}

	return 0;
}