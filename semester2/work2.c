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
				i++;					//��txt�@��@��s�i�}�C
		}
		while(1)
		{
				char input[MAXLEN]={'\0'};//�C���^��}�l��l��input
				printf("�п�J�r��:");
				x=0;
				while((c=getchar())!='\n')
				{
						input[x]=c;
						x++;
						if (c==EOF)
								return 5;
				}						//��J���y�l�s�Jinput �קKscanf�۰ʤ��Ϊ����D
				hptr=input;
				for(j=0;j<i;j++)
				{
						ptr=strstr(input,pattern[j]);//�v�@���
						if(ptr!=NULL)				//��令�\ ���X
								break;
				}
				if(ptr!=NULL)
				{
				while(hptr<ptr)
						putchar(*hptr++);		//�L��ؼЫe
				printf("*%s*",pattern[j]);		//tag�ؼЦr��
				ptr2=ptr+strlen(pattern[j]);	//�ؼЦr�굲��
				while(*ptr2!='\0')
						putchar(*ptr2++);
						printf("\n");
						}						//�L�쵲��
						else if(ptr==NULL){		//���b ��異�Ѫ����L�X�Ltag
								while(*hptr!='\0')
										putchar(*hptr++);
										printf("\n");}
		}
		return 0; 
}
