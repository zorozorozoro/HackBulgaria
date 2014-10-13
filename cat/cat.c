#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Invalid number of args");
	}

	char* source = argv[1];

	FILE* fd = fopen(source, "r");

	if (fd == 0) {
		printf("Unable to open file %s", source);
		return 1;
	}

	int x;

	while ((x = fgetc(fd)) != EOF) {
		printf("%c", x);
	}

	return 0;
}
