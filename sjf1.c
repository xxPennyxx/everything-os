#include<stdio.h>
int main()
{
    int BT[100],WT[100],TT[100],proc[100],i,j,n,total=0,pos,temp;
    float avgWT,avgTT;
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter burst time of process %d:",(i+1));
        scanf("%d",&BT[i]);
        proc[i]=i+1;
    }
    for (i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[pos])
            pos=j;

        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;
    }
    WT[0]=0;
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
        WT[i]+=BT[j];
        total+=WT[i];
    }
    avgWT=total/n;
    total=0;
    for(i=0;i<n;i++)
    {
        TT[i]=BT[i]+WT[i];
        total+=TT[i];
    }
    avgTT=total/n;
    printf("Process\t\tWT\t\t TAT\n");
    for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\n",proc[i],WT[i],TT[i]);
    printf("Average waiting time:%f\n",avgWT);
    printf("Average turnaround time:%f\n",avgTT);
    printf("\n\nSorted version:\n");
    for (i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(proc[j]<proc[pos])
            pos=j;

        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;
        temp=WT[i];
        WT[i]=WT[pos];
        WT[pos]=temp;
        temp=TT[i];
        TT[i]=TT[pos];
        TT[pos]=temp;
    }
    printf("Process\t\tWT\t\t TAT\n");
    for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\n",proc[i],WT[i],TT[i]);
    return 0;
}