#include<stdio.h>
int main()
{
		while(1){
		float a,b;
		scanf("%f %f",&a,&b);
        if (a==0&&b==0){return 0;}
		
				printf("%f+%f=%f\n",a,b,a+b);
				printf("%f-%f=%f\n",a,b,a-b);
				printf("%f*%f=%f\n",a,b,a*b);
				if(b!=0){
						printf("%f/%f=%f\n",a,b,a/b);}
				if(b==0){
						printf("%f/%f doesn't exist");}
						
		
		
		
		
				
		}
		return 0;
		}
				
