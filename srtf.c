#include<stdio.h>
int main()
{
 int AT[100],BT[100],RT[100],endTime,i,smallest;
 int remain=0,n,time,totalWT=0,totalTAT=0;
 printf("Enter no of Processes : ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter arrival time for Process P%d : ",i+1);
 scanf("%d",&AT[i]);
 printf("Enter burst time for Process P%d : ",i+1);
 scanf("%d",&BT[i]);
 RT[i]=BT[i];
 }
 printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
 RT[9]=9999;
 for(time=0;remain!=n;time++)
 {
 smallest=9;
 for(i=0;i<n;i++)
 {
 if(AT[i]<=time && RT[i]<RT[smallest] && RT[i]>0)
 
 smallest=i;
 
 }
 RT[smallest]--;
 if(RT[smallest]==0)
 {
 remain++;
 endTime=time+1;
 printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-AT[smallest],endTime-BT[smallest]-AT[smallest]);
 totalWT+=endTime-BT[smallest]-AT[smallest];
 totalTAT+=endTime-AT[smallest];
 }
 }
 printf("\n\nAverage waiting time = %f\n",totalWT*1.0/n);
 printf("Average Turnaround time = %f",totalTAT*1.0/5);
 return 0;
}