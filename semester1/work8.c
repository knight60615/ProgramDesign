#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void array_init(int A[], int num)
{
		int x,y;
		srand(time(NULL));
		for(x=0;x<num;x++)
		{
				y=(rand()%200000)+(-100000);
				A[x]=y;
				/*printf("The Random Number is %d .\n", A[x]);*/
		}

}

int isSorted(int A[], int num)
{
		int x;
		for(x=0;x<num-1;x++)
		{
				if(A[x]>A[x+1])
						return 0;
		}
		return 1;
}

void swap(int A[],int x,int y)
{
		int a;
		a=A[x];
		A[x]=A[y];
		A[y]=a;
}

int main()
{
		int n,i,j,B[1000000]={0},I[1000000]={0};
		printf("請輸入欲產生之亂數數量\n");
		scanf("%d",&n);
		array_init(B,n);
		for(i=0;i<n;i++)
				I[i]=B[i];
		double start, end;
		start = (double) clock() / CLOCKS_PER_SEC;
		for(i=0;i<n;i++)
		{
				for(j=0;j<n-1-i;j++)
				{
						if(B[j]>B[j+1])
								swap(B,j,j+1);
				}
		}//bubblesort
		//for(i=0;i<10000000;i++);
		end = (double) clock() / CLOCKS_PER_SEC;
		printf("Bubblesort:");
		//for(i=0;i<n;i++)
		//		printf("%d ",B[i]);
		printf("\t用時:%1f\n",end-start);
		start = (double) clock() / CLOCKS_PER_SEC;
		for(i=0;i<n-1;i++)
		{
				for(j=n-2-i;j<n-1;j++)
				{
						if(I[j]>I[j+1])
								swap(I,j,j+1);
						else
								break;
				}}//insertionsort
		end = (double) clock() / CLOCKS_PER_SEC;
		printf("Insertionsort:");
		//for(i=0;i<n;i++)
		//		printf("%d ",I[i]);
		printf("\t用時:%1f\n",end-start);

		isSorted(B,n);
		printf("Bubblesort:%d\n",isSorted(B,n));
		isSorted(I,n);
		printf("Insertionsort:%d\n",isSorted(I,n));

		while(1){
				int search,check=-1,pos;
				printf("請輸入欲查詢數字：\n");
				scanf("%d",&search);
				if(search==B[n/2])
						{check=1;
						pos=n/2;}
				else
				{
						for(i=n/2;i<n;i++)
						{if(B[i]==search)
								{check=1;
								pos=i;
										break;}}
						for(i=n/2;i>0;i--)
						{if(B[i]==search)
								{check=1;
								pos=i;
										break;}}
				}
				if(check==1)
						printf("exist at the position %d\n",pos);
				else if(check==-1)
						printf("doesn't exist\n");
		}



		return 0;
}
