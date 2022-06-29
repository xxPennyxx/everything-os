#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdio.h>
#include <string.h> 
int main()
{
    int i,j,n;
    void *shmem;
    char sentence[100];
    int shmid;
    shmid=shmget((key_t)2345,1024,0666 | IPC_CREAT);
    //printf("%d\n",shmid);
    shmem=shmat(shmid,NULL,0);
    //printf("%d\n",shmem);
    printf("Enter a number\n");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
    printf("Write something!!\n");
    read(0,sentence,1000);
    for (i = 0; sentence[i]!='\0'; i++) {
      if(sentence[i] >= 'a' && sentence[i] <= 'z') 
         sentence[i]=toupper(sentence[i]);
    }
    strcpy(shmem,sentence);
    printf("%s",(char*)shmem);
    shmid=shmget((key_t)2631,1024,0666 | IPC_CREAT);
    //printf("%d\n",shmid);
    //printf("Hello %s",(char*)shmem);
    }
    return 0;
}