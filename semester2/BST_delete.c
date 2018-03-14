#include <stdio.h>
#include <stdlib.h>
struct tree_node{   //二元搜尋樹的結構
    int data;
    struct tree_node *Lchild;
    struct tree_node *Rchild;
}; 
struct tree_node * search_Key(struct tree_node *, int);    //搜尋該刪除點是否存在在BST中
struct tree_node * delete_treeNode(struct tree_node *, int);  //刪除的函數
void trace_tree(struct tree_node *);    //中序追蹤
struct tree_node * create_ex_TREE();    //建立一個二元搜尋樹
struct tree_node *pre = NULL;   //此指標會指到需被刪除的點的父節點, 很重要
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
    struct tree_node *curr, *next, *dynSon;   //next 主要是在左數最大被移除後, 讓pre能夠參照
    curr = search_Key(r, Del_key);  //搜尋該刪除點
    if(curr == NULL){   //找不到
        printf("%d  is not exist in this binary tree\n"); 
        return r; 
    }else{
        if(curr->Rchild == NULL)   //代表要刪除的點沒有右節點
            next = curr->Lchild;
        else if(curr->Lchild == NULL) //代表要刪除的點沒有左節點
            next = curr->Rchild;
        else{
            pre = curr;
            dynSon = curr->Lchild;
            while(dynSon->Rchild != NULL){　　//此回圈會找出左邊最大的節點
                pre = dynSon;
                dynSon = dynSon->Rchild; 
            }
            curr->data = dynSon->data;
            curr = dynSon;   //這很重要!!!  將curr指向左樹最大的節點  
            next = dynSon->Lchild; 
        }
        if(pre == NULL)//代表這個二元搜尋樹只有一個節點, 如果刪除時 記得把 r 指向 NULL
            r = NULL;  
        else if(curr == pre->Rchild)  //pre 會指向左樹最大地節點(LMAX)的父節點,我以此判斷式代表現在curr就在LMAX結點上, 所以將LMAX的父節點重新指向到 next ("繞過" MAX)
            pre->Rchild = next; 
        else{ 
            pre->Lchild = next; 
        } 
        printf("SUCCESS for delete %d\n", Del_key); 
        return r;   //回傳 r, 讓 main 函數的 root 重新參考
    } 
     
} 
struct tree_node * search_Key(struct tree_node *r, int key) 
{
    struct tree_node *q = r; 
    while(q != NULL)
    {
        if(q->data == key){
            return q;  //找到了!!  回傳所在位置給 curr
        }else{
            pre = q;   //如果目前沒找到, 記得把 pre 只像目前的位置, 之後再繼續前進
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
