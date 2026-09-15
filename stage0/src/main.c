#include <stdio.h>
#include <string.h>

#define VERSION "0.0.1"
#define EXTENSION ".kr"
#define TRUE 1

int main(int argc, char** argv) {
	// Nothing to do
	if (argc < 2) {
		printf("Nothing to do, use \"--help\" for help\n");
		return 0;
	}

	// Version
	if (strcmp(argv[1], "--version") == 0) {
		printf("Compiler - %s\n", VERSION);
		return 0;
	} 

	// Help
	if (strcmp(argv[1], "--help") == 0) {
		printf("Compiler - A smol compiler\n" 
						"--version\tCompiler version\n"
						"--help\t\tCompiler help\n");
		return 0;
	} 

	// Open file
	char* it = argv[1];
	char* last_match = NULL;
	
	while (TRUE) {
		char *match = strstr(it, EXTENSION);
		if (match == NULL) break;
		it += strlen(match);
		last_match = match;
	}

	if (!last_match) { 
		printf("Source code must live in \"%s\" files\n", EXTENSION);
		return 0;
	}


	if (strlen(last_match)-strlen(EXTENSION) > 0) {
		printf("Source code must live in \"%s\" files\n", EXTENSION);
		return 0;
	}

	printf("Compiling %s\n", argv[1]);
	return 0;
}
