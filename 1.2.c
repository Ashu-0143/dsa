
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
    printf("%d  ", arr[i]);
    printf("\n ");
    
}

int main()
{
    int n, shifts = 0;
    printf("Enter total number of students : ");
    scanf("%d", &n);

    if(n <= 0)
    {        printf("Invalid number of students!\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL)
    {
        printf("Unable to allocate memory!\n");
        return 1;
    }

    printf("\nEnter student marks .....\n");

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nBefore sorting ...... ");
    display(arr,n);

    //insertion sort logic
    for(int i=1; i<n; i++){  
        int temp = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
            shifts++;
        }

        arr[j+1] = temp;

        printf("\nafter pass %d : ",i);
        display(arr,n);
    }

    printf("\n\nsorted marks : ");
    display(arr,n);
    printf("\ntotal number of shifts : %d\n",shifts);
    free(arr);
    return 0;
}
