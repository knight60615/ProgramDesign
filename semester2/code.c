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
	if(location==NULL)						//	如果沒有東西
	{
		struct Node *Temp;
		Temp=(struct Node*)malloc(sizeof(struct Node));	//	建一個新的node
		Temp->Word=(char *)malloc(sizeof(char)*(strlen(buf)+1));
		strcpy(Temp->Word,buf);			//	給Word空間，並複製進去
		Temp->Count=1;					//	給初始值
		Temp->left=NULL;				//  給初始值
		Temp->right=NULL;				//  給初始值
		Insertcount++;
		return Temp;					//	回傳這個新的node的位置
	}
	if(strcmp(location->Word,buf)<0)	//	如果比目標字小(目標字較大)
		location->right=Create(location->right,buf);	//	向右移動
	else								//	目標字較小
		location->left=Create(location->left,buf);		//  向左移動
	return location;					//	函式型態關係，回傳輸入值
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
	if(location==NULL)						//	如果沒有東西
	{
		struct Hnode *Temp;
		Temp=(struct Hnode*)malloc(sizeof(struct Hnode));
		Temp->Word=(char *)malloc(sizeof(char)*(strlen(key)+1));
		strcpy(Temp->Word,key);			//	給Word空間，並複製進去
		Temp->Count=1;					//	給初始值
		Temp->next=NULL;				//  給初始值
		Insertcount++;
		return Temp;					//	回傳這個新的node的位置
	}
	if(Scmp(location->Word,key)!=0)
		location->next=Ins(location->next,key);
	else location->Count++;
	return location;
}

struct Node *Search(struct Node *Temp,char buf[])
{
	if(Temp==NULL)						//	如果沒有東西
		return NULL;					//	回傳NULL
	else if(Scmp(Temp->Word,buf)==0)	//	找到
		return Temp;					//	回傳該位置
	else if(Scmp(Temp->Word,buf)<0)	//	目標字大
		return Search(Temp->right,buf);	//	往右邊找
	else								//  目標字小
		return Search(Temp->left,buf);	//  往左邊找
}

/*
struct Hnode *HSearch(struct Hnode *Temp,char buf[])
{
	if(Temp==NULL)						//	如果沒有東西
		return NULL;					//	回傳NULL
	else if(Hcmp(Temp->Word,buf)==0)	//	找到
		Temp->count++;					//	回傳該位置
		return Temp;
	else								//  目標字小
		return HSearch(Temp->next,buf);	//  往左邊找
}
*/



int main(int argc,char *argv[])
{
	FILE *FilePointer;
	char buf[1000000];
	int i;
	int temp;
	double start, end;


	
	
	//	計算建立HashTable所用時間 Insert次數 Cmp次數

	//struct Hnode *TempH;

	CMPcount=0;
	Insertcount=0;
	
	for (i=0;i<200000;i++)
		HashTable[i]=NULL;


	printf("正在建立HashTable...\n");
	FilePointer=fopen(argv[1],"r");
	start = (double) clock() / CLOCKS_PER_SEC;
	i = 0;
	while((fgets(buf,1000000,FilePointer)))
	{
		temp=hash33(buf)%200000;
		HashTable[temp] = Ins(HashTable[temp] ,buf);
	}
	
	printf("HashTable建構完成\n");	
	end = (double) clock() / CLOCKS_PER_SEC;
	printf("建立HashTable 使用時間:\t%lfs\n", end - start);
	printf("建立HashTable Insert次數:\t%d\n",Insertcount);
	printf("建立HashTable Comparsion次數:\t%ld\n",CMPcount);
	fclose(FilePointer);
	
	//	計算建立BST所用時間 Insert次數 Cmp次數
	
	struct Node *Root=NULL;
	struct Node *Temp;
	CMPcount=0;
	Insertcount=0;
	
	printf("正在建立BST...\n");
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
	
	printf("BST建構完成\n");	
	end = (double) clock() / CLOCKS_PER_SEC;
	printf("建立BST 使用時間:\t%lfs\n", end - start);
	printf("建立BST Insert次數:\t%d\n",Insertcount);
	printf("建立BST Comparsion次數:\t%ld\n",CMPcount);
	fclose(FilePointer);
	
	return 0;
}
