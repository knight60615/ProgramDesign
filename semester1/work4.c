#include<stdio.h>
int main()
{
		int k,max,min,i,A[300],sum;
		float average;
		printf("�п�J��X�Ӽ�\n");
		scanf("%d",&k);
		sum=0;
		for(i=0;i<k;i++)
		{
		scanf("%d",&A[i]);
		if (i==0)
				min=max=A[0];
		sum=sum+A[i];
				if (A[i]<=min){
						min=A[i];}
						if (A[i]>=max){
								 max=A[i];}
		}
		average=(float)sum/(float)k;
		printf("�Ӽ�:%d\n",k);
		for(i=0;i<k;i++)
		printf("A[%d]:%d\n",i,A[i]);
		printf("------------\n");
		printf("min:%d\n",min);
		printf("max:%d\n",max);
		printf("average:%.2f\n",average);
		return 0;
}
