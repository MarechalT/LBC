#include <iostream>
#include <string>
#include <fstream>
#include "../color/color.h"

void readAndOutputData(std::istream& in) {
	for (std::string line; std::getline(in, line);) {
		for (std::string::reverse_iterator rit = line.rbegin();
				rit != line.rend(); ++rit) {
			std::cout << *rit;
		}
		std::cout << " " << fblu(std::to_string(line.size())) << std::endl;
	}
}

int main(int argc, char** argv) {

	if (argc > 1) {
		std::ifstream ifile(argv[1]);
		if (ifile) {
			readAndOutputData(ifile);
		}
		else{
			std::cerr << "Can't open the file: \"" << argv[1] <<"\""<< std::endl;
			exit;
		}
	} else {
		readAndOutputData(std::cin);
	}

	return 0;
}
