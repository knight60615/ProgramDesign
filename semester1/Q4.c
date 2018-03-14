#include<stdio.h>
#include<string.h>
#define OUT 0
#define IN 1
#define Maxword 64

int main()
{
		int c,i=0,state,length,sec;
		char cword[Maxword]={0},longword[Maxword]={0},secword[Maxword]={0};
		state=OUT;
		while ((c=getchar())!=EOF)
		{
				if (c=='\n'||c==' '||c=='\t'){
						state=OUT;
						cword[i]='\0';
						length=strlen(cword);
						if(length>strlen(longword)){
								sec=strlen(longword);
								strcpy(secword,longword);
								strcpy(longword,cword);}
						if(length>strlen(secword)&&length<strlen(longword)){
								sec=strlen(cword);
								strcpy(secword,cword);}


						i=0;
				}
				else if (state==OUT){
						state=IN;
						cword[i]=c;i++;
				}
				else {
						cword[i]=c;i++;
				}
		}
		printf("最長的字:%s\n第二的字:%s\n",longword,secword);
		return 0;





}

