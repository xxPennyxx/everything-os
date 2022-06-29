#include<stdio.h>
int main()
{
    int i,limit,total=0,x,counter=0,tq;
    int wt=0,tt=0,AT[100],BT[100],temp[100];
    float avgWT,avgTT;
    printf("Enter no. of processes\n");
    scanf("%d",&limit);
    for (i=0;i<limit;i++)
    {
        printf("Enter arrival time of process %d:",(i+1));
        scanf("%d",&AT[i]);
    }
    for (i=0;i<limit;i++)
    {
        printf("Enter burst time of process %d:",(i+1));
        scanf("%d",&BT[i]);
        temp[i]=BT[i];
    }x=limit;
    printf("Enter time quantum\n");
    scanf("%d",&tq);
    printf("PID\t\tBT\t\tAT\t\tTAT\t\tWT\n");
    for(total=0,i=0;x!=0;)
    {
        if(temp[i]<=tq&&temp[i]>0)
        {
            total+=temp[i];
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-tq;
            total+=tq;
        }
        if(temp[i]==0&&counter==1)
        {
            x--;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),BT[i],AT[i],total-AT[i],total-AT[i]-BT[i]);
            wt=wt+total-AT[i]-BT[i];
            tt=tt+total-AT[i];
            counter=0;


        }
        if(i==limit-1)
        i=0;
        else if (AT[i+1]<=total)
        i++;
        else i=0;
       
    }
    avgWT=wt/limit;
    avgTT=tt/limit;
    printf("Average waiting time:%f\n",avgWT);
    printf("Average turnaround time:%f\n",avgTT);
    return 0;
}