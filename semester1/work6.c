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
		printf("��J#�N�Ʀr�ର�G�i��\n    +�N��Ʀr�ۥ[\n    -�N��Ʀr�۴�\n    *�N��Ʀr�ۭ�\n    /�N��Ʀr�۰�\n    %%�N��Ʀr�۰�����ܾl��\n    !�����{��\n");
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
						{printf("�A�d���!\n");
						break;}
				printf("%.2f\n",(float)a/b);
				break;
				case'%':scanf("%d %d",&a,&b);
				printf("%d\n",a%b);
				break;
				case'!':return 0;
				default:printf("�A�d���!����!\n");


				}

		
}
return 0;
}
