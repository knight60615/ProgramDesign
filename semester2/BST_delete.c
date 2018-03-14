#include <stdio.h>
#include <stdlib.h>
struct tree_node{   //�G���j�M�𪺵��c
    int data;
    struct tree_node *Lchild;
    struct tree_node *Rchild;
}; 
struct tree_node * search_Key(struct tree_node *, int);    //�j�M�ӧR���I�O�_�s�b�bBST��
struct tree_node * delete_treeNode(struct tree_node *, int);  //�R�������
void trace_tree(struct tree_node *);    //���ǰl��
struct tree_node * create_ex_TREE();    //�إߤ@�ӤG���j�M��
struct tree_node *pre = NULL;   //�����з|����ݳQ�R�����I�����`�I, �ܭ��n
int main(void)
{
    struct tree_node *root = NULL; 
    root = create_ex_TREE(); //create a binary search tree
    root = delete_treeNode(root, 20); //Example for delete 20
    printf("Now, the binary tree's in-order is"); 
    trace_tree(root); //trace the binary search tree after delete_treeNode's operation
    system("pause");
    return 0;
}
struct tree_node * delete_treeNode(struct tree_node *r, int Del_key)
{
    struct tree_node *curr, *next, *dynSon;   //next �D�n�O�b���Ƴ̤j�Q������, ��pre����ѷ�
    curr = search_Key(r, Del_key);  //�j�M�ӧR���I
    if(curr == NULL){   //�䤣��
        printf("%d  is not exist in this binary tree\n"); 
        return r; 
    }else{
        if(curr->Rchild == NULL)   //�N��n�R�����I�S���k�`�I
            next = curr->Lchild;
        else if(curr->Lchild == NULL) //�N��n�R�����I�S�����`�I
            next = curr->Rchild;
        else{
            pre = curr;
            dynSon = curr->Lchild;
            while(dynSon->Rchild != NULL){�@�@//���^��|��X����̤j���`�I
                pre = dynSon;
                dynSon = dynSon->Rchild; 
            }
            curr->data = dynSon->data;
            curr = dynSon;   //�o�ܭ��n!!!  �Ncurr���V����̤j���`�I  
            next = dynSon->Lchild; 
        }
        if(pre == NULL)//�N��o�ӤG���j�M��u���@�Ӹ`�I, �p�G�R���� �O�o�� r ���V NULL
            r = NULL;  
        else if(curr == pre->Rchild)  //pre �|���V����̤j�a�`�I(LMAX)�����`�I,�ڥH���P�_���N��{�bcurr�N�bLMAX���I�W, �ҥH�NLMAX�����`�I���s���V�� next ("¶�L" MAX)
            pre->Rchild = next; 
        else{ 
            pre->Lchild = next; 
        } 
        printf("SUCCESS for delete %d\n", Del_key); 
        return r;   //�^�� r, �� main ��ƪ� root ���s�Ѧ�
    } 
     
} 
struct tree_node * search_Key(struct tree_node *r, int key) 
{
    struct tree_node *q = r; 
    while(q != NULL)
    {
        if(q->data == key){
            return q;  //���F!!  �^�ǩҦb��m�� curr
        }else{
            pre = q;   //�p�G�ثe�S���, �O�o�� pre �u���ثe����m, ����A�~��e�i
            if(q->data > key)
                q = q->Lchild;
            else
                q = q->Rchild; 
        } 
    } 
    return NULL;           
}    
void trace_tree(struct tree_node *r)
{
    if(r != NULL){
        trace_tree(r->Lchild); 
        printf(" %d ", r->data);
        trace_tree(r->Rchild); 
    } 
}                  
struct tree_node * create_ex_TREE()
{
    struct tree_node *node1 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node2 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node3 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node4 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node5 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node6 = (struct tree_node *)malloc(sizeof(struct tree_node));
    struct tree_node *node7 = (struct tree_node *)malloc(sizeof(struct tree_node));
 
    node1->data = 20;
    node2->data = 10;
    node3->data = 30;
    node4->data = 5;
    node5->data = 15;
    node6->data = 25;
    node7->data = 35;
    node1->Lchild = node2; 
    node1->Rchild = node3; 
    node2->Lchild = node4; 
    node2->Rchild = node5; 
    node3->Lchild = node6; 
    node3->Rchild = node7; 
    node4->Lchild = NULL; 
    node4->Rchild = NULL; 
    node5->Lchild = NULL; 
    node5->Rchild = NULL; 
    node6->Lchild = NULL; 
    node6->Rchild = NULL; 
    node7->Lchild = NULL; 
    node7->Rchild = NULL; 
    return node1; 
}
</stdlib.h></stdio.h>
