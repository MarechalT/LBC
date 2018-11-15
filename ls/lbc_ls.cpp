#include <iostream>
#include <dirent.h>
#include <string>
#include <map>
#include "../color/color.h"

void displayMap(const std::map<std::string, unsigned char> &mc) {
	for (std::map<std::string, unsigned char>::const_iterator it = mc.begin();
			it != mc.end(); it++) {
		switch (it->second) {
		case DT_UNKNOWN:
			std::cout << fred(it->first) << fred(" Unknown type") << std::endl;
			break;
		case DT_REG:
			std::cout << it->first << " File" << std::endl;
			break;
		case DT_DIR:
			std::cout << fblu(it->first) << fblu(" Dir") << std::endl;
			break;
		case DT_FIFO:
			std::cout << fcya(it->first) << fcya(" FIFO") << std::endl;
			break;
		case DT_SOCK:
			std::cout << fgre(it->first) << fgre(" Sock") << std::endl;
			break;
		case DT_CHR:
			std::cout << fyel(it->first) << fyel(" Char dev") << std::endl;
			break;
		case DT_BLK:
			std::cout << fyel(it->first) << fyel(" Block dev") << std::endl;
			break;
		case DT_LNK:
			std::cout << fcya(it->first) << fcya(" SymLink") << std::endl;
			break;
		default:
			std::cout << fred(it->first) << fred(" Unknown type") << std::endl;
			break;
		}
	}
}

int main(int argc, char** argv) {
	//get the input directory path to list
	std::string directory = "./";
	if (argc > 1) {
		directory = argv[1];
	}

	DIR *dir;
	struct dirent *ent;
	//map containing the name and type of file (provided by readdir())
	std::map<std::string, unsigned char> entries;
	if ((dir = opendir(directory.c_str())) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			entries.insert(
					std::pair<std::string, unsigned char>(ent->d_name,
							ent->d_type));
		}
		displayMap(entries);
		closedir(dir);
	} else {
		std::cerr << "Could not open the directory" << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}
