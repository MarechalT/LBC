#ifndef COLORS_H
#define COLORS_H

#include <string>

#define RST "\x1B[0m"
#define RED "\x1B[31m"
#define GRE "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYA "\x1B[36m"
#define WHI "\x1B[37m"

std::string fred(std::string x) {
	return RED + x + RST;
}
std::string fgre(std::string x) {
	return GRE + x + RST;
}
std::string fyel(std::string x) {
	return YEL + x + RST;
}
std::string fblu(std::string x) {
	return BLU + x + RST;
}
std::string fmag(std::string x) {
	return MAG + x + RST;
}
std::string fcya(std::string x) {
	return CYA + x + RST;
}
std::string fwhi(std::string x) {
	return WHI + x + RST;
}

#endif
