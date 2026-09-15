#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	if (strcmp(argv[1], "--tafara") == 0) {
		printf("Compiler - Ne My Lord👑\n");
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

    FILE *fptr = fopen(argv[1], "r");

	if (fptr == NULL) {
		printf("Failed to read from %s\n", argv[1]);
		return 0;
	}

	char* fileContents = NULL;
	size_t len = 0;
	ssize_t bytes = 0;
	ssize_t total_bytes = 0;

	while (TRUE) {
		bytes = getline(&fileContents, &len, fptr);
		if (bytes == -1) break;
		total_bytes += bytes;
	}

	if (total_bytes <= 0) {
		 printf("File is empty\n");
	 }

	if (!fileContents) free(fileContents);
	fclose(fptr);

	printf("\n%s\n", fileContents-(total_bytes*sizeof(char)));
	printf("\n%zd bytes read\n", total_bytes);
	printf("Compiling %s\n", argv[1]);

	return 0;

	
}
