#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxlength 2000
#define Maxsize 1000000
struct hnode{
		char *word;
		int count;
		struct hnode *next;
};
unsigned int hash33(char *key){
		unsigned int hv=0;
		while(*key) {
				hv=hv*33+*key;
				key++;
		}
		return hv;
}
void hash_insert(struct hnode *htab[],char *key){
		struct hnode *ptr,*new;
		unsigned int hv;
		hv=hash33(key)%Maxsize;
		ptr=htab[hv];
		new=(struct hnode*)malloc(sizeof(struct hnode));
		new->word=(char*)malloc(sizeof(char)*(strlen(key)+1));
		// new->word[strlen(key)-3]='\0';
		strcpy(new->word,key);
		//new->word[strlen(key)-1]='\0';
		new->count=1;
		new->next=ptr;      //特別注意不能寫new->next=htab[hv]
		htab[hv]=new;       //因為這裡馬上就動到了
}
struct hnode *hash_find(struct hnode *htab[],char *key){
		unsigned int hv;
		struct hnode *ptr;
		hv=hash33(key)%Maxsize;
		ptr=htab[hv];
		while(ptr!=NULL){
				if(strcmp(ptr->word,key)==0)
						return ptr;
				ptr=ptr->next;
		}
		return NULL;
}
int main(int argc, char *argv[])
{
		FILE *fp;
		fp=fopen(argv[1],"r");
		int i=0,j=0;
		struct hnode **hash_input=NULL,*p,**temp;
		char buf[Maxlength];
		hash_input=(struct hnode**)malloc(sizeof(struct hnode*)*Maxsize);
		while(fgets(buf,Maxlength,fp)){
				if((p=hash_find(hash_input,buf))==NULL){
						hash_insert(hash_input,buf);
				}
				else if(p!=NULL)
						p->count++;
		}
		temp=(struct hnode**)malloc(sizeof(struct hnode*)*Maxsize);
		while(i<Maxsize)
		{
				p=hash_input[i++];
				while(p!=NULL)
				{
						temp[j++]=p;

						p=p->next;
				}
		}

		for(i=0;i<j;i++){
//				int k=0;
//				while()

temp[i]->word[strlen(temp[i]->word)-1]='\0';
				 printf("%s\t%d\n",temp[i]->word,temp[i]->count);
}


				return 0;
		}

