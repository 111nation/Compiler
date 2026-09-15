#include <stdio.h>
#include <string.h>

#define VERSION "0.0.1"

int main(int argc, char** argv) {
	if (argc <= 1) {
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

	printf("Invalid command\nUse \"--help\" for help\n");
	return 0;
}
