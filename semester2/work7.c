#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxName 20
#define MaxPhone 15
#define MaxEmail 50
struct addr{
		char name[MaxName];
		char phone[MaxPhone];
		char email[MaxEmail];
		struct addr *leftNode;
		struct addr *rightNode;
};
//struct addr *pre = NULL;   //此指標會指到需被刪除的點的父節點
struct addr *insert(struct addr *tp,char *name,char *phone,char *email){
		struct addr *temp;
		temp=(struct addr*)malloc(sizeof(struct addr));
		if(tp==NULL){
				strcpy(temp->name,name);
				strcpy(temp->phone,phone);
				strcpy(temp->email,email);
				temp->leftNode=NULL;
				temp->rightNode=NULL;
				return temp;
		}
		if (strcmp(tp->name,name)>0)
				tp->leftNode=insert(tp->leftNode,name,phone,email);
		else if(strcmp(tp->name,name)<0)
				tp->rightNode=insert(tp->rightNode,name,phone,email);
		return tp;
}
struct addr *find(struct addr *tp,char *key){
		if(tp==NULL)
				return NULL;
		else if (strcmp(tp->name,key)==0)
				return tp;
		else if (strcmp(tp->name,key)>0)
				return find(tp->leftNode,key);
		else
				return find(tp->rightNode,key);
}
struct addr *inorderTraversal(struct addr *tp){
		if(tp==NULL) return NULL;
		inorderTraversal(tp->leftNode);		
		printf("%s\t%s\t%s\n",tp->name,tp->phone,tp->email);	
		inorderTraversal(tp->rightNode);
		return NULL;
}


struct addr *delete(struct addr *root,char *name) {
		struct addr *temp;
		if (root==NULL) {
				printf("%s  is not exist in this binary tree\n",name);
				return NULL;
		} else if (strcmp(name,root->name)<0)
				root->leftNode=delete(root->leftNode,name);
		else if (strcmp(name,root->name)>0)
				root->rightNode=delete(root->rightNode,name);
		else {
				if (root->leftNode && root->rightNode) { //two children
						temp=root->leftNode;
						while(temp->rightNode!=NULL){     //此回圈會找出左邊最大的節點
								//root=temp;
								temp=temp->rightNode;
						}

						strcpy(root->name,temp->name);
						strcpy(root->phone,temp->phone);
						strcpy(root->email,temp->email);
						root->leftNode=delete(root->leftNode,root->name);
				}else{ // one child or no child
						temp=root;
						if (root->leftNode==NULL)
								root=root->rightNode;
						else if (root->rightNode==NULL)
								root=root->leftNode;
						free(temp);
				}}
				return root;	

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
		struct addr *input=NULL;
		struct addr *p;
		char buf1[MaxName],buf2[MaxPhone],buf3[MaxEmail];
		char c,d;
		while(fscanf(fp,"%s %s %s",buf1,buf2,buf3)!=EOF){
				//	printf("%s %s %s",buf1,buf2,buf3);
				input=insert(input,buf1,buf2,buf3);
		}
		while(1){
				printf("1)\tlist\n2)\tinsert\n3)\tdelete\n4)\tfind\n5)\texit\ninput a command:");
				scanf(" %c",&c);
				switch(c){
						case'1':inorderTraversal(input);
								break;
						case'2':
								d='Y';
								while(d=='Y'){
										printf("please input:\n\tname:");
										scanf("%s",buf1);
										printf("\tphone:");
										scanf("%s",buf2);
										printf("\temail:");
										scanf("%s",buf3);
										if((p=find(input,buf1))==NULL)
												input=insert(input,buf1,buf2,buf3);
										else
										{
												strcpy(p->name,buf1);
												strcpy(p->phone,buf2);
												strcpy(p->email,buf3);
										}

										printf("insert more?(Y/N)");
										scanf(" %c",&d);
								}
								break;
						case'3':printf("name:");
								scanf("%s",buf1);
								delete(input,buf1);
								break;
						case'4':printf("name:");
								scanf("%s",buf1);
								if((p=find(input,buf1))!=NULL)
										printf("%s\t%s\t%s\n",p->name,p->phone,p->email);
								else
										printf("%snot found\n",buf1);
								break;

						case'5':return 0;
				}


		}

		return 0;
}
