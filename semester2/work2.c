#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 200
int main(int argc, char *argv[])
{
		int i=0,j,x;
		char buf[MAXLEN],*pattern[MAXLEN];
		char c;
		char *ptr,*ptr2,*hptr;
		FILE *fp;
		if(argc>0)
				fp = fopen(argv[1], "r");
		if(fp==NULL){				
				printf("fopen failed");
				return 0;
		}

		while(fgets(buf, MAXLEN, fp)) {
				pattern[i]=(char*)malloc(sizeof(char)*(strlen(buf)+1));
				buf[strlen(buf)-1]='\0';
				strcpy(*(pattern+i),buf);
				i++;					//把txt一行一行存進陣列
		}
		while(1)
		{
				char input[MAXLEN]={'\0'};//每次回圈開始初始化input
				printf("請輸入字串:");
				x=0;
				while((c=getchar())!='\n')
				{
						input[x]=c;
						x++;
						if (c==EOF)
								return 5;
				}						//輸入的句子存入input 避免scanf自動切割的問題
				hptr=input;
				for(j=0;j<i;j++)
				{
						ptr=strstr(input,pattern[j]);//逐一比對
						if(ptr!=NULL)				//比對成功 跳出
								break;
				}
				if(ptr!=NULL)
				{
				while(hptr<ptr)
						putchar(*hptr++);		//印到目標前
				printf("*%s*",pattern[j]);		//tag目標字串
				ptr2=ptr+strlen(pattern[j]);	//目標字串結尾
				while(*ptr2!='\0')
						putchar(*ptr2++);
						printf("\n");
						}						//印到結束
						else if(ptr==NULL){		//防呆 比對失敗直接印出無tag
								while(*hptr!='\0')
										putchar(*hptr++);
										printf("\n");}
		}
		return 0; 
}
