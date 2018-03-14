#include<stdio.h>
#include<stdlib.h>
#define Maxnum 100
void swap(int A[],int x,int y)
{
		int a;
		a=A[x];
		A[x]=A[y];
		A[y]=a;
}
void inssort(int A[],int x)
{
		int i,j;
		for(i=0;i<x-1;i++)
		{
				for(j=x-2-i;j<x-1;j++)
				{
						if(A[j]>A[j+1])
								swap(A,j,j+1);
						else
								break;
				}}
}
/*void mg(int A[],int B[],int C[],int D[], int low1, int high1, int low2, int high2)
{
		int leftp = low1, rightp = low2, sp = 0;
		while(leftp < high1 && rightp < high2) {
				if(A[leftp] <= A[rightp]) {
						tmp1[sp++] = A[leftp++];
						tmp2[sp++] = B[leftp++];
						tmp3[sp++] = C[leftp++];
						tmp4[sp++] = D[leftp++];
				}
				else {
						tmp1[sp++] = A[rightp++];
						tmp2[sp++] = B[rightp++];
						tmp3[sp++] = C[rightp++];
						tmp4[sp++] = D[rightp++];
				}
		}
		if(leftp== high1 && rightp < high2)
		{
				tmp1[sp++] = A[rightp++];
				tmp2[sp++] = B[rightp++];
				tmp3[sp++] = C[rightp++];
				tmp4[sp++] = D[rightp++];
		}
		else if(rightp== high2 && leftp < high1)
		{
				tmp1[sp++] = A[leftp++];
				tmp2[sp++] = B[leftp++];
				tmp3[sp++] = C[leftp++];
				tmp4[sp++] = D[leftp++];
		}
}




void mgsort(int A[],int B[],int C[],int D[], int low, int high)
{
		int i,j;
		for(i=low;i<(low+high)/2-1;i++)
		{
				for(j=(low+high)/2-1-2-low;j<(low+high)/2-1;j++)
				{
						if(A[j]>A[j+1]){
								swap(A,j,j+1);
								swap(B,j,j+1);
								swap(C,j,j+1);
								swap(D,j,j+1);

						}
						else
								break;
				}}
		for(i=(low+high)/2+1;i<high-1;i++)
		{
				for(j=high-2-((low+high)/2+1);j<high-1;j++)
				{
						if(A[j]>A[j+1]){
								swap(A,j,j+1);
								swap(B,j,j+1);
								swap(C,j,j+1);
								swap(D,j,j+1);

						}
						else
								break;
				}}
		mg(A,B,C,D, low, (low + high) / 2, (low + high) / 2 + 1, high);
}*/


int MAX(int A[],int x)
{
		int i,max;
		for(i=0;i<x-1;i++)
		{
				if (i==0)
						max=A[0];
				if (A[i]>=max){
						max=A[i];}
		}
		return max;
}
int MIN(int A[],int x)
{
		int i,min;
		for(i=0;i<x-1;i++)
		{
				if (i==0)
						min=A[0];
				if (A[i]<=min){
						min=A[i];}
		}
		return min;
}


int main()
{
		int A[Maxnum]={0},B[Maxnum]={0},C[Maxnum]={0},D[Maxnum]={0},a,b,c,d,x,i,j,c1,c2,c3;
		float c4=0,E[Maxnum]={0},maxE,minE,t;
		char k;
		a=b=c=d=c1=c2=c3=0;
		FILE *fp;
		fp=fopen("testdata.txt","r");

		while(fscanf(fp,"%d\t%d\t%d\t%d",&A[a++],&B[b++],&C[c++],&D[d++])!=EOF)
		{
		}

		printf("No.\t|PD\t|Cal.\t|LA\t|Ave.\n-------------------------------------\n");
		for(x=0;x<a-1;x++)
		{		
				c1=c1+B[x];
				c2=c2+C[x];
				c3=c3+D[x];
				c4=c4+(float)(B[x]+C[x]+D[x])/3;
				E[x]=(float)(B[x]+C[x]+D[x])/3;
				printf("%d\t|%d\t|%d\t|%d\t|%.2f\n",A[x],B[x],C[x],D[x],E[x]);

		}
		for(i=0;i<x-1;i++)
		{
				if (i==0)
						maxE=minE=E[0];
				if (E[i]>=maxE){
						maxE=E[i];}
				if (E[i]<=minE){
						minE=E[i];}

		}

		printf("Ave.\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t\n",(float)c1/x,(float)c2/x,(float)c3/x,c4/x);
		printf("Max.\t|%d\t|%d\t|%d\t|%.2f\n",MAX(B,x-1),MAX(C,x-1),MAX(D,x-1),maxE);
		printf("Min.\t|%d\t|%d\t|%d\t|%.2f\n",MIN(B,x-1),MIN(C,x-1),MIN(D,x-1),minE);
		printf("選擇欲排列項目\n");
		printf("1) PD\n2) Cal\n3) LA\n4) Average\n");
		scanf("%c",&k);
		switch(k)
		{
				case'1':for(i=0;i<x-1;i++)
						{
								for(j=x-2-i;j<x-1;j++)
								{
										if(B[j]>B[j+1])
										{
												swap(A,j,j+1);
												swap(B,j,j+1);
												swap(C,j,j+1);
												swap(D,j,j+1);
												t=E[j];
												E[j]=E[j+1];
												E[j+1]=t;
										}

										else
												break;
								}}break;
				case'2':for(i=0;i<x-1;i++)
						{
								for(j=x-2-i;j<x-1;j++)
								{
										if(C[j]>C[j+1])
										{
												swap(A,j,j+1);
												swap(B,j,j+1);
												swap(C,j,j+1);
												swap(D,j,j+1);
												t=E[j];
												E[j]=E[j+1];
												E[j+1]=t;
										}
										else
												break;
								}}break;
				case'3':for(i=0;i<x-1;i++)
						{
								for(j=x-2-i;j<x-1;j++)
								{
										if(D[j]>D[j+1])
										{
												swap(A,j,j+1);
												swap(B,j,j+1);
												swap(C,j,j+1);
												swap(D,j,j+1);
												t=E[j];
												E[j]=E[j+1];
												E[j+1]=t;
										}
										else
												break;
								}}break;
				case'4':for(i=0;i<x-1;i++)
						{
								for(j=x-2-i;j<x-1;j++)
								{
										if(E[j]>E[j+1])
										{
												swap(A,j,j+1);
												swap(B,j,j+1);
												swap(C,j,j+1);
												swap(D,j,j+1);
												t=E[j];
												E[j]=E[j+1];
												E[j+1]=t;
										}
										else
												break;
								}}break;


		}
		for(x=0;x<a-1;x++)
				printf("%d\t|%d\t|%d\t|%d\t|%.2f\n",A[x],B[x],C[x],D[x],E[x]);




		return 0;

}
