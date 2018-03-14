#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
		int i,one,two;
		char c;
		if(argv[1][1]=='a'){

				one=atoi(argv[2]);
				two=atoi(argv[3]);
				printf("%d\n",one+two);
		}
		if(argv[1][1]=='s'){
				one=atoi(argv[2]);
				two=atoi(argv[3]);
				 printf("%d\n",one-two);
				  }
	if(argv[1][1]=='m'){
			one=atoi(argv[2]);
			two=atoi(argv[3]);
			printf("%d\n",one*two);
	}
	if(argv[1][1]=='d'){
			one=atoi(argv[2]);
			 two=atoi(argv[3]);
			 printf("%d\n",one/two);
	}
















		return 0;}
