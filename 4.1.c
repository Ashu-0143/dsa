#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* new(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val= val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node,int val) {
    if (node == NULL)return new(val);
    if (node->val > val)        node->left = insert (node->left,val);
    else if (node->val < val)        node->right = insert (node->right,val);
    return node;
}
void inorder(struct Node* root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if(root!=NULL) {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
}
struct Node* temp = NULL;

int op=1;
struct Node* search(struct Node* node,int val) {
    if(node!=NULL)    {
        if (node->val==val)
        {
            op=0;
            return node;
        }
        else if (node->val>= val)
        {
        temp=node;
            search(node->left,val);
            }
        else if (node->val <= val)
        {
        temp=node;
            search(node->right,val);
            }
    }
}
void case1(struct Node* node){printf("PErforming case1");}
void case2(struct Node* node){printf("PErforming case2");}
void case3(struct Node* node){printf("PErforming case3");}
void delete (struct Node* node)
{
if (node->right == NULL && node->left == NULL) case1(node);
else if (node->right == NULL || node->left == NULL) case2(node);
else case3(node);
    
}
int main () {
    int n,val,searc,choice=1;
    struct Node* root = NULL;

    printf("Enter No. of Elements : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)    {
        printf("\nEnter Element : ");
        scanf("%d",&val);
        root = insert(root,val);
    }
    while(choice!=0)
    {
    
    printf("\n\nEnter Your Choice : \n");
    printf("1.Insert\n");
    printf("2.Traversals\n");
    printf("3.Search\n");
        printf("4.Delete\n");
    printf("0.Stop\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
    case 1:
    {
    clrscr();
        printf("\nEnter Value : ");
        scanf("%d",&val);
        root = insert(root,val);
        break;
    }
    case 2:
    {
    clrscr();
        printf("Inorder Traversal : ");
        inorder(root);
        printf("\nPreorder Traversal : ");
        preorder(root);
        printf("\nPostorder Traversal : ");
        postorder(root);
        break;
    }
    case 3:
    {
    clrscr();
    struct Node* inp = NULL;
    printf("\n\nEnter Search Element : ");
    scanf("%d",&searc);
    inp = search(root,searc);
    if(!(op))
    printf("\n\nFound");
    else{
    printf("\n\nNot Found ");
    }   
    
    break;
    }
    case 4:
    {
    clrscr();
    struct Node* temp2 = NULL;
    printf("\nEnter Value to Delete : ");
    scanf("%d",&val);
    temp2 = search(root,val);
    if(op==0)
    delete(temp2);
    else
    printf("\nNot Found ");
    break;
    }
    
    case 0:
    exit(0);
    }
    }
    printf("\nInorder Traversal uses Left-Root-Right.\nBST stores elements lesser,root,greater\nHence the output is in sorted Order");
    return 0;
}