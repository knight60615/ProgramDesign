#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Maxlength 2000
#define Maxsize 1000000
int cmp=0,x=0;
long int bstcmp=0;
struct hnode{
		char *word;
		int count;
		struct hnode *next;
};
struct tnode{
		char *word;
		int count;
		struct tnode *lc;
		struct tnode *rc;
};
int myhstrcmp(char *A,char *B){
		cmp++;	
		return strcmp(A,B);
}
int mybstrcmp(char *A,char *B){
		bstcmp++;
		return strcmp(A,B);
}

int compare(const void*a,const void*b){
		return (*(struct hnode**)b)->count-(*(struct hnode**)a)->count;
}
struct tnode *BST_insert(struct tnode *tp,char *key){
		//�o�̭n�`�N�P�_tp==NULL����A�}temp,�]������j���ninsert���I���e�|���_����call insert function,�@�~�q�e�j�ɭP�h���L�N�q��malloc�|��C�{���t��
if(tp==NULL){
		struct tnode *temp;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		temp->count=1;
		temp->word=(char*)malloc(sizeof(char)*(strlen(key)+1));
		strcpy(temp->word,key);
		temp->lc=NULL;
		temp->rc=NULL;		//initialize temp
		return temp;
}
else if (mybstrcmp(tp->word,key)>0)
		tp->lc=BST_insert(tp->lc,key);
else if (mybstrcmp(tp->word,key)<0)
		tp->rc=BST_insert(tp->rc,key);
		return tp;
		}
struct tnode *BST_find(struct tnode *tp,char *key){
		if(tp==NULL)
				return NULL;
		else if (mybstrcmp(tp->word,key)==0)
				return tp;
		else if (mybstrcmp(tp->word,key)>0)
				return BST_find(tp->lc,key);
		else/* if (mybstrcmp(tp->word,key)<0)*/
				return BST_find(tp->rc,key);
}

unsigned int hash33(char *key){
		unsigned int hv=0;
		for(hv=0;*key;key++) // string polynomial 
				hv=hv*33+*key;
		return hv;
}
void hash_insert(struct hnode *htab[],char *key){
		struct hnode *ptr,*new;
		unsigned int hv;
		hv=hash33(key)%Maxsize;
		ptr=htab[hv];
		new=(struct hnode*)malloc(sizeof(struct hnode));
		new->word=(char*)malloc(sizeof(char)*(strlen(key)+1));
		strcpy(new->word,key);
		new->count=1;
		new->next=ptr;		//�S�O�`�N����gnew->next=htab[hv]
		htab[hv]=new;		//�]���o�̰��W�N�ʨ�F
}
struct hnode *hash_find(struct hnode *htab[],char *key){
		unsigned int hv;
		struct hnode *ptr;
		hv=hash33(key)%Maxsize;		
		ptr=htab[hv];
		while(ptr!=NULL){
				if(myhstrcmp(ptr->word,key)==0) 
						return ptr;
				ptr=ptr->next;
		}
		return NULL;
}
int main(int argc, char *argv[])
{
		double start, end;
		char buf[Maxlength];
		struct tnode *BST_input=NULL,*p;
		struct hnode **hash_input,*q,*ptr;
		struct hnode **temp;
		int i=0,j=0,num=0;
		FILE *fp;
		if (argc>0)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				printf("fopen failed\n");
				return 0;
		}
		//�ȥ���malloc�}���а}�C �T�w�O����O�ܤp��
hash_input=(struct hnode**)malloc(sizeof(struct hnode*)*Maxsize);
//�쥻�O�N���find�@�_��@�P�_����,insert�]�@�ֳB�z,�i�O������Ʒ|����,��]����
start = (double) clock() / CLOCKS_PER_SEC;
while(fgets(buf,Maxlength,fp)){
		if((q=hash_find(hash_input,buf))==NULL){
				hash_insert(hash_input,buf);
				num++;
		}
		else if(q!=NULL){
				q->count++;
		}
}
end = (double) clock() / CLOCKS_PER_SEC;
printf("hash time:%.4f\n",end-start);
fclose(fp);		//�ҥH���}�B�z
fp=fopen(argv[1],"r");	//���sŪ��
start = (double) clock() / CLOCKS_PER_SEC;
while(fgets(buf,Maxlength,fp))
{

		if((p=BST_find(BST_input,buf))==NULL){
				BST_input=BST_insert(BST_input,buf);
		}
		else if(p!=NULL){
				p->count++;
		}
}
end = (double) clock() / CLOCKS_PER_SEC;
printf("BST time:%.4f\n",end-start);
temp=(struct hnode**)malloc(sizeof(struct hnode*)*Maxsize);
//��hashtable���F��@��@�Ӫ��s����а}�C
while(i<Maxsize)
{
		ptr=hash_input[i++];
		while(ptr!=NULL)
		{ 
				temp[j++]=ptr;
				ptr=ptr->next;
		}
}
//�Ƨ�
qsort(temp,num,sizeof(struct hnode*),compare);
for(i=0;i<j;i++)
printf("%d\t%s",temp[i]->count,temp[i]->word);
//inorderTraversal(BST_input);

printf("hash strcmp����:%d\nBST strcmp����:%ld\ninsert����:%d\n",cmp,bstcmp,num);



return 0;
}

