#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
	int Count;
	char *Word;
	struct Node *left;
	struct Node *right;
};

struct Hnode
{
	int Count;
	char *Word;
	struct Hnode *next;
};

struct Hnode *HashTable[200000];

unsigned int hash33(char *key)
{
	unsigned int a=0;
	while(*key!='\0')
	{	a=a*33+*key;
		key++;}
	return a;
}


int Insertcount=0;
struct Node *Create(struct Node *location,char buf[])
{
	if(location==NULL)						//	�p�G�S���F��
	{
		struct Node *Temp;
		Temp=(struct Node*)malloc(sizeof(struct Node));	//	�ؤ@�ӷs��node
		Temp->Word=(char *)malloc(sizeof(char)*(strlen(buf)+1));
		strcpy(Temp->Word,buf);			//	��Word�Ŷ��A�ýƻs�i�h
		Temp->Count=1;					//	����l��
		Temp->left=NULL;				//  ����l��
		Temp->right=NULL;				//  ����l��
		Insertcount++;
		return Temp;					//	�^�ǳo�ӷs��node����m
	}
	if(strcmp(location->Word,buf)<0)	//	�p�G��ؼЦr�p(�ؼЦr���j)
		location->right=Create(location->right,buf);	//	�V�k����
	else								//	�ؼЦr���p
		location->left=Create(location->left,buf);		//  �V������
	return location;					//	�禡���A���Y�A�^�ǿ�J��
}


long int CMPcount=0;
int cmp(const void *PointerA,const void *PointerB)
{
	CMPcount++;
	return strcmp(  (*(struct Node *) PointerA).Word,
					(*(struct Node *) PointerB).Word  );	
}

int Scmp(char *PointerA,char *PointerB)
{
	CMPcount++;
	return strcmp(  PointerA, PointerB );	
}

int Hcmp(const void *PointerA,const void *PointerB)
{
	CMPcount++;
	return strcmp(  (*(struct Hnode *) PointerA).Word,
					(*(struct Hnode *) PointerB).Word  );	
}

struct Hnode *Ins(struct Hnode *location , char *key)
{
	if(location==NULL)						//	�p�G�S���F��
	{
		struct Hnode *Temp;
		Temp=(struct Hnode*)malloc(sizeof(struct Hnode));
		Temp->Word=(char *)malloc(sizeof(char)*(strlen(key)+1));
		strcpy(Temp->Word,key);			//	��Word�Ŷ��A�ýƻs�i�h
		Temp->Count=1;					//	����l��
		Temp->next=NULL;				//  ����l��
		Insertcount++;
		return Temp;					//	�^�ǳo�ӷs��node����m
	}
	if(Scmp(location->Word,key)!=0)
		location->next=Ins(location->next,key);
	else location->Count++;
	return location;
}

struct Node *Search(struct Node *Temp,char buf[])
{
	if(Temp==NULL)						//	�p�G�S���F��
		return NULL;					//	�^��NULL
	else if(Scmp(Temp->Word,buf)==0)	//	���
		return Temp;					//	�^�ǸӦ�m
	else if(Scmp(Temp->Word,buf)<0)	//	�ؼЦr�j
		return Search(Temp->right,buf);	//	���k���
	else								//  �ؼЦr�p
		return Search(Temp->left,buf);	//  �������
}

/*
struct Hnode *HSearch(struct Hnode *Temp,char buf[])
{
	if(Temp==NULL)						//	�p�G�S���F��
		return NULL;					//	�^��NULL
	else if(Hcmp(Temp->Word,buf)==0)	//	���
		Temp->count++;					//	�^�ǸӦ�m
		return Temp;
	else								//  �ؼЦr�p
		return HSearch(Temp->next,buf);	//  �������
}
*/



int main(int argc,char *argv[])
{
	FILE *FilePointer;
	char buf[1000000];
	int i;
	int temp;
	double start, end;


	
	
	//	�p��إ�HashTable�ҥήɶ� Insert���� Cmp����

	//struct Hnode *TempH;

	CMPcount=0;
	Insertcount=0;
	
	for (i=0;i<200000;i++)
		HashTable[i]=NULL;


	printf("���b�إ�HashTable...\n");
	FilePointer=fopen(argv[1],"r");
	start = (double) clock() / CLOCKS_PER_SEC;
	i = 0;
	while((fgets(buf,1000000,FilePointer)))
	{
		temp=hash33(buf)%200000;
		HashTable[temp] = Ins(HashTable[temp] ,buf);
	}
	
	printf("HashTable�غc����\n");	
	end = (double) clock() / CLOCKS_PER_SEC;
	printf("�إ�HashTable �ϥήɶ�:\t%lfs\n", end - start);
	printf("�إ�HashTable Insert����:\t%d\n",Insertcount);
	printf("�إ�HashTable Comparsion����:\t%ld\n",CMPcount);
	fclose(FilePointer);
	
	//	�p��إ�BST�ҥήɶ� Insert���� Cmp����
	
	struct Node *Root=NULL;
	struct Node *Temp;
	CMPcount=0;
	Insertcount=0;
	
	printf("���b�إ�BST...\n");
	FilePointer=fopen(argv[1],"r");
	start = (double) clock() / CLOCKS_PER_SEC;
	
	while((fgets(buf,1000000,FilePointer)))
	{
		Temp=Search(Root,buf);
		if(Temp!=NULL)
			(Temp->Count)++;
		else
			Root = Create(Root,buf);
	}
	
	printf("BST�غc����\n");	
	end = (double) clock() / CLOCKS_PER_SEC;
	printf("�إ�BST �ϥήɶ�:\t%lfs\n", end - start);
	printf("�إ�BST Insert����:\t%d\n",Insertcount);
	printf("�إ�BST Comparsion����:\t%ld\n",CMPcount);
	fclose(FilePointer);
	
	return 0;
}
