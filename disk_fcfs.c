#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[100],i,n,total=0,init;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
    printf("Enter initial head position\n");
    scanf("%d",&init);
    
    for(i=0;i<n;i++)
    {
        total+=abs(req[i]-init);
        init=req[i];
    }
    
    printf("Total head moment is %d",total);
    return 0;
    
}