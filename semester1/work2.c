#include<stdio.h>
int main()
{
		int lower,upper,step,search;
		float celsius,fahr;
		printf("�п�Jlower upper step\n");
		scanf("%d %d %d",&lower,&upper,&step);
		celsius=lower;
		printf("���\t|�ؤ�\n-----------------\n");
		if(celsius<-273)
		{
				printf("error\n");
				return 0;
		}
		if((lower>upper)&&(step>0))
		{
				printf("error\n");
				return 0;
		}
		if((lower<=upper)&&(step<0))
		{
				 printf("error\n");
				 return 0;
				  }

		while(celsius<=upper){
				fahr=(9.0/5.0)*celsius+32;
				printf("%.0f\t|%4.2f\n",celsius,fahr);
				celsius=celsius+step;
		}
		if((lower>upper)&&(step<0))
		{
		 while(celsius>upper){
				fahr=(9.0/5.0)*celsius+32;
				printf("%.0f\t|%4.2f\n",celsius,fahr);
				celsius=celsius+step;
		}

		}
		while(1)
		{
				printf("�п�J�n�d�ߪ��ū�\n");
				scanf("%d",&search);
				if((step>0)&&(search<=upper)&&(search>=lower))
				{
						printf("%.2f\n",search*(9.0/5.0)+32);
				}
				if((step<0)&&(search>=upper)&&(search<=lower))
				{
						printf("%.2f\n",search*(9.0/5.0)+32);
				}
				if((step>0)&&((search>upper)||(search<lower)))
				{
						printf("�A�d���!\n");
						break;
				}
				if((step<0)&&((search<upper)||(search>lower)))
						 {
						 		 printf("�A�d���!\n");
						 		 break;
						 }

		}


return 0;
}
