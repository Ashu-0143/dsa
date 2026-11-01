#include <stdio.h>
#define MAX 20
void bfs(int a[MAX][MAX], int n, int start)
{
    int q[MAX], visited[MAX] = {0};
    int front = 0, rear = 0, i, v;
    visited[start] = 1;
    q[rear++] = start;

    printf("\n BFS Traversal .... ");

    while (front < rear)    {
        v = q[front++];
        printf("%d ", v + 1);

        for (i = 0; i < n; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
    printf("\n");
}
int main()
{
    int a[MAX][MAX], n, i, j, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid number of vertices...\n");
        return 1;
    }

    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (scanf("%d", &a[i][j]) != 1 || (a[i][j] != 0 && a[i][j] != 1))
            {
                printf("Invalid matrix value...\n");
                return 1;
            }
        }
    }

    printf("Enter starting vertex (1 to %d): ", n);
    if (scanf("%d", &start) != 1 || start < 1 || start > n){        
        printf("Invalid starting vertex...\n");
        return 1;
    }
    bfs(a, n, start - 1);
    return 0;
}
