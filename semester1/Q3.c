#include<stdio.h>
#include<string.h>
void swap(int A[],int x,int y)
{
		int a;
		a=A[x];
		A[x]=A[y];
		A[y]=a;
}


int main()
{
		int a=0,j,x,B[100],t,i,sum=0;
		B[100]=(0);
		char A[100][100];
		while(scanf(" %s",&A[a++])!=EOF)
		{}
		for(j=0;j<a-1;j++)
		{
				if(atoi(A[j])==0)
				{
				for(x=0;x<100;x++){
			/*	if(atoi(A[j][x])!=0)
						break;

				}
				for(i=x;i<100;i++){
						int k=0;
						k=k+atoi(A[j][x]);
						 B[j]=k;
						  sum=sum+k;
						}}
						else*/
				t=atoi(A[j]);
				B[j]=t;
				sum=sum+t;
		//		printf("%d\n",B[j]);
		}
		for(i=0;i<a-1;i++)
		{
				for(j=a-2-i;j<a-1;j++)
				{
						if(B[j]<B[j+1])
						{
								swap(B,j,j+1);
						}

						else
								break;
				}}


		for(i=1;i<a;i++)
		{
				printf("%d\n",B[i]);
		}
		printf("ензб:%.2f\n",(float)sum/(a-1));




		return 0;
}
