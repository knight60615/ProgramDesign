#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 12000000
int k=0;
struct tnode{
		char word[50];
		int count;
		struct tnode *lc;
		struct tnode *rc;
};
struct tnode *A[MAXNUM];	//指向tree的指標陣列 方便等下直接操作tree裡內容
void swap(struct tnode **a,struct tnode **b)
{ struct tnode *temp;
		temp=*a;
		*a=*b;
		*b=temp;
}
struct tnode *insert(struct tnode *tp,char *key){
		struct tnode *temp;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		if(tp==NULL){
				temp->count=0;
				strcpy(temp->word,key);
				temp->count++;
				temp->lc=NULL;
				temp->rc=NULL;		//initialize temp
				return temp;
		}
		if (strcmp(tp->word,key)>0)
				tp->lc=insert(tp->lc,key);
		else if(strcmp(tp->word,key)<0)
				tp->rc=insert(tp->rc,key);
		return tp;
}
struct tnode *find(struct tnode *tp,char *key){
		if(tp==NULL)
				return NULL;
		else if (strcmp(tp->word,key)==0)
				return tp;
		else if (strcmp(tp->word,key)>0)
				return find(tp->lc,key);
		else
				return find(tp->rc,key);
}

void inorderTraversal(struct tnode *tp){
		if(tp==NULL) return;
		inorderTraversal(tp->lc);
		A[k++]=tp;
		inorderTraversal(tp->rc);
		return;
}

int main(int argc, char *argv[])
{
		int i,j;
		FILE *fp;
		if (argc>0)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				printf("fopen failed\n");
				return 0;
		}
		struct tnode *input=NULL,*p;
		char buf[50];
		while(fscanf(fp,"%s",buf)!=EOF){
				if(find(input,buf)==NULL){
						input=insert(input,buf);

				}
				else if((p=find(input,buf))!=NULL)
						p->count++;
		}					//讀檔存入BST
		inorderTraversal(input);		//tree和指標陣列連結
		for(i=0;i<k-1;i++){
				for(j=0;j<k-i-1;j++){
						if(A[j]->count<A[j+1]->count){
								swap(&A[j],&A[j+1]);
						}							//Bubble sort

				}
		}
		for(i=0;i<k;i++){
				printf("%d %s\n",A[i]->count,A[i]->word);
		}

		return 0;
}


