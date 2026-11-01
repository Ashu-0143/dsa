
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{

    int page;
    struct Node *prev,*next;
}node;
node *head=NULL,*tail=NULL,*current=NULL;
node* createnode(){
    int x;
    node *new=(node*)malloc(sizeof(node));
    printf("Enter page no : ");
    scanf("%d",&x);
    new->page=x;
    new->next=NULL;
    new->prev=NULL;
    return new;
}


void createpage()
{
    node *new=createnode();
    if(current==NULL)
        head=tail=current=new;
    else if(current==tail)
    {
        new->prev=tail;
        tail->next=new;
        current=tail=new;
    }
    else
    {
        new->next=current->next;
        new->prev=current;
        current->next->prev=new;
        current->next=new;
        current=new;
    }
    printf("Page added...\n");
}
void moveforward()
{
    if(current==NULL)
        printf("No pages...\n");
    else if(current==tail)
        printf("Last page...\n");
    else
    {
        current=current->next;
        printf("Page : %d\n",current->page);
    }
}

void movebackward(){
    if(current==NULL)
        printf("No pages...\n");
    else if(current==head)
        printf("First page...\n");
    else
    {
        current=current->prev;
        printf("Page : %d\n",current->page);
    }
}

void deletepage()
{

    int x;
    node *temp=head;
    if(current==NULL)
        printf("No pages...\n");
    else
    {
        printf("Enter page to delete : ");
        scanf("%d",&x);
        while(temp!=NULL && temp->page!=x)
            temp=temp->next;
        if(temp==NULL)
            printf("Not found...\n");
        else
        {
            if(temp==current)
            {
                if(temp->next!=NULL)
                    current=temp->next;
                else
                    current=temp->prev;
            }
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;

            else
                head=temp->next;

            if(temp->next!=NULL)
                temp->next->prev=temp->prev;

            else
                tail=temp->prev;
            free(temp);
            printf("Deleted...\n");
        }
    }
}
void displayftl()
{
    node *temp=head;
    if(current==NULL)
        printf("List empty...\n");
    else
    {
        printf("First to last : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->page);
            temp=temp->next;
        }

        printf("\n");
    }
}
void displayltf()
{

    node *temp=tail;
    if(current==NULL)
        printf("List empty...\n");
    else
    {
        printf("Last to first : ");
        while(temp!=NULL)
        {

            printf("%d ",temp->page);
            temp=temp->prev;

        }
        printf("\n");
    }
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
    tail=current=NULL;
    return 0;
}
int main()
{

    int ch=0;
    while(ch!=7)
    {
        printf("\n-------- MENUU\n");
        printf("1. Create page\n");
        printf("2.Move forward\n");
        printf("3.Move backward\n");
        printf("4.Delete page\n");
        printf("5.Display F-L\n");
        printf("6.Display L-F\n");
        printf("7.Exit\n");
        printf("Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: createpage(); break;
            case 2: moveforward(); break;
            case 3: movebackward(); break;
            case 4: deletepage(); break;
            case 5: displayftl(); break;
            case 6: displayltf(); break;
            case 7: return exitcode();
            default: printf("Wrong choice...\n");
        }

    }

    return 0;
    
}
