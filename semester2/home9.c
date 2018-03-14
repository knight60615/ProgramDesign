#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *tbin(char A)
{
		static char bin[8]={0};
		unsigned char mask=0x80;
		int i;
		for(i=0;i<8;i++)
		{
				if(A & mask) bin[i]='1';
				else bin[i]='0';
                mask >>= 1;
		}
		bin[8]='\0';
		return bin;
}
int main(int argc,char *argv[])
{
		int i,state;
		FILE *fp;
		char c;
		char *tmp;
		fp=fopen(argv[1],"r");
		if(fp==NULL)
		{
				printf("error!\n");
				exit(0);
		}
		state=0;
		while((c=fgetc(fp))!=EOF)
		{
			//	if(c=='\n') continue;
				tmp=tbin(c);
				for(i=0;i<8;i++)
				{
						if((state==0)&&(tmp[i]=='0')) printf("A");
						else if((state==1)&&(tmp[i]=='0'))
						{
								printf("B");
								state=0;
						}
						else if((state==2)&&(tmp[i]=='0'))
						{
								printf("C");
								state=0;
						}
						else if((state==2)&&(tmp[i]=='1'))
						{
								printf("D");
								state=0;
						}
						else if(tmp[i]=='1') state++;
				}
		}
		printf("\n");
		return 0;
}


