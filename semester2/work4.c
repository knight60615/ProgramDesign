#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 100000
//#define NKEYS (sizeof(keyword) / sizeof (struct key))		//這樣寫無論內容是什麼都不必更動資料筆數
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
		int cond;		// call binsearch 時,需注意 tab 空間 至少為 2 超過 2 空間至少為 n+1

		struct key *low = &tab[0];
		struct key *high = &tab[n];

		struct key *mid;

		while(low < high) {

				// mid 是 pointer 非第幾元素

				mid = low +(high - low) / 2;

				//存取結構成員 (*mid).word 等價於 mid->word

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


		while(fscanf(fp1,"%s",buf)!=EOF)			//把文件的單字存進struct key的word裡
		{
				keyword[i].word=(char *) malloc(sizeof(char)*(strlen(buf)+1));
				buf[strlen(buf)]='\0';
				strcpy(keyword[i].word,buf);
				i++;
		}
		qsort(keyword,i,sizeof(struct key),mystrcmp);		//排序




		while((fscanf(fp2,"%s",buf))!=EOF)			//讀進文件二暫時存在buf
		{
				if ((p=binsearch(buf,keyword,i))!=NULL)		//直接去和keyword做比較所以不用特意存出來
						p->count++;				//指標p指向binsearch的回傳值(mid),也就是找到的那一個(struct key)keyword
		}

		for (x=0;x<i;x++)
		{
				printf("%s:%d\n",keyword[x].word,keyword[x].count);		
		}		
		/*  也可以寫成 
			for (p=keyword;p<keyword+i;p++)
			printf("%s:%d\n",p->word,p->count);*/




		return 0;
}
