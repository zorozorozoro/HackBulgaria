#include <stdio.h>


int main(int argc, char *argv[])
{
	if (argc != 4) {
		return 1;
	}

	FILE* finp = fopen(argv[1], "r");
	FILE* fout = fopen(argv[2], argv[3]);	

	if (finp == 0 || fout == 0) {
		printf("Could not open file\n");
		return 1;
	}
	
	int x;

	while ((x = fgetc(finp)) != EOF) {
		fputc(x, fout);
	}

	fclose(finp);
	fclose(fout);

    return 0;
}
