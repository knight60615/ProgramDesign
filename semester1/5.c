#include<stdio.h>
#include<string.h>

int main()
{
int i,j,count=0;
char *token,temp[100];
char str[100],save[100][100];
while(fgets(str,100,stdin)!=NULL)
{
token=strtok(str," .\n");
while(token!=NULL)
{
if(token[0]>='A'&&token[0]<='Z')
{
strcpy(save[count],token);		
count++;
}
token=strtok(NULL," .\n");
}
}
printf("The count is %d.\n",count);
for(j=0;j<count;j++)
for(i=j;i<count-1;i++)
{
    if(save[i][0]>save[i+1][0])
	{
	strcpy(temp,save[i]);
	strcpy(save[i],save[i+1]);
	strcpy(save[i+1],temp);
	}
}

for(i=0;i<count;i++)
		printf("%s\n",save[i]);
		

}

