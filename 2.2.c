
#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();
int isoverflow();
int isunderflow();

int main()
{
    int choice;
    do
    {
        printf("\n--------------MENU \n");
        printf("1.Insert request\n");
        printf("2.Delete request\n");
        printf("3.Show buffer\n");
        printf("4.Exit.\n");
        printf("------------------\n");
        printf("Enter your option ......\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExitting .. .\n");
                break;
            default:
                printf("\nInvalid!\n");
        }

    } while(choice != 4);
    return 0;
}


void enqueue()
{
    int value;
    if(isoverflow())
    {
        printf("\nQueue is full!!!\n");
        return;
    }

    printf("please enter request value:");
    scanf("%d", &value);
    if(front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("\n%d inserted \n", value);
}


void dequeue()
{
    int deleted;
    if(isunderflow())
    {
        printf("\nqueue is empty!!.\n");
        return;
    }

    deleted = queue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    printf("\ndeleted request :%d\n", deleted );
}

void display()
{
    int i;

    if(isunderflow())
    {
        printf("\nUnderFLOW !\n");
        return;
    }
    printf("\ncurrent queue ----- \n");
    i = front;
    while(1){
        printf("%d  ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int isoverflow()
{
    if((rear + 1) % SIZE == front)
        return 1;
    return 0;
}
int isunderflow()
{
    if(front == -1)
        return 1;
return 0;
}
