#include <stdio.h>

#define MAX 20

int main()
{
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);

            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Insert vertices with indegree 0 into queue
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }

    while(front <= rear)
    {
        int u = queue[front++];

        topo[k++] = u;

        for(i = 0; i < n; i++)
        {
            if(adj[u][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if(k != n)
    {
        printf("Graph contains a cycle. Topological ordering not possible.\n");
    }
    else
    {
        printf("Topological Ordering:\n");
        for(i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}
