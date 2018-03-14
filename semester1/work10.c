#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxnum 100
void swap(int A[],int x,int y)
{
		int a;
		a=A[x];
		A[x]=A[y];
		A[y]=a;
}
void fswap(float A[],int x,int y)
{
		float a;
		a=A[x];
		A[x]=A[y];
		A[y]=a;
}
void swap2(char A[Maxnum][Maxnum],int x,int y)
{
		char TEMP[Maxnum][Maxnum];
		strcpy(TEMP[x],A[x]);
		strcpy(A[x],A[y]);
		strcpy(A[y],TEMP[x]);

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
		int A[Maxnum]={0},B[Maxnum]={0},C[Maxnum]={0},D[Maxnum]={0},a,b,c,d,x,i,j,k,c1,c2,c3,n,count;
		float c4=0,E[Maxnum]={0},maxE,minE;
		char search[Maxnum],N[Maxnum][Maxnum],s,t;
		a=b=c=d=c1=c2=c3=n=count=0;
		FILE *fp;
		fp=fopen("./testdata","r");

		while(fscanf(fp,"%s\t%d\t%d\t%d\t%d",&N[n++],&A[a++],&B[b++],&C[c++],&D[d++])!=EOF)
		{
		}

		printf("Name\t|No.\t|PD\t|Cal.\t|LA\t|Ave.\n-------------------------------------\n");
		for(x=0;x<a-1;x++)
		{		
				c1=c1+B[x];
				c2=c2+C[x];
				c3=c3+D[x];
				c4=c4+(float)(B[x]+C[x]+D[x])/3;
				E[x]=(float)(B[x]+C[x]+D[x])/3;
				printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);

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
		printf("-------------------------------------\n");
		printf("Ave.\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t\n",(float)c1/x,(float)c2/x,(float)c3/x,c4/x);
		printf("Max.\t|%d\t|%d\t|%d\t|%.2f\n",MAX(B,x-1),MAX(C,x-1),MAX(D,x-1),maxE);
		printf("Min.\t|%d\t|%d\t|%d\t|%.2f\n",MIN(B,x-1),MIN(C,x-1),MIN(D,x-1),minE);
		printf("依姓名排序\n");
		for(i=0;i<x-1;i++)
		{
				for(j=x-2-i;j<x-1;j++)
				{
						if(strcmp(N[j],N[j+1])>0)
						{
								swap2(N,j,j+1);
								swap(A,j,j+1);
								swap(B,j,j+1);
								swap(C,j,j+1);
								swap(D,j,j+1);
								fswap(E,j,j+1);

						}



						else
								break;
				}}

		for(x=0;x<a-1;x++)
				printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);



		printf("依平均排序\n");
		for(i=0;i<x-1;i++)
		{
				for(j=x-2-i;j<x-1;j++)
				{
						if(E[j]>E[j+1])
						{
								swap2(N,j,j+1);
								swap(A,j,j+1);
								swap(B,j,j+1);
								swap(C,j,j+1);
								swap(D,j,j+1);
								fswap(E,j,j+1);

						}
						else
								break;
				}}



		for(x=0;x<a-1;x++)
				printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);

		while(1){

				printf("請輸入欲查詢之項目\n1)名字\n2)座號\n3)PD\n4)Cal\n5)LA\n6)Ave.\n7)結束查詢\n");
				scanf(" %c",&s);
				switch(s){
						case'1':
								printf("請輸入欲查詢之字串\n");
								scanf("%s",&search);
								printf("搜尋結果 :\n-------------------------------------\n");
								for(x=0;x<a-1;x++)
								{
										if(strstr(N[x],search)!=0)
										{
												printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
												count++;
										}
										else
										{}
								}
								if(count==0)
										printf("查無此結果\n");
								break;
						case'2':
								printf("請輸入欲查詢之座號\n");
								scanf("%d",&k);
								printf("搜尋結果 :\n-------------------------------------\n");
								for(x=0;x<a-1;x++)
								{
										if(A[x]==k)
										{
												printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
												count++;
										}
										else
										{}
								}
								if(count==0)
										printf("查無此結果\n");
								break;
						case'3':
								printf("請輸入條件類別\n");
								printf("1)大於     >\n");
								printf("2)大於等於 >=\n");
								printf("3)等於     =\n");
								printf("4)小於等於 <=\n");
								printf("5)小於     <\n");
								scanf(" %c",&t);
								switch(t){
										case'1':scanf("%d",&k);
												printf("搜尋結果 :\n-------------------------------------\n");
												for(x=0;x<a-1;x++)
												{
														if(B[x]>k)
														{
																printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																count++;
														}
														else
														{}
												}
												if(count==0)
														printf("查無此結果\n");
												break;
										case'2':scanf("%d",&k);
												printf("搜尋結果 :\n-------------------------------------\n");
												for(x=0;x<a-1;x++)
												{
														if(B[x]>=k)
														{
																printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																count++;
														}
														else
														{}
												}
												if(count==0)
														printf("查無此結果\n");
												break;
										case'3':scanf("%d",&k);
												printf("搜尋結果 :\n-------------------------------------\n");
												for(x=0;x<a-1;x++)
												{
														if(B[x]==k)
														{
																printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																count++;
														}
														else
														{}
												}
												if(count==0)
														printf("查無此結果\n");
												break;
										case'4':scanf("%d",&k);
												printf("搜尋結果 :\n-------------------------------------\n");
												for(x=0;x<a-1;x++)
												{
														if(B[x]<=k)
														{
																printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																count++;
														}
														else
														{}
												}
												if(count==0)
														printf("查無此結果\n");
												break;
										case'5':scanf("%d",&k);
												printf("搜尋結果 :\n-------------------------------------\n");
												for(x=0;x<a-1;x++)
												{
														if(B[x]<k)
														{
																printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																count++;
														}
														else
														{}
												}
												if(count==0)
														printf("查無此結果\n");
												break;






								}
								break;

						case'4': printf("請輸入條件類別\n");
								 printf("1)大於     >\n");
								 printf("2)大於等於 >=\n");
								 printf("3)等於     =\n");
								 printf("4)小於等於 <=\n");
								 printf("5)小於     <\n");
								 scanf(" %c",&t);
								 switch(t){
										 case'1':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(C[x]>k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'2':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(C[x]>=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'3':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(C[x]==k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'4':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(C[x]<=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'5':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(C[x]<k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;}
								 break;

						case'5': printf("請輸入條件類別\n");
								 printf("1)大於     >\n");
								 printf("2)大於等於 >=\n");
								 printf("3)等於     =\n");
								 printf("4)小於等於 <=\n");
								 printf("5)小於     <\n");
								 scanf(" %c",&t);
								 switch(t){
										 case'1':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(D[x]>k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'2':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(D[x]>=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'3':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(D[x]==k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'4':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(D[x]<=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'5':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(D[x]<k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;
								 }
								 break;
						case'6': printf("請輸入條件類別\n");
								 printf("1)大於     >\n");
								 printf("2)大於等於 >=\n");
								 printf("3)等於     =\n");
								 printf("4)小於等於 <=\n");
								 printf("5)小於     <\n");
								 scanf(" %c",&t);
								 switch(t){
										 case'1':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(E[x]>k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'2':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(E[x]>=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'3':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(E[x]==k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'4':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(E[x]<=k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;

										 case'5':scanf("%d",&k);
												 printf("搜尋結果 :\n-------------------------------------\n");
												 for(x=0;x<a-1;x++)
												 {
														 if(E[x]<k)
														 {
																 printf("%s\t|%d\t|%d\t|%d\t|%d\t|%.2f\n",N[x],A[x],B[x],C[x],D[x],E[x]);
																 count++;
														 }
														 else
														 {}
												 }
												 if(count==0)
														 printf("查無此結果\n");
												 break;}
								 break;

						case'7':
								 return 0;




				}






		}

		return 0;

}

