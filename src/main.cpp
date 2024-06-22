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
			("lines,l", "count lines")
			("words,w", "count words")
			("multibytes,m", "count multi bytes")
			("bytes,c", "count bytes")
			("file", po::value<std::string>(), "input file");

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

		std::string file_string = vm.count("file") ? readFromFile(vm["file"].as<std::string>()) : readFromStdin();
		bool count_lines = vm.count("lines");
		bool count_words = vm.count("words");
		bool count_multibytes = vm.count("multibytes");
		bool count_bytes = vm.count("bytes");
		bool show_file = vm.count("file");
		if (!(count_lines || count_words || count_bytes || count_multibytes)) {
			count_lines = count_words = count_bytes = true;
		}
        std::cout << "hello world\n";
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	} catch (...) {
		std::cerr << "Exception of unknown type!\n";
		return 1;
	}

	return 0;
}