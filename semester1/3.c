/*
請寫一個程式comd將command line的字串作以下處理
-r將後面的兩個字串倒轉並列印出
   >./comd -r apple banana
   ananab elppa
-s 將後面兩個arguments當作整數相加
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
