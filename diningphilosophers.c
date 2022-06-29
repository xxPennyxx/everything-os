#include<stdio.h>
#define n 20
 
int completed = 0,i;
 
struct fork{
int taken;
}forks[n];
 
struct phil{
int left;
int right;
}status[n];
 
void dine(int pid){ //same like threads concept here cases implemented
if(status[pid].left==10 && status[pid].right==10)
        printf("Philosopher %d completed his dinner\n",pid+1);
//if already completed dinner
else if(status[pid].left==1 && status[pid].right==1){
            //if just taken two forks
            printf("Philosopher %d completed his dinner\n",pid+1);
 
            status[pid].left = status[pid].right = 10; //remembering that he completed dinner by assigning value 10
            int otherFork = pid-1;
 
            if(otherFork== -1)
                otherFork=(n-1);
 
            forks[pid].taken = forks[otherFork].taken = 0; //releasing forks
            printf("Philosopher %d released fork %d and fork %d\n",pid+1,pid+1,otherFork+1);
            completed++;
        }
        else if(status[pid].left==1 && status[pid].right==0){ //left already taken, trying for right fork
                if(pid==(n-1)){
                    if(forks[pid].taken==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                        forks[pid].taken = status[pid].right = 1;
                        printf("Fork %d taken by philosopher %d\n",pid+1,pid+1);
                    }else
                        printf("Philosopher %d is waiting for fork %d\n",pid+1,pid+1);
                    
                }else{ //except last philosopher case
                    int pid1 = pid;
                    pid-=1;
 
                    if(pid== -1)
                        pid=(n-1);
 
                    if(forks[pid].taken == 0){
                        forks[pid].taken = status[pid1].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",pid+1,pid1+1);
                    }else
                        printf("Philosopher %d is waiting for Fork %d\n",pid1+1,pid+1);
                    
                }
            }
            else if(status[pid].left==0){ //nothing taken yet
                    if(pid==(n-1)){
                        if(forks[pid-1].taken==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                            forks[pid-1].taken = status[pid].left = 1;
                            printf("Fork %d taken by philosopher %d\n",pid,pid+1);
                        }else
                            printf("Philosopher %d is waiting for fork %d\n",pid+1,pid);
                        
                    }else{ //except last philosopher case
                        if(forks[pid].taken == 0){
                            forks[pid].taken = status[pid].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",pid+1,pid+1);
                        }else
                            printf("Philosopher %d is waiting for Fork %d\n",pid+1,pid+1);
                        
                    }
        }else{}
}
 
int main(){
for(i=0;i<n;i++)
        forks[i].taken=status[i].left=status[i].right=0;
 
while(completed<n){
/* Observe here carefully, while loop will run until all philosophers complete dinner
Actually problem of deadlock occur only when they try to take at same time
This for loop will say that they are trying at same time. And remaining status will print by dine function
*/
for(i=0;i<n;i++)
            dine(i);
printf("\nTill now num of philosophers completed dinner are %d\n\n",completed);
}
 
return 0;
}