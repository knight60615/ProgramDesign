#include<stdio.h>
void swap(char *x, char *y)
{
		int i;
		char tmp[20];
		for(i=0;i<20;i++){

				tmp[i]=x[i];
				x[i]=y[i];
				y[i]=tmp[i];
		}

}

int main()
{
		char A[5][20];
		int x;
		for(x=0;x<=1;x++)
				scanf("%s",A[x]);
		swap(A[0], A[1]);
		printf("%s %s\n",A[0],A[1]);
		return 0;
}
