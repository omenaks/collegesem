#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char* argv []) {
printf("hello world my pid is %d\n", (int)getpid());
int rc= fork();



if (rc<0)
{
    fprintf (stderr, "fork failed\n");
    exit(1);
}

else if (rc == 0)
{
    printf ("hello, i am child, my pid is %d\n",(int)getpid());
    sleep(20);
}

else
{
    int wc = wait(NULL);
    printf ("hello i am the parent of pid %d and my own pid is %d\n",rc,(int)getpid());
    sleep(60);
}
    
}
