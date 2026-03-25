#include<stdio.h>
#define max 10
int main()
{
    int n,i,j,start;
    int cost[max][max],dist[max],visited[max];
    printf("enter number of vertices");
    scanf("%d",&n);
    printf("enter cost matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;

        }
    }
    printf("enter starting vertex");
    scanf("%d",&start);
    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];
        visited[i]=0;
    }
    dist[start]=0;
    visited[start]=1;

    for(i=1;i<n;i++)
    {
        int min=999,u;
        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=1;
        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[u]+cost[u][j]<dist[j])
            {
                dist[j]=dist[u]+cost[u][j];
            }
        }

    }
    printf("sortest distance \n");
    for(i=0;i<n;i++)
        printf("to %d=%d\n ",i,dist[i]);
    return 0;
}
