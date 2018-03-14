#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int mystrcmp(const void*a,const void*b)
{
		return strcmp(*((char**)a),*((char**)b));
//		return *((char**)a)-*((char**)b);
}

int main()
{
		int i,j,k;
		int *integer1,*integer2;
		char **character1,**character2;
		double start,end;
		integer1=(int*)malloc(sizeof(int)*5000000);//�n�D500w�檺�O����
		integer2=(int*)malloc(sizeof(int)*5000000);
		srand(time(NULL));
		printf("[integer array]\n");
		for(i=0;i<5000000;i++)					//�s�y500w�ӶüƦs�J
		{
				*(integer1+i)=*(integer2+i)=(rand()%100001)+0;
		}
		start=(double)clock()/CLOCKS_PER_SEC;
		qsort(integer1,5000000,sizeof(int),myintcmp);
		end=(double)clock()/CLOCKS_PER_SEC;		//�ƧǨíp��
		printf("qsort() time:%.4f\n",end-start);
		start=(double)clock()/CLOCKS_PER_SEC;
		mergesort(integer2,5000000,sizeof(int),myintcmp);
		end=(double)clock()/CLOCKS_PER_SEC;		//�ƧǨíp��
		printf("mergesort() time:%.4f\n",end-start);
		free(integer1);						//����O����
		free(integer2);

		character1=(char**)malloc(sizeof(char*)*5000000);//�n�D500w�檺�O����
		character2=(char**)malloc(sizeof(char*)*5000000);
		printf("[string array]\n");
		for(i=0;i<5000000;i++)					//�s�y500w�ӶüƦr��s�J
		{
				character1[i]=(char*)malloc(8*sizeof(char));
				character2[i]=(char*)malloc(8*sizeof(char));
				for(j=0;j<7;j++)
				{
						k=((rand()%58)+65);
						character1[i][j]=character2[i][j]=(char)k;
				}
				character1[i][7]='\0';
				character2[i][7]='\0';
		}
		start=(double)clock()/CLOCKS_PER_SEC;
		qsort(character1,5000000,sizeof(char*),mystrcmp);
		end=(double)clock()/CLOCKS_PER_SEC;			//�ƧǨíp��
		printf("qsort() time:%.4f\n",end-start);
		start=(double)clock()/CLOCKS_PER_SEC;
		mergesort(character2,5000000,sizeof(char*),mystrcmp);
		end=(double)clock()/CLOCKS_PER_SEC;			//�ƧǨíp��
		printf("mergesort() time:%.4f\n",end-start);
		free(character1);						//����O����
		free(character2);  

		return 0;
}
