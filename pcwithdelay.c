#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int printRandoms(int lower, int upper)
{

        int num = (rand() %
           (upper - lower + 1)) + lower;
     return num;
    
}
 
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int mutex=1,full=0,empty=3,x=0;
 
int main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);
while(1)
{

n=printRandoms(1, 3);

switch(n)
{
case 1: if((mutex==1)&&(empty!=0))
producer();
else{
printf("Buffer is full!!\n");
        delay(1000);}

break;
case 2: if((mutex==1)&&(full!=0))
consumer();
else{printf("Buffer is empty!!\n");
        delay(1000);}

break;

}
}
return 0;
}
 
int wait(int s)
{
return (--s);
}
 
int signal(int s)
{
return(++s);
}
 
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("Producer produces the item %d\n",x);
        delay(1000);

mutex=signal(mutex);
}
 
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("Consumer consumes item %d\n",x);
        delay(1000);

x--;
mutex=signal(mutex);
}
