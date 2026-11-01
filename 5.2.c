#include <stdio.h>
#define MAX 20
#define INF 99999
void dij(int a[MAX][MAX], int n, int src){

    int dist[MAX], visited[MAX] = {0};
    int i, j, u, min;

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (a[u][j] > 0 && visited[j] == 0)
            {
                if (dist[u] + a[u][j] < dist[j])
                    dist[j] = dist[u] + a[u][j];
            }
        }
    }

    printf("\nshortest distances from vertex %d... : \n", src + 1);
    printf("Vertex\tDistance\n");

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d\tNot reachable\n", i + 1);
        else
            printf("%d\t%d\n", i + 1, dist[i]);
    }
}

int main()
{
    int a[MAX][MAX], n, i, j, src;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid number of vertices...\n");
        return 1;
    }

    printf("Enter weighted adjacency matrix ...");
    printf("(enter 0 if there is no road)\n::");

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            if (scanf("%d", &a[i][j]) != 1 || a[i][j] < 0 || a[i][j] >= INF)
            {
                printf("Invalid weight...\n");
                return 1;
            }
        }
    }

    printf("enter source vertex (1 to %d)...: ", n);
    if (scanf("%d", &src) != 1 || src < 1 || src > n)
    {
        printf("Invalid source ..\n");
        return 1;
    }
    dij(a, n, src - 1);
    return 0;
}
