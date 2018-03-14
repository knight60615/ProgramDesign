#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 5000
int mystrcmp(const void*a,const void*b)
{
		return strcmp(*((char**)a),*((char**)b));
}
int mystrcmpd(const void*a,const void*b)
{
		return (-1)*strcmp(*((char**)a),*((char**)b));
}



int main(int argc, char *argv[]){
		int i,j=0,k/*,n=0*/,state=0;
		int fd=0,fu=0;
		char *buf,*file,**input,**output;
		FILE *fp;
		for (i = 1; i < argc; i++) {
				if (strcmp(argv[i], "-d") == 0 && fd == 0) fd = 1;
				else if (strcmp(argv[i], "-u") == 0 && fu == 0) fu = 1;
				else file = argv[i];
		}
		fp = fopen(file, "r");
		buf = (char *)malloc(sizeof(char)*MAXLEN);
		input=(char**)malloc(sizeof(char*)*MAXLEN);
	//	output=(char**)malloc(sizeof(char*)*MAXLEN);
		while(fgets(buf, MAXLEN, fp)) {
				input[j]=(char *)malloc(sizeof(char)*MAXLEN);
				strcpy(input[j],buf);
				j++;
		}
		fclose(fp);
		//		for(i=0;i<j;i++)
		//		printf("%s",input[i]);

		if(fd){
				qsort(input,j,sizeof(char*),mystrcmpd);
		}
		else {
				qsort(input,j,sizeof(char*),mystrcmp);
		}
		//		for(i=0;i<j;i++)
		//				printf("%s",input[i]);

		if(fu){

				for(i=0;i<j;i++){
						for(k=i+1;k<j;k++){
								if(strcmp(input[i],input[k])==0){
										state=1;
										break;
								}
						}
						if(state)
								state=0;

						else
								printf("%s",input[i]);

				}
		}
		else {
				for(i=0;i<j;i++)
						printf("%s",input[i]);
		}





		return 0;
}


