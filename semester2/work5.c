#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 1000
struct key{
		char word[MAXNUM];
		int count;
		struct key *next;
};
struct key *insert(struct key *llist,char *word) {
// 要求記憶體位置
		struct key *lptr=(struct key*)malloc(sizeof(struct key));
		// 放入資料
		strcpy(lptr->word,word);
		lptr->count=1;
		// 串列的遞迴
		lptr->next=llist;//指向原字串位址 insert at front 
		llist=lptr;
		return llist;
}
struct key *find(struct key *llist,char *word) {
		struct key *lptr=llist;
		while(lptr!=NULL) {
				if(strcmp(lptr->word,word)==0)//找到
						return lptr;
				else 						//沒找到
						lptr=lptr->next;
		} return NULL;			//全部找完都沒找到
}
void swap(struct key *A,struct key *B){
		int temp;
		temp=A->count;
		A->count=B->count;
		B->count=temp;
}
void swap2(struct key *A,struct key *B){
		char temp[MAXNUM];
		strcpy(temp,A->word);
		strcpy(A->word,B->word);
		strcpy(B->word,temp);
}


int main(int argc, char *argv[])
{
		FILE *fp;
		if (argc>0)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				printf("fopen failed\n");
				return 0;
		}
		struct key *input=NULL,*p,*A;
		char buf[MAXNUM];
		int num=0;				//用來記項數
		while(fscanf(fp,"%s",buf)!=EOF){
				num++;
				if(find(input,buf)==NULL)
						input=insert(input,buf);
				else if((p=find(input,buf))!=NULL)
						p->count++;
		}
		int a=1;
		while(a<=num){//其實寫for就好了不知哪根筋不對
				for(A=input;A->next!=NULL;A=A->next){
						if(A->count < (A->next)->count){
								swap(A,A->next);
								swap2(A,A->next);
						}
				}
				a++;
		}				//Bubblesort
		for(A=input;A!=NULL;A=A->next)
				printf("%d %s\n",A->count,A->word);

		return 0;
}
