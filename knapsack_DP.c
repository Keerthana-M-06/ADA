#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int knapsack(int n,int M,int w[],int p[])
{
    int i,j;
    int table[n+1][M+1];
    for(i=0;i<=n;i++)
        table[i][0]=0;
    for(j=0;j<=M;j++)
        table[0][j]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(j<w[i-1])
                table[i][j]=table[i-1][j];
            else if(j>=w[i-1])
                table[i][j]=max(table[i-1][j],(p[i-1]+table[i-1][j-w[i-1]]));
        }
    }
    return table[n][M];
}
int main()
{
    int n,M;
    printf("enter number of items and capacity of knapsack");
    scanf("%d %d",&n,&M);
    int w[n],p[n];
    printf("enter weight of items");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("enter profit of items");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    int profit=knapsack(n,M,w,p);
    printf("profit is %d",profit);
    return 0;
}
