#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1024

int main(int argc, char *argv[]){
		int i,line=0;
		int fi=0,fc=0;
		char *buffer, *str, *pattern = NULL, *file = NULL;
		FILE *fp;
		for (i = 1; i < argc; i++) {
				if (strcmp(argv[i], "-i") == 0 && fi == 0) fi = 1;
				else if (strcmp(argv[i], "-c") == 0 && fc == 0) fc = 1;
				else if (pattern == NULL) pattern = argv[i];
				else file = argv[i];
		}
		fp = fopen(file, "r");

		buffer = (char *)malloc(MAXLEN);
		while(fgets(buffer, MAXLEN, fp)) {
				if(fi) {
						str = strcasestr(buffer, pattern);
				} else {
						str = strstr(buffer, pattern);
				}
				if(str!=NULL&&fc==0)
				printf("%s", buffer);
				 if(str!=NULL&&fc==1){
				 		 line++;
		}


		
}

		if(fc)
		 printf("%d", line);
fclose(fp);






return 0;
}
