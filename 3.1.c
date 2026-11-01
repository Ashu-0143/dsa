
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *head=NULL;
void insertBeg()
{
    int x;
    node *new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("No memory...\n");
        return;
    }
    printf("Enter roll no : ");
    scanf("%d",&x);
    new->data=x;
    new->next=head;
    head=new;
    printf("Inserted...\n");
}
void insertEnd()
{
    int x;
    node *temp=head;
    node *new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("No memory...\n");
        return;
    }
    printf("Enter roll no : ");
    scanf("%d",&x);
    new->data=x;
    new->next=NULL;
    if(head==NULL)
        head=new;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new;
    }
    printf("Inserted...\n");
}
void search()
{
    int x;
    node *temp=head;
    if(head==NULL)
    {
        printf("List empty...\n");
        return;
    }
    printf("Enter roll no : ");
    scanf("%d",&x);
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            printf("Found...\n");
            return;
        }
        temp=temp->next;
    }
    printf("Not found...\n");
}
void display()
{
    node *temp=head;
    if(head==NULL)
    {
        printf("List empty...\n");
        return;
    }
    printf("Roll nos : ");
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delete()
{
    int x;
    node *temp=head;
    if(head==NULL)
    {
        printf("List empty...\n");
        return;
    }
    printf("Enter roll no : ");
    scanf("%d",&x);
    if(head->data==x)
    {
        head=head->next;
        free(temp);
        display();
        return;
    }
    while(temp->next!=NULL && temp->next->data!=x)
        temp=temp->next;
    if(temp->next==NULL)
        printf("Not found...\n");
    else{
        node *del=temp->next;
        temp->next=del->next;
        free(del);
        display();}
}
int exitcode()
{
    node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
int main()
{
    int ch=0;
    while(ch!=6)
    {
        printf("\n-----Menuu\n");
        printf("1.Insert beg\n");
        printf("2.Insert end\n");
        printf("3.Search\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: search(); break;
            case 4: delete(); break;
            case 5: display(); break;
            case 6: exitcode(); break;
            default: printf(" Wrong choice...\n");
        }
    }
    return 0;
}
