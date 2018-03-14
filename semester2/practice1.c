struct node{
char name[MAXSIZE];
struct node *next;
};
struct node *insert(struct node *llist,char *word) {
		struct node *lptr=(struct node*)malloc(sizeof(struct node));
		strcpy(lptr->name,word);
		lptr->next=llist;
		llist=lptr;
		return llist;
}
