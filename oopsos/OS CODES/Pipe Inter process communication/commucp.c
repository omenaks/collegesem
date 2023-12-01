#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main() {
	int dataprocessed;
	int file_pipes[2];
	const char some_data[] = "Hello World";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;
	memset(buffer, '\0', sizeof(buffer));
	if(pipe(file_pipes)==0) {
		fork_result = fork();
		if(fork_result == -1) {
			fprintf(stderr,"Fork Failure");
			exit(EXIT_FAILURE);
		}
		else if(fork_result == 0) {
			sleep(2);
			dataprocessed = read(file_pipes[0], buffer, BUFSIZ);
			printf("Child read %d bytes: %s\n", dataprocessed, buffer);
			exit(EXIT_SUCCESS);
		}
		else {
			dataprocessed = write(file_pipes[1], some_data, strlen(some_data));
			printf("Parent wrote %d bytes: %s\n",dataprocessed, some_data);
		}
	}
	exit(EXIT_SUCCESS);
}

