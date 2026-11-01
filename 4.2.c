
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};



struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));

        if (root == NULL){
            printf("Memory allocation failed...\n");
            exit(1);
        }
        root->data = x;
        root->left = root->right = NULL;
    }


    else if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        printf("Duplicate value ignored...\n");

    return root;
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *minnode(struct node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}
struct node *delete(struct node *root, int x)
{
    struct node *temp;

    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = delete(root->left, x);
    else if (x > root->data)
        root->right = delete(root->right, x);
    else
    {
        // no children case
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // one child case
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // two children case
        temp = minnode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}



int main()
{
    struct node *root = NULL;
    int n, x, i, key;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input...\n");
        return 1;
    }

    printf("Enter node values:\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &x) != 1)
        {
            printf("Invalid value...\n");
            freetree(root);
            return 1;
        }

        root = insert(root, x);
    }

    printf("\nInorder before deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    if (scanf("%d", &key) != 1)
    {
        printf("Invalid input...\n");
        freetree(root);
        return 1;
    }
    {
        struct node *p = root;
        while (p != NULL && p->data != key)
        {
            if (key < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if (p == NULL)
            printf("Node not found...\n");
        else
            root = delete(root, key);
    }
    printf("\nInorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}
