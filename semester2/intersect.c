#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxlength 2000
#define Maxsize 1000000
struct hnode{
		char *word;
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
		strcpy(new->word,key);
		new->next=ptr;		//特別注意不能寫new->next=htab[hv]
		htab[hv]=new;		//因為這裡馬上就動到了
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
		FILE *fp1,*fp2;
		fp1=fopen(argv[1],"r");
		fp2=fopen(argv[2],"r");
		struct hnode **hash_input=NULL,*p;
		char buf[Maxlength];
		hash_input=(struct hnode**)malloc(sizeof(struct hnode*)*Maxsize);
		while(fgets(buf,Maxlength,fp1)){
				if(hash_find(hash_input,buf)==NULL){
						hash_insert(hash_input,buf);
				}
		}
		while(fgets(buf,Maxlength,fp2)){
				if((p=hash_find(hash_input,buf))!=NULL)
						printf("%s",p->word);
		}
		return 0;
}
