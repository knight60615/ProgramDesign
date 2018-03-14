#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	int issp = 0;
	int c;
	FILE *fp = fopen(argv[1], "r");
	
	// 讀取每一個字元
	while((c = fgetc(fp)) != EOF) {
		if(c == ' ') {

			// 判斷連續空白
			if(issp == 1)
				continue;
			issp = 1;
		} else 
			issp = 0; 
		
		// 印出來
		fputc(c, stdout);
	}
	
	fclose(fp);
	return 0;
}
