#include<stdio.h>
void two(int i)
{
		int k,m;
		for(k=31;k>=0;k--)
		{m=((i>>k) &1);
		printf("%d",m);}

}
int main()
{
		int a,b;
		char c;
		printf("輸入#將數字轉為二進位\n    +將兩數字相加\n    -將兩數字相減\n    *將兩數字相乘\n    /將兩數字相除\n    %%將兩數字相除後顯示餘數\n    !結束程式\n");
		while(1){
		scanf("%c",&c);
		switch(c){
				case'\n':break;
				case'#':scanf("%d",&a);
				two(a);
				printf("\n");
				break;
				case'+':scanf("%d %d",&a,&b);
				printf("%d\n",a+b);
				break;
				case'-':scanf("%d %d",&a,&b);
			    printf("%d\n",a-b);
				break;
				case'*':scanf("%d %d",&a,&b);
				printf("%d\n",a*b);
				break;
				case'/':scanf("%d %d",&a,&b);
				if(b==0)
						{printf("你搞毛啊!\n");
						break;}
				printf("%.2f\n",(float)a/b);
				break;
				case'%':scanf("%d %d",&a,&b);
				printf("%d\n",a%b);
				break;
				case'!':return 0;
				default:printf("你搞毛啊!重打!\n");


				}

		
}
return 0;
}
