#include<stdio.h>
#define INF 9999
#define max 10
void floyd(int n,int dist[max][max])
{


    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }

        }
    }
    printf("Shortest path is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
                printf("INF ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int dist[max][max],n;
    printf("enter value of n");
    scanf("%d",&n);
    int i,j;
    printf("enter matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           scanf("%d",&dist[i][j]);
        }

    }
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;
    floyd(n,dist);
}
