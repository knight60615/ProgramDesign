#include<stdio.h>
#include<string.h>
#define MAXLEN 200
int main()
{
		char buf[MAXLEN],search[MAXLEN];
		char A[MAXLEN][MAXLEN],B[MAXLEN][MAXLEN];
		FILE *fp;
		int i=0,x,y,z,s1,s2,state=0;
		fp = fopen("dict.txt", "r");
		while(fgets(buf, MAXLEN, fp)) {
				strcpy(*(A+i),buf);
				//			printf("%s\n",*(A+i));
				i++;
		}
		for(x=0;x<i;x++)
		{
				for(y=0;y<=MAXLEN;y++)
				{
						if(A[x][y]=='\t')
								break;
				}
				for(z=0;z<=MAXLEN;z++)
				{
						B[x][z]=A[x][y+1];
						y++;
						if(A[x][y+1]=='\n'){
								 B[x][z]='\0';
								break;}
				}
//						printf("%s\n",*(B+x));
		}


		for(x=0;x<i;x++)
		{
				for(y=0;y<=MAXLEN;y++)
				{
						if(A[x][y]=='\t')
						{A[x][y]='\0';
								break;}
				}
//							printf("%s\n",*(A+x));
		}
		while(1)
		{
				printf("Please input query:");
				scanf("%s",search);
				for(x=0;x<i;x++)
				{
						s1=strcasecmp(A[x],search);
						s2=strcmp(B[x],search);
						if(s1==0)
						{
								state=1;
								printf("%s\n",B[x]);
						}
						else if(s2==0)
						{
								state=1;
								printf("%s\n",A[x]);
						}

				}
				if(state==0)
						printf("¬dµL¦¹¦r\n");
						state=0;
		}
		return 0;
}

