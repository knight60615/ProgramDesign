#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 100000
//#define NKEYS (sizeof(keyword) / sizeof (struct key))		//�o�˼g�L�פ��e�O���򳣤�����ʸ�Ƶ���
struct key {
		char *word;
		int count;
};
int mystrcmp(const void*a,const void*b)
{
		struct key *A = (struct key*) a;
		struct key *B = (struct key*) b;
		return (strcmp(A->word,B->word));
}

struct key *binsearch(char *word, struct key *tab,int n) {
		int cond;		// call binsearch ��,�ݪ`�N tab �Ŷ� �ܤ֬� 2 �W�L 2 �Ŷ��ܤ֬� n+1

		struct key *low = &tab[0];
		struct key *high = &tab[n];

		struct key *mid;

		while(low < high) {

				// mid �O pointer �D�ĴX����

				mid = low +(high - low) / 2;

				//�s�����c���� (*mid).word ������ mid->word

				if( (cond = strcmp(word , mid->word )) < 0) {
						high = mid;

				}else if (cond > 0){
						low = mid +1;
				}else{
						return mid;
				}

		}
		return NULL;

}
int main(int argc, char *argv[])
{
		int i=0,x;
		char buf[MAXNUM];
		FILE *fp1,*fp2;
		struct key keyword[MAXNUM];
		struct key *p;
		if (argc>0)
		{
				fp1=fopen(argv[1],"r");
				fp2=fopen(argv[2],"r");
		}
		if(fp1==NULL||fp2==NULL){				
				printf("fopen failed");
				return 0;
		}


		while(fscanf(fp1,"%s",buf)!=EOF)			//���󪺳�r�s�istruct key��word��
		{
				keyword[i].word=(char *) malloc(sizeof(char)*(strlen(buf)+1));
				buf[strlen(buf)]='\0';
				strcpy(keyword[i].word,buf);
				i++;
		}
		qsort(keyword,i,sizeof(struct key),mystrcmp);		//�Ƨ�




		while((fscanf(fp2,"%s",buf))!=EOF)			//Ū�i���G�Ȯɦs�bbuf
		{
				if ((p=binsearch(buf,keyword,i))!=NULL)		//�����h�Mkeyword������ҥH���ίS�N�s�X��
						p->count++;				//����p���Vbinsearch���^�ǭ�(mid),�]�N�O��쪺���@��(struct key)keyword
		}

		for (x=0;x<i;x++)
		{
				printf("%s:%d\n",keyword[x].word,keyword[x].count);		
		}		
		/*  �]�i�H�g�� 
			for (p=keyword;p<keyword+i;p++)
			printf("%s:%d\n",p->word,p->count);*/




		return 0;
}
