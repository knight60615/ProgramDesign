#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <fcntl.h>
#include<ctype.h>

#define MAXLEN 1024
int main(int argc, char *argv[]){
	int i;
	int line;
	int fv = 0, fi = 0, fn = 0;
	char *buffer, *str, *pattern = NULL, *file = NULL;
	FILE *fp;

	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-v") == 0 && fv == 0) fv = 1;
		else if (strcmp(argv[i], "-i") == 0 && fi == 0) fi = 1;
		else if (strcmp(argv[i], "-n") == 0 && fn == 0) fn = 1;
		else if (pattern == NULL) pattern = argv[i];
		else file = argv[i];
	}

	fp = fopen(file, "r");

	buffer = (char *)malloc(MAXLEN);

	line = 1;

	while(fgets(buffer, MAXLEN, fp)) {
		if(fi) {
			str = strcasestr(buffer, pattern); 
		} else {
			str = strstr(buffer, pattern);
		}
		if((str != NULL && fv == 0) || (str == NULL && fv == 1)) {
			if(fn) printf("%d: ", line);
			printf("%s", buffer);
		}
		line ++;
	}
	fclose(fp);
	return 0;
}
