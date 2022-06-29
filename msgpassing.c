#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include <string.h> 
struct msg{
    long int type;
    char rickroll[1000];
};
int main()
{
    int running=1;
    int msgid;
    struct msg yeah;
    char rick[100];
    msgid=msgget((key_t) 14534,0666 | IPC_CREAT);
    if(msgid==-1)
    {
        printf("Oh shit!");
        exit(0);
        
    }
    while(running)
    {
        printf("TYPE SOMETHING\n");
        fgets(rick,100,stdin);
        strcpy(yeah.rickroll,rick);
        if (msgsnd(msgid,(void*)&yeah,100,0)==-1)
        printf("Oh shit!");
        msgrcv(msgid,(void*)&yeah,100,0,0);
        printf("%s",yeah.rickroll);
        if(strncmp(rick,"Jhye",4)==0)
        running=0;
        msgctl(msgid,IPC_RMID,0);
        
    }
    
    return 0;
}