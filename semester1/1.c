


#include<stdio.h>

int main()
{
		int i,lower,upper,step,search;
		printf("lower:");
		scanf("%d",&lower);
		getchar();
		printf("upper:");
		scanf("%d",&upper);
		getchar();
		printf("step:");
		scanf("%d",&step);
		getchar();
		printf("���\t|�ؤ�\t\n");
		printf("-------------------\n");
		for(i=lower;i<=upper;i+=step)
		{
				printf("%d\t|%.2f\n",i,(float)(i*1.8)+32);	
		}
		while(1)
		{
				printf("���:");
				scanf("%d",&search);
				if(search<0)break;
				printf("�ؤ�:%.2f\n",(float)(search*1.8)+32);
		}
		return 0;

}
