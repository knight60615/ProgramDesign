#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *binary(char key,char *code)		//轉二進位
{
		int k;
		unsigned char mask=0x80;	//128(10000000)
		for(k=0;k<8;k++)
		{
				if(key & mask) code[k]='1';
				else code[k]='0';
				mask >>= 1;
		}
		code[8]='\0';
		return code;
}
int main(int argc, char *argv[])
{
		int i,state=0;
		char code[8];
		FILE *fp;
		char /*c,*/*p;
		int c;
		if (argc>1)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				printf("fopen failed\n");
				return 0;
		}
		while((c=fgetc(fp))!=EOF)		//一次讀入一個字元
		{			
				p=binary(c,code);
				i=0;
//				printf("%s\n",p);
				while(i<8){
						if((state==0)&&(p[i]=='0')){
								printf("A");
								state=0;
								i++;
						}
						else if((state==0)&&(p[i]=='1')){
								state=1;
								i++;
						}
						else if((state==1)&&(p[i]=='0')){
								printf("B");
								state=0;
								i++;
						}
						else if((state==1)&&(p[i]=='1')){
								state=2;
								i++;
						}
						else if((state==2)&&(p[i]=='0')){
								printf("C");
								state=0;
								i++;
						}
						else if((state==2)&&(p[i]=='1')){
								printf("D");
								state=0;
								i++;
						}
				}
		}
		printf("\n");
		return 0;
}
