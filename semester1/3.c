/*
�мg�@�ӵ{��comd�Ncommand line���r��@�H�U�B�z
-r�N�᭱����Ӧr�����æC�L�X
   >./comd -r apple banana
   ananab elppa
-s �N�᭱���arguments��@��Ƭۥ[
    > ./comd -s 1022 203
    1225

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
		int i,sum=0,len,j;
		if(argv[1][1]=='r')
				
		{
				for(i=argc-1;i>=2;i--)
				{
						len=strlen(argv[i]);
						for(j=len-1;j>=0;j--)
						printf("%c",argv[i][j]);
						if(i==argc-1)printf(" ");
				}
		}
		if(argv[1][1]=='s')
		{
				for(i=2;i<argc;i++)
				{
						sum+=atoi(argv[i]);	
				}
				printf("%d\n",sum);
		}
		return 0;
}
