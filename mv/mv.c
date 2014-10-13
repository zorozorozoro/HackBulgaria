#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		return 1;
	}

	char* source = argv[1];
	char* destination = argv[2];

	FILE* finp = fopen(source, "r");

	int status;

	if(access(destination, F_OK) != -1) {
		printf("using cp\n");	
		char *buf;
		size_t sz;
		sz = snprintf(NULL, 0, "./cp %s %s w+", source, destination);
		buf = (char *)malloc(sz + 1); /* make sure you check for != NULL in real code */
		snprintf(buf, sz+1, "./cp %s %s w+", source, destination);
		
		status = system(buf);
		int status = system("./cp tst tst.2 w+");

		if (status != 0) {
			printf("error in mv, using cp\n");
		} else {
			int rmStatus = remove(source);

			if (rmStatus != 0) {
				printf("error removing source file");
				return 2;
			}
		}

		return status;

	} else {
		printf("using rename\n");
		status = rename(source, destination);
	
        if (status != 0) {
            printf("error in mv, using rename\n");
        }

	}

	return status;
}
