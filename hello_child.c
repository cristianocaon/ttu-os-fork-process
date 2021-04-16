#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_child(int);

int main(int argc, char *argv[]) {
	printf("\n+-----------------------------------+\n");

	// Receiving the input from command line
	int num = strtol(argv[1], NULL, 10);
	printf("\nCalling create_child() function");
	create_child(num);
	return 0;
}

void create_child(int num) {
	printf("\nNumber entered: %d\n", num);

	// Amount of child processes to create within the for-loop
	for (int i = 0; i < num; i++) {
		// Creating the processes
		long out = fork();
		if(out == 0) {
			// Inside child process
			printf("Hello from Child!!  PID=%d\n", getpid());
			exit(0);
		} else if(out < 0) { 
			// Error handling for unsuccessful child process creation
			printf("\n\nCreation was unsuccessful.\n\n");
		} else {	
			// Inside parent process, waiting for child process to finish
			waitpid(-1, NULL, 0);
		}
	}
}

