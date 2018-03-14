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
// �n�D�O�����m
		struct key *lptr=(struct key*)malloc(sizeof(struct key));
		// ��J���
		strcpy(lptr->word,word);
		lptr->count=1;
		// ��C�����j
		lptr->next=llist;//���V��r���} insert at front 
		llist=lptr;
		return llist;
}
struct key *find(struct key *llist,char *word) {
		struct key *lptr=llist;
		while(lptr!=NULL) {
				if(strcmp(lptr->word,word)==0)//���
						return lptr;
				else 						//�S���
						lptr=lptr->next;
		} return NULL;			//�����䧹���S���
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
		int num=0;				//�ΨӰO����
		while(fscanf(fp,"%s",buf)!=EOF){
				num++;
				if(find(input,buf)==NULL)
						input=insert(input,buf);
				else if((p=find(input,buf))!=NULL)
						p->count++;
		}
		int a=1;
		while(a<=num){//���gfor�N�n�F�������ڵ�����
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
