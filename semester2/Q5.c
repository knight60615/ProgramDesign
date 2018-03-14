#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxword 1000
int main(int argc, char *argv[])
{
		FILE *fp;
		fp=fopen(argv[1],"r");
		int length=0;
		char buf[Maxword],longword[Maxword]={0};
while(fscanf(fp,"%s",buf)!=EOF){
if(strlen(buf)>strlen(longword))
		strcpy(longword,buf);


}
printf("%s\n",longword);

		return 0;
}
