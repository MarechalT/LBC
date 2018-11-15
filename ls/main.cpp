#include <iostream>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

void displayVector(const std::vector<char*> &vc) {
	for (std::vector<char*>::const_iterator it = vc.begin(); it != vc.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void finishSlash(std::string &dir){
	if(dir.back() == '/')
		return;
	else
		dir.push_back('/');
}

int main(int argc, char** argv) {
	std::string directory=".";
	if(argc>1){
		directory = argv[1];
	}


	DIR *dir;
	struct dirent *ent;
	std::vector<char*> entries;
	if ((dir = opendir(directory.c_str())) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			entries.push_back(ent->d_name);
		}
		std::sort(entries.begin(),entries.end(),strcmp);
		displayVector(entries);
		closedir(dir);
	} else {
		std::cerr << "Could not open the directory" << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}
