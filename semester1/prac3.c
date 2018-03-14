#include<stdio.h>
#include<string.h>
int main()
{
char a[100]={0},b[100]={0};
while (1){
scanf("%s %s",&a,&b);
if(strlen(a)>strlen(b))
		printf("%s,%s",a,b);
		else
				 printf("%s,%s\n",b,a);
		
}return 0;
}
