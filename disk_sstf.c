#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[100],i,n,total=0,init,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
    printf("Enter initial head position\n");
    scanf("%d",&init);
    
        /* loop will execute until all process is completed*/
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(req[i]-init);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        total=total+min;
        init=req[index];
        // 1000 is for max
        // you can use any number
        req[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d",total);
    return 0;
}