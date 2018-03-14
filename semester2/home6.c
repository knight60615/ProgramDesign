#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode
{
		char *key;
		int count;
		struct tnode *lc;
		struct tnode *rc;
};
int bstinsert(struct tnode *p,char *A,struct tnode **c,int i)
{
		struct tnode *tmp;
		if(strcmp(p->key,A)>0)
		{
				if(p->lc==NULL)
				{
						tmp=(struct tnode*)malloc(sizeof(struct tnode));
						tmp->key=(char*)malloc(sizeof(A)+1);
						strcpy(tmp->key,A);
						tmp->count=1;
						p->lc=tmp;
						c[i]=p->lc;
				}
				else return bstinsert(p->lc,A,c,i);
		}
		else if(strcmp(p->key,A)<0)
		{
				if(p->rc==NULL)
				{
						tmp=(struct tnode*)malloc(sizeof(struct tnode));
						tmp->key=(char*)malloc(sizeof(A)+1);
						strcpy(tmp->key,A);
						tmp->count=1;
						p->rc=tmp;
						c[i]=p->rc;
				}
				else return bstinsert(p->rc,A,c,i);
		}
		else
		{
				p->count++;
				return 0;
		}
		return 1;
}
int main(int argc,char *argv[])
{
		struct tnode *wtree=NULL;
		struct tnode *tmp=NULL;
		struct tnode *wordlist[10000];
		int i=1,k,j;
		char word[100];
		FILE *fp;
		fp=fopen(argv[1],"r");
		if(fp==NULL)
		{
				printf("error\n");
				exit(0);
		}
		while(fscanf(fp,"%s",word)!=EOF)
		{
				if(wtree==NULL)
				{
						wtree=(struct tnode*)malloc(sizeof(struct tnode));
						wtree->key=(char*)malloc(sizeof(word)+1);
						strcpy(wtree->key,word);
						wtree->count=1;
						wordlist[0]=wtree;
				}
				else 
				{
						if(bstinsert(wtree,word,wordlist,i)==1)
						i++;
				}
		}
		for(j=0;j<i-1;j++)
		{
				for(k=0;k<i-1-j;k++)
				{
						if(wordlist[k]->count<wordlist[k+1]->count)
						{
								tmp=wordlist[k];
								wordlist[k]=wordlist[k+1];
								wordlist[k+1]=tmp;
						}
				}
		}
		for(j=0;j<i;j++)
		{
				printf("%s %d\n",wordlist[j]->key,wordlist[j]->count);
		}
		return 0;
}





