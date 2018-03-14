#include<stdio.h>
int main()
{
		int a,b,c;
		for(a=1;a<=5;a++)
		{
				if(a<=3)
					{
					 for(b=0;b<=(3-a);b++)
						{printf(" ");}
			 	   	 for(c=1;c<=(a*2-1);c++)
						printf("*");
					 for(b=0;b<=(3-a);b++)
					  	{printf(" ");}
					  	printf("\n");
							}
				if(a>3&&a<=5)
				{
					 for(b=0;b<=(a-3);b++)
					    {printf(" ");}
					 for(c=1;c<=(2*(5-a)+1);c++)
					 	printf("*");
					 for(b=0;b<=(a-3);b++)
					 	{printf(" ");}
					 	printf("\n");
					 		       
				}}		//以上菱形
		 for(a=1;a<=5;a++)
		 {
		 		 for(b=0;b<=(5-a);b++)
		 		 	printf(" ");
		 		 for(c=1;c<=(a*2-1);c++)
		 		 	printf("*");
		 		 for(b=0;b<=(5-a);b++)
		 		 	 printf(" ");
		 		 	 printf("\n");
		 				 }//以上三角形
		 for(a=1;a<=5;a++)
		 {
		 	 if(a==1||a==5)
		 		 for(b=1;b<=5;b++)
				   printf("*");
			 else
			 {
			 	printf("*");
			 	for(b=2;b<=4;b++)
			 	printf(" ");
			 	printf("*");
			 		 }
		    	printf("\n");
		 		 }//以上正方形
		 for(a=25;a>0;a--)
		 {
		 		 for(b=0;b<=5;b++)
				 {
				 	if(b==0||a==(b*b))
				 	printf("*");
				 	else
				 	printf(" ");
				 		 }
		 	     printf("\n");
		 		 }
		 for(b=0;b<=25;b++)
		 printf("*");
		 printf("\n");





		return 0;
}
