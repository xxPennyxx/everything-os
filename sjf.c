#include<stdio.h>
#include <string.h> 
int main()
{
    int BT[100],WT[100],TAT[100],AT[100],proc[100],start[100],CT[100],iscompleted[100],i,n;
    float avgWT,avgTT;
    int totalWT=0,totalTAT=0;
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
        printf("Enter arrival time of process %d:",(i+1));
        scanf("%d",&AT[i]);
    }
    memset(iscompleted,0,sizeof(iscompleted));
    
    int curtime=0;
    int completed=0;
    while (completed!=n)
    {
        int idx=-1;
        int mn=10000000;
        for (i=0;i<n;i++)
        {
            if(AT[i]<=curtime && iscompleted[i]==0)
            {
                if(BT[i]<mn)
                {
                    mn=BT[i];
                    idx=i;
                }
                if (BT[i]==mn)
                {
                    if(AT[i]<AT[idx])
                    {
                        mn=BT[i];
                        idx=i;
                    }
                    
                }
            }
        }
                if(idx!=-1)
                {
                    start[idx]=curtime;
                    CT[idx]=start[idx]+BT[idx];
                    TAT[idx]=CT[idx]-AT[idx];
                    WT[idx]=TAT[idx]-BT[idx];
                    totalWT+=WT[idx];
                    totalTAT+=TAT[idx];
                    iscompleted[idx]=1;
                    completed++;
                    curtime=CT[idx];
                }
                else
                {
                    curtime++;
                }
            }
    
    
    
    avgWT=(float)(totalWT/n);
    avgTT=(float)(totalTAT/n);
    printf("Process\t\tBT\t\tAT\t\tWT\t\t TAT\n");
    for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i],BT[i],AT[i],WT[i],TAT[i]);
    printf("Average waiting time:%f\n",avgWT);
    printf("Average turnaround time:%f\n",avgTT);
    return 0;

}
