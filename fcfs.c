#include<stdio.h>
int main()
{
    int AT[100],BT[100],WT[100],TT[100],n;
    int burst=0,comptime,i;
    float avgWT,avgTT, total=0;
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter arrival time of process %d:",(i+1));
        scanf("%d",&AT[i]);
    }
    for (i=0;i<n;i++)
    {
        printf("Enter burst time of process %d:",(i+1));
        scanf("%d",&BT[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        WT[i]=AT[i];//WT[i]=0?
        else
        WT[i]=burst-AT[i];
        burst+=BT[i];
        total+=WT[i];
    }
    avgWT=total/n;
    comptime=0;
    total=0;
    for(i=0;i<n;i++)
    {
        comptime+=BT[i];
        TT[i]=comptime-AT[i];
        total+=TT[i];
    }
    avgTT=total/n;
    for(i=0;i<n;i++)
    {
        if(WT[i]<0)
        WT[i]=0;
        if(TT[i]<0)
        TT[i]=0;
    }
    printf("Process\t\tWT\t\t AT\t\tTAT\n");
    for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",(i+1),WT[i],AT[i],TT[i]);
    printf("Average waiting time:%f\n",avgWT);
    printf("Average turnaround time:%f\n",avgTT);
    return 0;

}