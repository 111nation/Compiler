#include <stdio.h>

#define VERSION "0.0.1"

int main(int argc, char** argv) {
	if (argc > 0) {
		printf("Compiler - %s\nUse switch -h for help\n", VERSION);
		return 0;
	}

	return 0;
}
