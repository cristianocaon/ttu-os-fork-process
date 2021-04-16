#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void recursive_child(int);

int main(int argc, char *argv[]) {
	printf("\n+-----------------------------------+\n");

	// Receiving input from command line
	int num = strtol(argv[1], NULL, 10);
	printf("\nCalling recursive_child() function");
	printf("\nNumber entered: %d\n", num);
	recursive_child(num);
	return 0;
}

void recursive_child(int num) {
	// Base case. If reaches this point, starts returning and exiting child processes
	if (num == 0) {
		printf("\n\nReached the end. Exiting...\n");
		exit(0);
	// Continues creating child processes
	} else {
		long out = fork();
		// Child process case
		if (out == 0) {
			printf("Creating child!\n");
			// Proceeds with recusrion until it reaches base case
			// Creates the hierarchy of child processes
			recursive_child(num - 1);
		} else if (out > 0){
			// Parent process waits for child to finish
			waitpid(-1, NULL, 0);
		} else {
			printf("Child creation failed.");
		}
	}
}

