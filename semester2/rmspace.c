#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	int issp = 0;
	int c;
	FILE *fp = fopen(argv[1], "r");
	
	// Ū���C�@�Ӧr��
	while((c = fgetc(fp)) != EOF) {
		if(c == ' ') {

			// �P�_�s��ť�
			if(issp == 1)
				continue;
			issp = 1;
		} else 
			issp = 0; 
		
		// �L�X��
		fputc(c, stdout);
	}
	
	fclose(fp);
	return 0;
}
