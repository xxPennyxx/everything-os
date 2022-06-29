#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#define MAX 100

struct msg_buffer {
	long msg_type;
	char msg_text[100];
};

int main()
{
    int i=0,j;
	key_t key;
	int msgid;
	int vowels=0;
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    struct msg_buffer message[n];
    for(i=0;i<n;i++)
    {
        vowels=0;
	key = ftok("progfile", 65);

	msgid = msgget(key, 0666 | IPC_CREAT);
	message[i].msg_type = 1;

	printf("Write Data : ");
	fgets(message[i].msg_text,MAX,stdin);

	msgsnd(msgid, &message[i], sizeof(message[i]), 0);
    for(j=0;j<strlen(message[i].msg_text);j++)
    {
        if(message[i].msg_text[j]=='A'||
        message[i].msg_text[j]=='E'||
        message[i].msg_text[j]=='I'||
        message[i].msg_text[j]=='O'||
        message[i].msg_text[j]=='U'||
        message[i].msg_text[j]=='a'||
        message[i].msg_text[j]=='e'||
        message[i].msg_text[j]=='i'||
        message[i].msg_text[j]=='o'||
        message[i].msg_text[j]=='u')
        vowels++;
    }
	printf("Data send is : %s \n", message[i].msg_text);
	printf("There are %d vowels in there\n",vowels);
    }

	return 0;
}
