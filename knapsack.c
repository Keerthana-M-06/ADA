#include<stdio.h>
int main()
{
    int n,i,j;
    float weight[10],profit[10],ratio[10];
    float capacity,temp;
    float totalprofit=0;
    printf("ente number of items");
    scanf("%d",&n);
    printf("enter weights and profits");
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
        ratio[i]=profit[i]/weight[i];
    }
    printf("enter capacity");
    scanf("%f",&capacity);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(weight[i]>capacity)
            break;
        else{
            totalprofit+=profit[i];
            capacity-=weight[i];
        }
    }
    if(i<n)
        totalprofit+=ratio[i]*capacity;
    printf("max profit is %f",totalprofit);
    return 0;
}
