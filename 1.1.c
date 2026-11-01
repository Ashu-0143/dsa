//1.1
#include <stdio.h>

int main()
{
    int size,key;
    int comparisons=0;

    printf("Enter number of employee IDs : ");
    scanf("%d", &size);

    int emp[size];

    printf("\nEnter the IDs below :\n");

    for(int j=0;j<size;j++)
    {
        scanf("%d", &emp[j]);
    }

    int sorted=1;

    for(int j=1;j<size;j++)
    {
        if(emp[j] < emp[j-1])
        {
            sorted=0;
            break;
        }
    }

    if(sorted==0)
    {
        printf("\nEntered IDs are not in ascending order!\n");
        return 1;
    }

    printf("\nEnter ID to be searched : ");
    scanf("%d", &key);

    int low=0, high=size-1;
    int position=-1;

    while(low<=high)
    {
        int middle=low+(high-low)/2;
        comparisons++;

        if(emp[middle]==key)
        {
            position=middle;
            break;
        }
        else if(emp[middle]>key)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    if(position!=-1)
    {
        printf("\nEmployee ID is found at position : %d\n",position+1);
    }
    else
    {
        printf("\nSorry, ID not found!\n");
    }

    printf("Comparisons made : %d\n",comparisons);

    return 0;
}
