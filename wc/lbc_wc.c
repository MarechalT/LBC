#include <stdio.h>
#include <ctype.h>
void count(const char *str) {
	int numC = 0;
	int numW = 0;
	int numL = 0;
	FILE *fptr;
	fptr = fopen(str, "r");
	if (fptr == NULL) {
		printf("Error opening %s", str);
		return;
	} else {
		char c;
		int spaceBefore = 1;
		while ((c = getc(fptr)) != EOF) {
			numC++;
			if (c == '\n')
				numL++;
			if (isspace(c))
				spaceBefore = 1;
			else {
				if (spaceBefore) {
					spaceBefore = 0;
					numW++;
				}
			}
		}
	}
	fclose(fptr);
	printf("\t%d\t%d\t%d\t%s\n", numL, numW, numC, str);
}

int main(int argc, char* argv[]) {

	if (argc > 1) {
		int i = 0;
		while (++i < argc) {
			count(argv[i]);
		}
	}

	return 0;
}
