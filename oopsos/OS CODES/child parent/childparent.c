#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
    char* arr[3];
    arr[0] = strdup("/usr/bin/wc");//arr[1] = strdup("ls");
    arr[1] = strdup("wc"); //arr[1] = strdup("-l");
    arr[2] = NULL;
    execlp (arr[0], arr[0], "f1", NULL);//execlp (arr[0], arr[0], arr[1], NULL);
    printf("This should not be printed");
}

else
{
    int wc = wait(NULL);
    printf ("hello i am the parent of pid %d with wc: %d and my own pid is %d\n",rc, wc,(int)getpid());
}
    
}
