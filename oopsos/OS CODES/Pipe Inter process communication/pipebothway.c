#include<stdio.h>
#include<unistd.h>
int main()
{
	int pipefds1[2],pipefds2[2];
	int returnstatus1,returnstatus2;
	int pid;
	char pipe1writemessage[20]="HI";
	char pipe2writemessage[20]="HELLO";
	char readmessage[20];
	returnstatus1=pipe(pipefds1);
	if(returnstatus1==-1)
	{
		printf("UNABLE TO CREATE PIPE!\n");
		return 1;
	}
	returnstatus2=pipe(pipefds2);
	if(returnstatus2==-1)
	{
		printf("UNABLE TOCREATE PIPE 2\n");
		return 1;
	}
	pid=fork();
	if(pid!=0)
	{
		close(pipefds1[0]);
		close(pipefds2[1]);
		printf("IN PARENT : WRITING TO PIPE 1-MESSAGE IS %s\n",pipe1writemessage);
		write(pipefds1[1],pipe1writemessage,sizeof(readmessage));
	}
	else
	{
		close(pipefds1[1]);
		close(pipefds2[0]);
		read(pipefds1[0],readmessage,sizeof(readmessage));
		printf("IN CHILD : WRITING TO PIPE 1-MESSAGE IS %s\n",readmessage);
		printf("IN CHILD : WRITING TO PIPE 2-MESSAGE IS %s\n",pipe2writemessage,sizeof(pipe2writemessage));
		write(pipefds2[1],pipe2writemessage,sizeof(pipe2writemessage));
	}
	return 0;
}
