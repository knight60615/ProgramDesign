#include<stdio.h>

int main()
{
int i,j,n;
char a[100][100];
scanf("%d",&n);
//getchar();
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++)
	{
	if(i==j)a[i][j]='X';
	else if(i+j==(n-1))
		a[i][j]='X';
	
	}

}
for(j=0;j<n;j++)
{
		for(i=0;i<n;i++)
		{
		  if(a[i][j]=='X')		
          printf("%c",a[i][j]);
          else printf(" ");
		}
		printf("\n");
}
}
