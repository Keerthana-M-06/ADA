#include <stdio.h>
#define MAX 20
#define INF 9999

int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int ne = 0;           // number of edges
    int mincost = 0;
    int a, b, u, v, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;  // start from vertex 0

    printf("\nEdges in MST:\n");

    while (ne < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", a, b, min);
        mincost += min;
        visited[b] = 1;
        ne++;
        cost[a][b]=cost[b][a]=999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
