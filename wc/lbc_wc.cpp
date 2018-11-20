#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../color/color.h"

int countWords(const char* pstr) {
	int count = 0;
	int len = 0;
	if (pstr == nullptr) {
		return 0;
	}
	while (*pstr) {
		if (*pstr == ' ') {
			len = 0;
		} else if (++len == 1) {
			count++;
		}
		pstr++;
	}

	return count;
}

int countWordsStream(const std::string &s) {
	std::istringstream iss(s);
	std::string temp;
	int cnt = 0;
	while (iss >> temp)
		cnt++;
	return cnt;
}

void count(std::string filename) {
	int lineCount = 0, wordCount = 0, charCount = 0, wordCount2 = 0;
	std::ifstream fs;
	fs.open(filename);
	if (!fs) {
		std::cerr << "Couldn't open " << filename << std::endl;
		exit(1);
	}
	std::string s;
	while (getline(fs, s)) {
		lineCount++;
		charCount += s.length()+1; // add the '\n' because getline function specifty: If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).
		wordCount += countWords(s.c_str());
		wordCount2 += countWordsStream(s);
	}
	fs.close();

	std::cout << fred("L: " + std::to_string(lineCount)) << fblu("\tW: " + std::to_string(wordCount)) <<
			fcya("\tW2: " +std::to_string(wordCount2)) << fgre("\tC: " + std::to_string(charCount))
			<< ":\t" << filename << std::endl;

}

int main(int argc, char** argv) {

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			count(argv[i]);
		}
	} else {
		std::cerr << "No arguments provide" << std::endl;
	}

	return 0;
}
