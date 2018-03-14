#include<stdio.h>
int main()
{
		int a,b,c,mid;
		float ave;
		scanf("%d %d %d",&a,&b,&c);
		if(a>b&&a>c)
		{if(b>c)
		mid=b;
		else
				mid=c;}
				else if(b>a&&b>c)
				{if(a>c)
				mid=a;
				else
						mid=c;}
						 else if(c>a&&c>b)
						 {if(b>a)
						 mid=b;
						 else
						 		 mid=a;}

						 		 ave=(a+b+c)/3.000;
						 		 printf("mid=%d,ave=%.3f",mid,ave);

return 0;
}
