#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int pipe1[2]; 
	int pipe2[2]; 
	char str2[] = " is a sussy noob";
	char name[100];
	pid_t p;

	if (pipe(pipe1) == -1) {
		printf("Pipe Failed");
		return 1;
	}
	if (pipe(pipe2) == -1) {
		printf("Pipe Failed");
		return 1;
	}
    printf("Enter a name\n");
	scanf("%s", name);
	p = fork();

	if (p < 0) {
		fprintf(stderr, "fork Failed");
		return 1;
	}
	else if (p > 0) {
		char strconcat[100];
		close(pipe1[0]); 
		write(pipe1[1], name, strlen(name) + 1);
		close(pipe1[1]);

		wait(NULL);

		close(pipe2[1]); 
		read(pipe2[0], strconcat, 100);
		printf("Concatenated string:\n%s\n", strconcat);
		close(pipe2[0]);
	}

	else {
		close(pipe1[1]); 
		char strconcat[100];
		read(pipe1[0], strconcat, 100);

		int k = strlen(strconcat);
		int i;
		for (i = 0; i < strlen(str2); i++)
			strconcat[k++] = str2[i];

		strconcat[k] = '\0'; 
		close(pipe1[0]);
		close(pipe2[0]);
		write(pipe2[1], strconcat, strlen(strconcat) + 1);
		close(pipe2[1]);
		exit(0);
	}
}
