#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[100],i,j,n,total=0,init,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
    printf("Enter init head position\n");
    scanf("%d",&init);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
        
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(init<req[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            total=total+abs(req[i]-init);
            init=req[i];
        }
        //  last movement for max size 
        total=total+abs(size-req[i-1]-1);
        /*movement max to min disk */
        total=total+abs(size-1-0);
        init=0;
        for( i=0;i<index;i++)
        {
             total=total+abs(req[i]-init);
             init=req[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            total=total+abs(req[i]-init);
            init=req[i];
        }
        //  last movement for min size 
        total=total+abs(req[i+1]-0);
        /*movement min to max disk */
        total=total+abs(size-1-0);
        init =size-1;
        for(i=n-1;i>=index;i--)
        {
             total=total+abs(req[i]-init);
             init=req[i];
            
        }
    }
    
    printf("Total head movement is %d",total);
    return 0;
}